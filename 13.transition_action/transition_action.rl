#include <string.h>
#include <stdio.h>

%%{
    machine foo;

    action start_action {
        printf("\033[31mEntering Action\033[0m\n");
		start = p;
	}

    action leave_action {
		printf("\033[31mLeaving Actions: [%.*s]\033[0m\n", (int)(p-start), start);
	}

    action end_action {
        printf("\033[32mFinishing Action\033[0m\n");
    }

    action all_action {
        printf("\033[34mAll Transition Action\033[0m\n");
    }

    numbers = digit{2,4} $all_action @end_action >start_action %leave_action space;

    main := numbers*;
}%%

%% write data;

int main( int argc, char **argv )
{
    int cs = 0;
    char *start = NULL;

    if ( argc > 1 ) {
        char *p = argv[1];
        char *pe = p + strlen(p) + 1;
        char *eof = pe;

        printf("Input string: [%s]\n", p);
        printf("----start----\n\n");

        %% write init;
        %% write exec;
    }

    printf("\n----end----\n");
    return 0;
}