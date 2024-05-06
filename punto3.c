#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
    char **nombres;
    char buff[10];
    int cant;

    printf("ingrese la cantidad de nombres: ");
    scanf("%d",&cant);
    nombres = (char**) malloc (sizeof(char*) * cant);

    for(int i=0; i<cant; i++)
    {
        printf("ingrese el nombre %d: ", i+1);
        fflush(stdin);
        gets(buff);
        nombres[i] = (char*) malloc (strlen(buff) + 1 * sizeof(char));
        strcpy(nombres[i], buff);
    }
    printf("\n");
    for(int i=0; i<cant; i++)
    {
        puts(nombres[i]);
    }

    for(int i=0; i<cant; i++)
    {
        free(nombres[i]);
    }
    return 0;
}