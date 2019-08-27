
#include "Lexer.h"


void main(int* argv, char** args)
{
    const char* fName = args[1];

    printf("%i\n", argv);
    printf("%s\n", fName);


    //printf("%i\n", sizeof(Tag));
    //printf("%i\n", sizeof(Digit));
    //printf("%i\n", sizeof(char*));

    if (argv > 1)
    {
        lexer (fName);
    }else
    {
        printf(" No ingreso el nombre del archivo a buscar!!\n Ingrese el nombre.\n ");
    }
    
    //char* word = (char*)malloc(sizeof(char) * 100);
    //char* access = word;
//
    //
    //for (unsigned int i = 'a'; i <= 'z'; i++)
    //{
    //    *word = i;
    //    ++word;
    //    printf("%i\n", i);
    //}
//
//
    //printf(access);

}

