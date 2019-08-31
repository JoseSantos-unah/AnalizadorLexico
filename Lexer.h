

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

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
void* scan(FILE* file, struct Queue* q);


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
    CHAR = 262,
    SHORT = 263,
    OPERATOR = 264,
    NONE = 265
    
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
    const char* lexeme;
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

    if( isLetter(c) || isDigit(c) )
    {
        return  1;
    }

}


void Begin_Lexer(const char* fName)
{
    FILE * file = fopen (fName, "r"); /*Lectura de el archivo */
    
    if (file) //Si el archivo Existe...
    {
        void* fullData ;
        int tagData;

        struct Queue* m_Queue = queueConstructor();         

        reserveWord(m_Queue, "int", INT);
        reserveWord(m_Queue, "char", CHAR);
        reserveWord(m_Queue, "short", SHORT);
        reserveWord(m_Queue, "float", FLOAT);

        reserveWord(m_Queue, "+", OPERATOR);
        reserveWord(m_Queue, "-", OPERATOR);
        reserveWord(m_Queue, "*", OPERATOR);
        reserveWord(m_Queue, "/", OPERATOR);
        reserveWord(m_Queue, "++", OPERATOR);
        reserveWord(m_Queue, "--", OPERATOR);
        reserveWord(m_Queue, "+=", OPERATOR);
        reserveWord(m_Queue, "-=", OPERATOR);

        while (tagData != EOF) // Mientras que no sea el fin del archivo
        {

        switch ( tagData = *(int*)( fullData =  (scan(file, m_Queue)) ) )
        {
            case NUM: {
                printf(" Se leyó un Digito con valor %u ", ((Digit*)(fullData))->value );
                //printf("Es un Numero!\n");
                //free(tagData);
                break;
            }

            case ID:{
                printf(" Se leyó una variable con valor %s \n", ((Word*)(fullData))->lexeme );
                //printf("Es un ID!\n");
                ///free(tagData);
                break;
            }

            //ID = 257, 
            //TRUE = 258, 
            //FALSE = 259, 
            //INT = 260, 
            //FLOAT = 261, 
            //END_INSTRUCTION = 262,
            //RESERVED_WORD = 263,
            //OPERATOR = 264,
            //NONE = 265

            case FLOAT: {
                printf("Se encontro la palabra reservada %s!!\n", ((Word*)(fullData))->lexeme);
            }

            case OPERATOR: {
                printf("Se encontro un operador %s!!\n", ((Word*)(fullData))->lexeme );
            }

            case INT : {
                printf("Se encontro palabra reservada %s!!\n", ((Word*)(fullData))->lexeme );
            }

            default: break;
        }

        }
        
        free(m_Queue);
        fclose(file);
        free(fullData);
        free(file);
        
    }else
    {
        printf("El archivo ingresado NO EXISTE.\n");

    }
    
}

void* scan(FILE* file, struct Queue* q)
{
    int peek;

    while ( (peek = getc(file)) != EOF )
    {
        for ( ; ; peek = (char)getc(file) )
        {
            if (peek == ' ' || peek == '\t' || peek == '\n') continue;
            else break;
        }
        
        if (isDigit(peek))
        {
            int value = 0;

            do{
                peek = getc(file);
            } while ( isDigit(peek) );

            if ( isLetter(peek) )
            {
                continue;
            }
            
            Digit* number = (Digit*)malloc(sizeof(Digit));
            number->tag = NUM;
            number->value = value;

            //printf("%i\n", number->tag);
            return number;
        }

        
        if( isLetter(peek) || peek == ';' )
        {
            //Apartando memoria para 100 char's
            char* wordPointer = (char*)malloc(sizeof(char) * 100); 
            const char* access = wordPointer;

            do{
               *wordPointer = peek;
                wordPointer++;
                peek = getc(file);
            }while( isLetterOrDigit(peek) );
            
            struct Node* n = getFromQueue(q, access);
            Word* real = (Word*) malloc( sizeof(Word) );

            real->lexeme = n->name;
            real->tag = n->Tag;

            printf("%s\n", getFromQueue(q, access)->name);
            
            if( n->name != " " )
            {
                return real;
            }

            real->lexeme = access;
            real->tag = ID;
            
            reserveWord(q, access, ID);

            //printf("%s\n", getFromQueue(q, access)->name);

            printf("%s\n", access);
            return real;
        }

        GenericTag* token = (GenericTag*)malloc(sizeof(GenericTag));
        token->tag = NONE;

        peek = ' ';

        return token;
    }


}
