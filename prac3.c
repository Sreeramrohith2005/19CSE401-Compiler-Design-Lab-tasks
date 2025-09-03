#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char input[50], stack[50];

// parse table (productions)
const char table[5][6][4] = {
    {"tb",  "",   "",   "tb",  "",   ""},     // E
    {"",    "+tb","",   "",    "n",  "n"},    // B
    {"fc",  "",   "",   "fc",  "",   ""},     // T
    {"",    "n",  "*fc","n",   "n",  "n"},    // C
    {"i",   "",   "",   "(e)", "",   ""}      // F
};

const int len[5][6] = {
    {2,0,0,2,0,0},
    {0,3,0,0,1,1},
    {2,0,0,2,0,0},
    {0,1,3,1,1,1},
    {1,0,0,3,0,0}
};

// map non-terminals on stack to row
int rowIndex(char nt) {
    switch (nt) {
        case 'e': return 0; // E
        case 'b': return 1; // B
        case 't': return 2; // T
        case 'c': return 3; // C
        case 'f': return 4; // F
    }
    return -1;
}

// map next input symbol to column
int colIndex(char sym) {
    switch (sym) {
        case 'i': return 0;
        case '+': return 1;
        case '*': return 2;
        case '(': return 3;
        case ')': return 4;
        case '$': return 5;
    }
    return -1;
}

int main(void) {
    printf("Enter the input string: ");
    scanf("%s", input);
    strcat(input, "$");

    // initialize stack
    stack[0] = '$';
    stack[1] = 'e';   // start symbol E
    int top = 1, pos = 0;

    printf("\nStack\tInput\n");
    printf("-----\t-----\n");

    while (stack[top] != '$' && input[pos] != '$') {
        if (stack[top] == input[pos]) {
            top--;      // match terminal
            pos++;
        } else {
            int r = rowIndex(stack[top]);
            int c = colIndex(input[pos]);
            if (r < 0 || c < 0 || table[r][c][0] == '\0') {
                printf("ERROR\n");
                exit(1);
            }
            if (table[r][c][0] == 'n') {
                top--; // epsilon
            } else {
                // pop and push production
                top--;
                for (int k = len[r][c] - 1; k >= 0; k--) {
                    stack[++top] = table[r][c][k];
                }
            }
        }

        // print stack and remaining input
        for (int k = 0; k <= top; k++) printf("%c", stack[k]);
        printf("\t%s\n", input + pos);
    }

    printf("\nSUCCESS\n");
    return 0;
}
