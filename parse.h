// parse.h - interface for parsing strings

// The types of tokens the parser can return.
typedef enum token
{
    NONE = 0,
    NUMBER,
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV
} token;

// opaque parser type
struct parser;
typedef struct parser parser;

// create a new parser for a given string. Return NULL on error.
parser *parser_create(const char *str);

// returns the next token from the string `p` is parsing. If the token
// is a number, store the parsed number in `out`. Returns NONE iff the
// parser has reached the end of the string. Does not support negative
// numbers.
token parser_parse(parser *p, int *out);

// frees `p`, but not the string it contains.
void parser_free(parser *p);
