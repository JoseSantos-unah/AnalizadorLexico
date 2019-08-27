
#include "Lexer.h"

const char* data_type[DATA_TYPE] = 
{"int", "float", "double", "void", "char", "long"}; 

const char* aritmetic_operators[ARITMETIC_OPERATIONS] = 
{ "+", "*", "-", "/" };

const char* unary_operators[UNARY_OPERATORS] = 
{ "--", "++", "-", "="};

const char* logical_operator[LOGICAL_OPERATORS] =
{ "<", ">", ">=", "<=", "==", "!=" };



void Begin_Lexer(const char* fName)
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

void* scan(FILE* file)
{
    int peek;

    while ( (peek = getc(file)) != EOF)
    {
        //if( (character >= 'a' && character <= 'z') && state == NONE  )
        //{
        //}
//
        //if( (character >= '0' && character <= '9') && state == NONE  )
        //{
        //}
//
        //if( character == ' ' && state == Data_type)
        //{
        //}
//
        //if( character == ' ' && state == Digit)
        //{
        //}


    }


}
