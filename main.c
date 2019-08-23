
#include <stdio.h>
#include <stdlib.h>

void main()
{

    int c;
    FILE *file;
    file = fopen("texto.txt", "r");

    if(file)
    {
        while( (c = getc(file)) != EOF ){
            putchar(c);
        }

        fclose(file);        
    }


}