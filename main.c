
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATA_TYPE 6
#define ARITMETIC_OPERATIONS 4
#define UNARY_OPERATORS 4
#define LOGICAL_OPERATORS 6

const char* data_type[DATA_TYPE] = 
{"int", "float", "double", "void", "char", "long"}; 

const char* aritmetic_operators[ARITMETIC_OPERATIONS] = 
{ "+", "*", "-", "/" };

const char* unary_operators[UNARY_OPERATORS] = 
{ "--", "++", "-", "="};

const char* logical_operator[LOGICAL_OPERATORS] =
{ "<", ">", ">=", "<=", "==", "!=" };


typedef enum
{
    tkn_identifier,
    tkn_integer_literal,
    tkn_string_literal
}Token;

typedef enum
{
    NONE,
    Variable,
    Number,
    String,
    Data_type
}State;


void Lexer(const char* fName);
Token FiniteStateMachine(FILE* file);

void main(int* argv, char** args)
{
    const char* fName = args[1];

    printf("%i\n", argv);
    printf("%s\n", fName);

    if (argv > 1)
    {
        Lexer(fName);
    }else
    {
        printf(" No ingreso el nombre del archivo a buscar!!\n Ingrese el nombre.\n ");
    }
    
}


void Lexer(const char* fName)
{
    FILE * file = fopen (fName, "r"); /*Lectura de el archivo */
    
    if (file) //Si el archivo Existe...
    {
        FiniteStateMachine(file); 

        fclose(file);
    }else
    {
        printf("El archivo ingresado NO EXISTE.\n");
    }
    
}

Token FiniteStateMachine(FILE* file)
{
    int character;

    while ( (character = getc(file)) != EOF)
    {
        State state = NONE;
        
        switch (character)
        {
            case ' ' : break;
            case '\n': return tkn_string_literal;
            case ('a'|'b'|'c'|'d'| 'z') : {state = Variable;} break;
            
            case (';') : break;
            default: break;
        }
    }


}
