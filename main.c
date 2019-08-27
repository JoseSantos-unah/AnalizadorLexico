
#include "Lexer.h"
#include <string.h>


void Lexer(const char* fName);
void* FiniteStateMachine(FILE* file);

void main(int* argv, char** args)
{
    const char* fName = args[1];

    printf("%i\n", argv);
    printf("%s\n", fName);

    Word t ;
    t.lexeme = "qiondas pue";
    t.tag = ID;

    Digit d;
    d.tag = NUM;
    d.value = 4;

    printf(t.lexeme);

    //if (argv > 1)
    //{
    //    Lexer(fName);
    //}else
    //{
    //    printf(" No ingreso el nombre del archivo a buscar!!\n Ingrese el nombre.\n ");
    //}

    
}

