#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
typedef struct
{
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} Producto;

typedef struct
{
    int ClienteID; // Numerado en el ciclo iterativo
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    char *NombreCliente; // Ingresado por usuario
    Producto *Productos; //El tamaño de este arreglo depende de la variable
    // “CantidadProductosAPedir”
}Cliente;

float precioTotalProd(Producto producto);
void liberarCliente(Cliente *cliente, int cant);

int main()
{
    int cantClientes;
    Cliente * clientes;
    char buff[10];
    int numProd;
    int IDProd = 0;
    printf("ingrese la cantida de clientes: ");
    scanf("%d", &cantClientes);
    clientes = (Cliente*) malloc (sizeof(Cliente) * cantClientes);

    for(int i=0; i<cantClientes; i++)
    {
        clientes[i].ClienteID = i;
        clientes[i].CantidadProductosAPedir = rand()%5 + 1;
        clientes[i].Productos = (Producto*) malloc (sizeof(Producto) * clientes[i].CantidadProductosAPedir);
        printf("ingrese el nombre del cliente %d: ", i+1);
        fflush(stdin);
        gets(buff);
        clientes[i].NombreCliente = (char*) malloc (sizeof(char) * strlen(buff) + 1);
        strcpy(clientes[i].NombreCliente, buff);
        printf("el usuario va a pedir %d productos\n", clientes[i].CantidadProductosAPedir);
        for(int j=0; j<clientes[i].CantidadProductosAPedir; j++)
        {
            numProd = rand()%5;
            (clientes[i].Productos[j]).ProductoID = IDProd;
            (clientes[i].Productos[j]).Cantidad = rand()%10 + 1;
            (clientes[i].Productos[j]).TipoProducto = TiposProductos[numProd];
            (clientes[i].Productos[j]).PrecioUnitario = (float)(rand()%9001 + 1000) / 100;
            IDProd++;
        }
    }

    for (int i=0; i<cantClientes; i++)
    {
        float totalPrecio = 0;
        printf("cliente %d:\n", i + 1);
        printf("\tID cliente: %d\n", clientes[i].ClienteID);
        printf("\tnombre cliente: %s\n", clientes[i].NombreCliente);
        printf("\tcantidad de productos: %d\n", clientes[i].CantidadProductosAPedir);
        printf("\tproductos:\n");
        for(int j=0; j<clientes[i].CantidadProductosAPedir; j++)
        {
            printf("\n\t\tID producto: %d\n", (clientes[i].Productos[j]).ProductoID);
            printf("\t\ttipo de producto: %s\n", (clientes[i].Productos[j]).TipoProducto);
            printf("\t\tcantidad de tal: %d\n", (clientes[i].Productos[j]).Cantidad);
            printf("\t\tprecio unitario: %f\n", (clientes[i].Productos[j]).PrecioUnitario);
            printf("\t\tprecio total: %.2f\n", precioTotalProd(clientes[i].Productos[j]));
            totalPrecio = totalPrecio + precioTotalProd(clientes[i].Productos[j]);
        }
        printf("Precio Total a pagar: %.2f\n", totalPrecio);
    }

    liberarCliente(clientes, cantClientes);
    return 0;
}

float precioTotalProd(Producto producto)
{
    return (producto.Cantidad * producto.PrecioUnitario);
}

void liberarCliente(Cliente *cliente, int cant)
{
    for(int i=0; i<cant; i++)
    {
        free(cliente[i].Productos);
    }
    free(cliente);
}
