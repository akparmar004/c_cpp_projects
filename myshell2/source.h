#ifndef SOURCE_H
#define SOURCE_H

#define EOF             (-1)
#define ERRCHAR         ( 0)

#define INIT_SRC_POS    (-2)

typedef struct source_s
{   
    char *buffer;       /* the input text */
    long bufsize;       /* size of the input text */
    long  curpos;       /* absolute char position in source */
}str;

char next_char(str *src);
void unget_char(str *src);
char peek_char(str *src);
void skip_white_spaces(str *src);

#endif
