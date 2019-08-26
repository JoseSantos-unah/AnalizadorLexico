
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
    Digit,
    String,
    Data_type,
    Expresion
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
    State state = NONE;

    while ( (character = getc(file)) != EOF)
    {
        
        switch (character)
        {
            case (' ') : continue;
            case ('\n'): continue;
            case ('a'|'b'|'c'|'d'|'e'|'f'|'g') : state = Variable; continue;
            case ('1'|'2'|'3'|'4'|'5'|'6'|'7'|'8'|'9'|'0'): state = Digit; continue;
            case (';') : state = Expresion;  break;
            default: break;
        }
    
    }


}