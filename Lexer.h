
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


int isLetter(int c);
int isDigit(int c);
int isLetterOrDigit(int c);
int isOperator(int c);

void Begin_Lexer(const char* fName);
void* scan(FILE* file, struct Queue* q);

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
    }else
    {
        return 0;
    }
    

}

int isOperator(int c)
{
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '=')
    {
        return 1;
    }else
    {
        return 0;
    }
    
}


void Begin_Lexer(const char* fName)
{
    FILE * file = fopen (fName, "r"); /*Lectura de el archivo */
    
    if (file) //Si el archivo Existe...
    {
        void* fullData;
        int tagData;

        struct Queue* m_Queue = queueConstructor();         

        reserveWord(m_Queue, "int",   RESERVED_WORD);
        reserveWord(m_Queue, "char",  RESERVED_WORD);
        reserveWord(m_Queue, "float", RESERVED_WORD);

        reserveWord(m_Queue, "+",  OPERATOR);
        reserveWord(m_Queue, "-",  OPERATOR);
        reserveWord(m_Queue, "*",  OPERATOR);
        reserveWord(m_Queue, "/",  OPERATOR);
        reserveWord(m_Queue, "++", OPERATOR);
        reserveWord(m_Queue, "--", OPERATOR);
        reserveWord(m_Queue, "+=", OPERATOR);
        reserveWord(m_Queue, "-=", OPERATOR);
        reserveWord(m_Queue, "=",  OPERATOR);
        reserveWord(m_Queue, "!=", OPERATOR);

        reserveWord(m_Queue, "true", TRUE);
        reserveWord(m_Queue, "false", FALSE);


        while ( (int*)fullData != EOF ) // Mientras que no sea el fin del archivo
        {

        switch ( tagData = *(int*)(fullData =  scan(file, m_Queue)) )
        {
            case NUM: {
                printf("Se leyó un Digito con valor \"%u\" !! \n", ((Digit*)(fullData))->value );
                break;
            }

            case ID:{
                printf("Se leyó una variable con valor \"%s\" \n", ((Word*)(fullData))->lexeme );
                break;
            }

            case RESERVED_WORD : {
                printf("Se encontro la palabra reservada \"%s\" !!\n", ((Word*)(fullData))->lexeme);
                break;
            }

            case OPERATOR: {
                printf("Se encontro un operador \"%s\" !!\n", ((Word*)(fullData))->lexeme );
                break;
            }

            case TRUE: {
                printf("Se encontro la palabra reservada \"%s\" !!\n", ((Word*)(fullData))->lexeme );
                break;
            }

            case FALSE: {
                printf("Se encontro la palabra reservada \"%s\" !!\n", ((Word*)(fullData))->lexeme );
                break;
            }
            
            default:  break;
        }
            //printf("%u\n", m_Queue->size);
        }

        // printQueue(m_Queue);
        // destroyQueue(m_Queue);
// 
        // fclose(file);
        // free(fullData);

        return;
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
            //TODO: falta arreglar el valot correcto
            int value = 0;

            do{
                peek = getc(file);
            } while ( isDigit(peek) );

            if ( isLetter(peek) )
            {
                // Si comienza leyendo digitos y encuentra un caracter entonces sale
                // de la función usado "continue" y pasa a la lectura con caracteres.
                continue; 
            }
            
            Digit* number = (Digit*)malloc(sizeof(Digit));
            number->tag = NUM;
            number->value = value;

            return number;
        }

        
        if( isLetter(peek) || isOperator(peek))
        {
            //Apartando memoria para 100 char's
            char* access = (char*)malloc(sizeof(char) * 100);
            char* wordPointer = access; 

            do{
               *wordPointer = peek;
                wordPointer++;
                peek = getc(file);
            }while( isLetterOrDigit(peek) );
            
            struct Node* n = getFromQueue(q, access);
            Word* real = (Word*) malloc( sizeof(Word) );

            if( n != null_node_ptr )
            {
                real->lexeme = n->name;
                real->tag = n->Tag;
                printf("\t\"%s\" fue encontrado en el Queue\n", n->name);
                return real;
            }
        
            reserveWord(q, access, ID);

            real->lexeme = access;
            real->tag = ID;

            return real;
        }

        GenericTag* token = (GenericTag*)malloc(sizeof(GenericTag));
        token->tag = NONE;

        peek = ' ';

        return token;
    }

    /// Capturar caso de EOF

    return EOF;
}
