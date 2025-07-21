%{
#include <stdio.h>
#include <stdlib.h>

int c = 0, w = 0, s = 0, l = 0;
%}

WORD    [^ \t\n,\.:]+
EOL     [\n]
BLANK   [ ]

%%
{WORD}  { w++; c += yyleng; }
{BLANK} { s++; }
{EOL}   { l++; }
.       { c++; }
%%

int yywrap() {
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror("Error opening file");
        exit(1);
    }

    yylex();
    fclose(yyin);

    printf("No of characters = %d\n", c);
    printf("No of words = %d\n", w);
    printf("No of spaces = %d\n", s);
    printf("No of lines = %d\n", l);

    return 0;
}
