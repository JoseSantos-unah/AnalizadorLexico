

#include <stdio.h>
#include <stdlib.h>


#define DATA_TYPE 6
#define ARITMETIC_OPERATIONS 4
#define UNARY_OPERATORS 4
#define LOGICAL_OPERATORS 6

void Begin_Lexer(const char* fName);
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
    END_INSTRUCTION = 262
    
}Tag; // Tambien se pueden llamar "states"


typedef struct 
{
    int value;
    Tag tag;
}Digit;

typedef struct 
{
    const char* lexeme;
    Tag tag;
}Word;

