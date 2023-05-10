#include <string.h>
#include <stdio.h>

// python -c "print(ord('f'),ord('0'),ord('a'),ord('r'),ord('b'))"
// 102 48 97 114 98
%%{
    machine foo;
    main := ( 'foo' | 'bar' ) 0 @{ res = 1; };
}%%

%% write data;

int main( int argc, char **argv )
{
    int cs, res = 0;
    if ( argc > 1 ) {
        char *p = argv[1];
        char *pe = p + strlen(p) + 1;
        %% write init;
        %% write exec;
    }
    printf("result = %i\n", res );
    return 0;
}