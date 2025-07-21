%{
#include <stdio.h>
int vowels = 0;
int cons = 0;
%}
%%
[aeiouAEIOU]     { vowels++; }
[a-zA-Z]         { cons++; }
[^a-zA-Z\n]      { /* ignore non-letter characters */ }
\n               { /* ignore newlines */ }
%%
int yywrap() {
    return 1;
}

int main() {
    printf("Enter the string.. at end press Ctrl+D (Unix) or Ctrl+Z (Windows)\n");
    yylex();
    // Since vowels are a subset of letters, subtract vowels from cons
    printf("No of vowels = %d\n", vowels);
    printf("No of consonants = %d\n", cons - vowels);
    return 0;
}

