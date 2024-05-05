#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAMA 5


int main()
{
    char *nombres[TAMA];
    char buff[10];

    for(int i=0; i<TAMA; i++)
    {
        printf("ingrese el nombre %d: ", i+1);
        gets(buff);
        nombres[i] = (char*) malloc (strlen(buff) + 1 * sizeof(char));
        strcpy(nombres[i], buff);
    }
    printf("\n");
    for(int i=0; i<TAMA; i++)
    {
        puts(nombres[i]);
    }

    for(int i=0; i<TAMA; i++)
    {
        free(nombres[i]);
    }
    return 0;
}