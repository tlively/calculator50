// calculator.c - Implement a postfix calculator

#include <stdlib.h>
#include <stdio.h>

#include "stack.h"
#include "parse.h"

int main(void)
{
    stack *s = stack_create();
    if (s == NULL)
    {
        printf("Could not allocate stack!\n");
        return 1;
    }

    // TODO: implement postfix calculator


    // clean up
    stack_free(s);
}
