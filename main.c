
#include <stdio.h>
#include <stdlib.h>


void main(int* argv, char** args)
{
    ++args;

    int c;
    FILE *file;
    file = fopen(args[0], "r");

    if(file)
    {
        while( (c = getc(file)) != EOF ){
            putchar(c);
        }

        fclose(file);        
    }

}
