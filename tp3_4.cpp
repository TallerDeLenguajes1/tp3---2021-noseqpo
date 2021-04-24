#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};
struct Producto
{
    int ProductoID;       //Numerado en ciclo iterativo
    int Cantidad;         // entre 1 y 10
    char *TipoProducto;   // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
};
struct Cliente
{
    int ClienteID;               // Numerado en el ciclo iterativo
    char *NombreCliente;         // Ingresado por usuario
    int CantidadProductosAPedir; // (alteatorio entre 1 y 5)
    struct Producto *Productos;  // El tamaño de este arreglo depende de la variable “CantidadProductosAPedir”
};

void CreacionProductos(struct Producto *lista, int tamanio)
{
    //Esta funcion crea los productos, todo aleatorio
    //struct Producto temp = (struct Producto) malloc(sizeof(struct Producto) * tamanio);
    for (int i = 0; i < tamanio; i++)
    {
        (lista + i)->ProductoID = i + 1;

        (lista + i)->Cantidad = (1 + rand() % 10);

        (lista + i)->TipoProducto = TiposProductos[0 + rand() % 6];

        (lista + i)->PrecioUnitario = (float)(10 + rand() % 90);
    }
}
void DatosCliente(struct Cliente *lista, int tamanio)
{
    //Esta funcion pide nombre, crea la cantidad de productos y por ultimo llama al funcion de productos
    for (int i = 0; i < tamanio; i++)
    {

        (lista + i)->ClienteID = i + 1;

        (lista + i)->NombreCliente = (char *)malloc(sizeof(char) * 20);
        printf("Por favor ingrese el nombre del cliente %d:\n", i + 1);
        scanf("%s", (lista + i)->NombreCliente); 
        (lista + i)->CantidadProductosAPedir = (1 + rand() % 5);

        (lista + i)->Productos = (struct Producto *)malloc(sizeof(struct Producto) * ((lista + i)->CantidadProductosAPedir));
        CreacionProductos((lista + i)->Productos, (lista + i)->CantidadProductosAPedir);
    }
}
float ProductoProducto(int cantidad, float precio)
{
    // Devuelve un float multiplicacion de los argumentos, recordar usar "%.2f"
    return cantidad * precio;
}
void MostrarTodo(struct Cliente *clientes, int tamanio)
{   
    printf("\n\n");
    for (int i = 0; i < tamanio; i++)
    {
        printf("Cliente N %d: ", i + 1);
        printf("%s\n\n", (clientes + i)->NombreCliente);
        printf("Productos pedidos:\n");
        struct Producto *temp = (clientes + i)->Productos;
        float suma = 0;
        for (int j = 0; j < (clientes + i)->CantidadProductosAPedir; j++)
        {
            printf("%d. -------------------------- %s \n", j + 1, (temp + j)->TipoProducto);
            printf("Cantidad: ------------------- %d\n", (temp + j)->Cantidad);
            printf("Precio unitario: ------------ %.2f\n", (temp + j)->PrecioUnitario);
            suma = suma + ProductoProducto((temp + j)->Cantidad, (temp + j)->PrecioUnitario);
        }
        printf("\nTotal a pagar:--------------- %.2f\n\n\n", suma);
    }
}

int main()
{
    srand(time(NULL));

    int clts;
    printf("Indique el numero de clientes:\n");
    scanf("%d",&clts);
    struct Cliente *lista = (struct Cliente *)malloc(sizeof(struct Cliente) * clts);
    DatosCliente(lista, clts);
    MostrarTodo(lista, clts);
    // pausar acá para que pueda mostrarse bien
    getchar();
    return 0;
}