
#include <stdio.h>
#include <stdlib.h>

const char* data_type[] = 
{"int", "float", "double", "void", "char", "long"}; 

const char* aritmetic_operators[] = 
{ "+", "*", "-", "/" };

const char* unary_operators[] = 
{ "--", "++", "-"};

const char* logical_operator[] =
{ "<", ">", ">=", "<=", "==", "!=" };

char assign = '=';

typedef enum
{
    tkn_identifier,
    tkn_integer_literal,
    tkn_string_literal
}Tokens;

typedef enum
{
    Variable,
    Number,
    String,
    Reserved
}States;


Tokens getToken(const char letter);

void main(int* argv, char** args)
{
    ++args;

    char * buffer = 0;
    long length;
    FILE * file = fopen (args[0], "r");

    if (file)
    {
        fseek (file, 0, SEEK_END);
        length = ftell (file);
        fseek (file, 0, SEEK_SET);

        buffer = malloc (length);

        if (buffer)
        {
            fread (buffer, 1, length, file);
        }

        fclose (file);
    }

    if (buffer)
    {
        printf("%s\n", buffer);
    }
}


Tokens getToken(const char letter)
{

    States state;

    switch (letter)
    {
        case '\n' | ' ' : ;

        case 'a'|'b'|'c': state = Variable;

        case '1'|'2'|'3': state = Number; 

        case ' ' : break;

        default:
            break;
   }



}