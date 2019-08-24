
#include <stdio.h>
#include <stdlib.h>

const char aritmetic_operators[] = 
{ "+", "*", "-", "/" };

const char unary_operators[] = 
{ "--", "++", "-"};

const char logical_operator[] =
{ "<", ">", ">=", "<=", "==", "!=" };

char assign = '=';

typedef enum
{
    tkn_identifier,
    tkn_integer_literal,
    tkn_string_literal
}Tokens;



char* getToken(const char letter);

void main(int* argv, char** args)
{
    ++args;

    int c;
    FILE *file;
    file = fopen(args[0], "r");

    if(file)
    {
        while( (c = getc(file)) != EOF ){
            putchar(c);
        }

        fclose(file);        
    }


}


char* getToken(const char letter)
{
   
}