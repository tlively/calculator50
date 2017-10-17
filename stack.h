// stack.h - public interface to a stack data structure

#include <stdbool.h>

// The type of items in the stack
typedef int item;

// Declare a stack type
struct stack;
typedef struct stack stack;

// Create and return a new stack, or NULL on error
stack *stack_create();

// Push the item `it` onto the stack `s`.
// Returns `true` on success, otherwise `false`.
bool stack_push(stack *s, item it);

// Pop an item from the stack `s` and store it at `out`.
// Return `true` on success or `false` if there are no items.
bool stack_pop(stack *s, item *out);

// Free stack-owned resources. The stack must be empty.
void stack_free(stack *s);
