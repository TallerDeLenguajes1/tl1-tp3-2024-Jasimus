#include <stdio.h>
#include <stdlib.h>
#define MESES 12
#define ANIO 5


void cargarMatriz(int matriz[][MESES]);
void mostrarMatriz(int matriz[][MESES]);
void promedio(int matriz[][MESES]);
void maxMin(int matriz[][MESES]);

int main()
{
    int prodA[ANIO][MESES];
    cargarMatriz(prodA);
    mostrarMatriz(prodA);
    printf("\n");
    promedio(prodA);
    maxMin(prodA);
    return 0;
}

void cargarMatriz(int matriz[][MESES])
{
    for(int i=0; i<ANIO; i++)
    {
        for(int j=0; j<MESES; j++)
        {
            matriz[i][j] = rand()%40001 + 10000;
        }
    }
}

void mostrarMatriz(int matriz[][MESES])
{
    for(int i=0; i<ANIO; i++)
    {
        for(int j=0; j<MESES; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void promedio(int matriz[][MESES])
{
    int sum = 0;
    for(int i=0; i<ANIO; i++)
    {
        for(int j=0; j<MESES; j++)
        {
            sum = sum + matriz[i][j];
        }
        printf("promedio de anio %d: %.3f\n", i+1, (float)sum/MESES);
        sum = 0;
    }
}

void maxMin(int matriz[][MESES])
{
    int max = matriz[0][0];
    int min = matriz[0][1];
    int aux;
    int indMax[2];
    int indMin[2];

    for(int i=0; i<ANIO; i++)
    {
        for(int j=0; j<MESES; j++)
        {
            if(max < matriz[i][j])
            {
                max = matriz[i][j];
                indMax[0] = i;
                indMax[1] = j;
            }
            if(min > matriz[i][j])
            {
                min = matriz[i][j];
                indMin[0] = i;
                indMin[1] = j;
            }
        }
    }
    printf("mayor produccion:\n\tanio: %d\n\tmes: %d\n\n", indMax[0]+1, indMax[1]+1);
    printf("menor produccion:\n\tanio: %d\n\tmes: %d\n", indMin[0]+1, indMin[1]+1);
}