
#include "Lexer.h"
#include <string.h>

void main(int* argv, char** args)
{
    const char* fName = args[1];

    printf("%i\n", argv);
    printf("%s\n", fName);

    if (argv > 1)
    {
        Begin_Lexer(fName);
    }else
    {
        printf(" No ingreso el nombre del archivo a buscar!!\n Ingrese el nombre.\n ");
    }

    //int i = compareStrings("float", "floor");
//
    //printf("%i\n", i);

}

