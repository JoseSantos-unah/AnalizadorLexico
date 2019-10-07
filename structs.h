
#pragma once

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
    OPERATOR = 260,
    RESERVED_WORD = 261,
    NONE = 262
    
}Tag; // Tambien se pueden llamar "states"


/*
    Estos son los diferentes tipos de Tokens que son regresados por el Lexer
    Como en "C" no hay POO entonces deben ser estructuras por separado.
*/

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

