#include <stdio.h>
#include <assert.h>

int yy_input(char *buf, int max_size) {
    // Looking at the implementation, we are guaranteed at least 512 bytes
    assert(max_size >= 3);

    int c = getchar();
    switch (c) {
    case EOF:
        return 0;
    case '}':
        buf[0] = '}';
        c = getchar();
        if (c == '\n') {
            buf[1] = ';';
            buf[2] = '\n';
            return 3;
        } else {
            buf[1] = c;
            return 2;
        }
    default:
        buf[0] = c;
        return 1;
    }
}

#define YY_INPUT(buf, result, max_size) \
{                                       \
    result = yy_input(buf, max_size);   \
}

int yyparse();

int main() {
    if (yyparse() == 0) {
        fprintf(stderr, "Failed!\n");
        return 1;
    }

    return 0;
}
