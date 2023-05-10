#include <stdio.h>
#include <string.h>

%%{
machine foo;
write data;
}%%

int main(int argc, char *argv[]) {
    int cs;
    if(argc > 1){
        char *p = argv[1];
        char *pe = p + strlen(p);

        %%{
            main := [0-9]+ ('.' [0-9]+)?;
            write init;
            write exec;
        }%%
    }

    printf("result=%i\n", cs>=foo_first_final);
    return 0;
}