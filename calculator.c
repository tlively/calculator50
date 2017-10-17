// calculator.c - Implement a postfix calculator

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "cs50.h"

#include "stack.h"
#include "parse.h"

int main(void)
{
    // make stack
    stack *s = stack_create();
    if (s == NULL)
    {
        printf("Could not allocate stack!\n");
        return 1;
    }

    // make parser
    parser *p = parser_create(get_string("expression: "));
    if (p == NULL)
    {
        printf("Could not allocate parser!\n");
        stack_free(s);
        return 2;
    }

    token tok;
    int num;

    // parse tokens until we get NONE
    while ((tok = parser_parse(p, &num)))
    {
        // push numbers onto the stack
        if (tok == NUMBER)
        {
            stack_push(s, num);
            continue;
        }

        // try popping two numbers off the stack
        int a, b;
        if (!stack_pop(s, &b) || !stack_pop(s, &a))
        {
            printf("Invalid expression!\n");
            parser_free(p);
            stack_free(s);
            return 3;
        }

        // push the correct result onto the stack
        switch(tok)
        {
        case OP_ADD:
            stack_push(s, a + b);
            break;
        case OP_SUB:
            stack_push(s, a - b);
            break;
        case OP_MUL:
            stack_push(s, a * b);
            break;
        case OP_DIV:
            stack_push(s, a / b);
            break;
        default:
            assert(false && "Illegal operand");
        }
    }

    int result;
    stack_pop(s, &result);
    printf("%d\n", result);
    parser_free(p);
    stack_free(s);
}
