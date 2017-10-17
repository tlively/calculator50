#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "parse.h"

struct parser
{
    int idx;
    int len;
    const char *str;
};

parser *parser_create(const char *str)
{
    // allocate parser
    parser *p = malloc(sizeof(parser));
    if (p == NULL)
    {
        return NULL;
    }

    // initialize parser
    p->idx = 0;
    p->len = strlen(str);
    p->str = str;
    return p;
}

token parser_parse(parser *p, int *out)
{
    assert(p != NULL);
    assert(out != NULL);

    // skip whitespace and non-recognized characters
    while (true)
    {
        // don't go off the end
        if (p->idx >= p->len)
        {
            break;
        }

        // is this an operator or number?
        bool is_op = false;
        switch (p->str[p->idx])
        {
            case '+':
            case '-':
            case '/':
            case '*':
                is_op = true;
        }
        if (is_op || isdigit(p->str[p->idx]))
        {
            break;
        }

        // go to next character;
        p->idx++;
    }

    // check for end of string
    if (p->idx >= p->len)
    {
        return NONE;
    }

    // check for op
    switch (p->str[p->idx])
    {
        case '+':
            p->idx++;
            return OP_ADD;
        case '-':
            p->idx++;
            return OP_SUB;
        case '/':
            p->idx++;
            return OP_DIV;
        case '*':
            p->idx++;
            return OP_MUL;
    }

    // start of number
    int start_idx = p->idx;

    // find end
    while (p->idx < p->len && isdigit(p->str[p->idx]))
    {
        p->idx++;
    }
    int num_len = p->idx - start_idx;

    // buffer to hold number
    char buffer[num_len + 1];
    strncpy(buffer, &p->str[start_idx], num_len);
    buffer[num_len] = '\0';

    *out = atoi(buffer);
    return NUMBER;
}

void parser_free(parser *p)
{
    free(p);
}
