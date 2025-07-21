%{
#include <stdio.h>
#include <stdlib.h>

int posint = 0, negint = 0, posfraction = 0, negfraction = 0;
%}

%%
[-][0-9]+          { negint++; }
[+]?[0-9]+         { posint++; }
[+]?[0-9]*\.[0-9]+ { posfraction++; }
[-][0-9]*\.[0-9]+  { negfraction++; }
%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter input (press Ctrl+D to finish):\n");
    yylex();
    printf("No of +ve integers = %d\n", posint);
    printf("No of -ve integers = %d\n", negint);
    printf("No of +ve fractions = %d\n", posfraction);
    printf("No of -ve fractions = %d\n", negfraction);
    return 0;
}
