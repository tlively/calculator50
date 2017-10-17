#include <stdlib.h>
#include <assert.h>

#include "stack.h"

typedef struct node
{
    item data;
    struct node *next;
} node;

struct stack
{
    node *head;
};

stack *stack_create()
{
    stack *s = malloc(sizeof(stack));
    if (s == NULL)
    {
        return s;
    }
    s->head = NULL;
    return s;
}

bool stack_push(stack *s, item it)
{
    assert(s != NULL);

    // allocate new node
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {
        return false;
    }

    // initialize and push node
    new_node->data = it;
    new_node->next = s->head;
    s->head = new_node;
    return true;
}

bool stack_pop(stack *s, item *out)
{
    assert(s != NULL);
    assert(out != NULL);

    // check whether stack is empty
    if (s->head == NULL)
    {
        return false;
    }

    // get first node and its item
    node *old_head = s->head;
    s->head = old_head;
    item it = old_head->data;

    free(old_head);
    return it;
}

// recursively frees a link list
void free_node(node *n)
{
    if (n == NULL)
    {
        return;
    }

    free_node(n->next);
    free(n);
}

void stack_free(stack *s)
{
    assert(s != NULL);
    free_node(s->head);
    free(s);
}
