#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdint.h>

#if 1
#define RED_PRINT(fmt, ...) \
    do { \
        printf("\033[31m");  \
        printf(fmt, ##__VA_ARGS__); \
        printf("\033[0m"); \
    }while(0)

#define GREEN_PRINT(fmt, ...) \
    do { \
        printf("\033[32m");  \
        printf(fmt, ##__VA_ARGS__); \
        printf("\033[0m"); \
    }while(0)

#define BLUE_PRINT(fmt, ...) \
    do { \
        printf("\033[34m");  \
        printf(fmt, ##__VA_ARGS__); \
        printf("\033[0m"); \
    }while(0)

#define PRINT(fmt, ...) \
    do { \
        printf(fmt, ##__VA_ARGS__); \
    }while(0)
#else
#define RED_PRINT(fmt, ...)  
#define GREEN_PRINT(fmt, ...)
#define BLUE_PRINT(fmt, ...)
#define PRINT(fmt, ...)
#endif

// generated using python
// ', '.join(map(str, map(lambda x: (chr(x) in '''%{}[]-+*|!"\/'()`><. \n\t\r#,@~''') and 1 or 0,
// range(256))))
static const char suspicious_table[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

// generated using python
// ', '.join(map(str, map(lambda x: (x in (range(32, 128) + [ord('\t'), ord('\r'), ord('\n')])) and
// 1 or 0, range(256))))
static const char printable_table[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};


%%{
    machine main_fsm;
    alphtype unsigned char;

    action stats_char {
        suspicious_char += suspicious_table[fc];
        printable_char += printable_table[fc];
    }

    action enter_action {
        RED_PRINT("Enter action called\n");
    }

    action finishing_action {
        RED_PRINT("Finishing action called\n");
    }

    action all_transition_action {
        RED_PRINT("All transition action called\n");
    }

    action leaving_action {
        RED_PRINT("Leaving action called\n");
    }

    action count_all {
        count_all++;
    }

    # main := any* > enter_action $ stats_char  @ finishing_action % leaving_action;
    main := any* @ stats_char 
        (
            [a-zA-Z] @ count_all
        )
    ;
}%%

%%write data;

void run_fst(const char *str, const char *str_end) {
    long suspicious_char = 0;
    long printable_char = 0;
    long count_all = 0;

    const char *p = str;
    const char *pe = str_end;
    const char *eof = pe;
    int cs;

    %% write init;
    %% write exec;

    GREEN_PRINT("All ascii char count: %ld\nPrintable char count: %ld\nSuspicous char count: %ld\n", count_all, printable_char, suspicious_char);

    return ;
}

int main(int argc, char *argv[])
{
    char buf[4096];
    long len = 0;

    while (fgets(buf, sizeof(buf), stdin) != 0) {
        len=strlen(buf);
        if ((len < 1) || buf[0] == '#') {
            continue;
        }

        // fgets()  reads  in  at  most one less than size characters from stream and stores them into the buffer pointed to by s.  
        // Reading stops after an EOF or a newline.  
        // If a newline is read, it is stored into the buffer.  A terminating null byte ('\0') is stored after the last character in the buffer.
        // skip newline char
        if(buf[len-1] == '\n'){
            len--;
        }

        BLUE_PRINT("Case: %.*s(%ld) result: \n", (int)(len), buf, len);
        
        run_fst(buf, buf+len);
    }

    return 0;
}
