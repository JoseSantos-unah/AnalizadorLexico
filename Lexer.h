

#include <stdio.h>
#include <stdlib.h>


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

int isLetter(int c);
int isDigit(int c);
int isLetterOrDigit(int c);

void lexer(const char* fName);
void* scan(FILE* file);


typedef enum 
{
    /**
     * Debido a que un char toma valores [0-255] 
     * Se inicia el enum en 256 para evitar algun conflicto.
    */

    NUM = 256, 
    ID = 257, 
    TRUE = 258, 
    FALSE = 259, 
    INT = 260, 
    FLOAT = 261, 
    END_INSTRUCTION = 262,
    NONE = 263  
    
}Tag; // Tambien se pueden llamar "states"

typedef struct
{
    Tag tag;
}GenericTag;


typedef struct 
{
    Tag tag;
    int value;
}Digit;

typedef struct 
{
    Tag tag;
    char* lexeme ;
}Word;


int isLetter(int c)
{
    if( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') )
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
} 

int isDigit(int c)
{
    if( c >= '0' && c <= '9' )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isLetterOrDigit(int c)
{

    if(isLetter(c) || isDigit(c))
    {
        return  1;
    }

}


void lexer(const char* fName)
{
    FILE * file = fopen (fName, "r"); /*Lectura de el archivo */
    
    if (file) //Si el archivo Existe...
    {
        void* data ;
        int tagData; 
        //while (1)
        //{

        switch ( tagData = *((int*) (scan(file))) )
        {
            case NUM: {
                //printf(" Se leyó un Digito con valor %s ", ((Digit*)(data))->value  );
                printf("Es un Numero!\n");
                //free(data);
                break;
            }

            case ID:{
               // printf(" Se leyó una variable con valor %s \n", ((Word*)(data))->lexeme   );
                printf("Es un ID!\n");
                ///free(data);
                break;
            }
            
            default: break;
        }

        //}
        

       fclose(file);
    }else
    {
        printf("El archivo ingresado NO EXISTE.\n");

    }
    
}

void* scan(FILE* file)
{
    int peek;

    while ( (peek = getc(file)) != EOF )
    {
        for ( ; ; peek = (char)getc(file) )
        {
            if (peek == ' ' || peek == '\t') continue;
            else break;
        }
        
        
        if (isDigit(peek))
        {
            int value = 0;

            do{
                peek = getc(file);
            } while ( isDigit(peek) );
            
            Digit* number = (Digit*)malloc(sizeof(Digit));
            number->tag = NUM;
            number->value = value;

            printf("%i", number->tag);
            return number;
        }

        
        if( isLetter(peek) )
        {
            char* word = (char*)malloc(sizeof(char) * 100);
            char* access = word;

            do{
                peek = getc(file);
                *word = peek;
                ++word;
            }while( isLetterOrDigit(peek) );

            Word* real = (Word*)malloc(sizeof(Word));
            real->lexeme = access;
            real->tag = ID;

            printf("%s\n", access);
            return real;
        }

        GenericTag* token = (GenericTag*)malloc(sizeof(GenericTag));
        token->tag = NONE;

        peek = ' ';

        return token;
    }


}
