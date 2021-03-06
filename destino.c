#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "destino.h"

int mostrarDestinos( eDestino destinos[], int tamD )
{
    int todoOk = 0;
    if (destinos != NULL && tamD > 0 )
    {
        printf("      *** Destinos  *** \n\n");
        printf("  Id          Descripcion         Precio\n");
        for (int i = 0; i < tamD; i++)
        {
            printf("  %d       %-10s          $%d\n", destinos[i].id, destinos[i].descripcion, destinos[i].precio);
        }
        //printf("\n");
        todoOk = 1;
    }

    return todoOk;
}


int validarIdDestino( int id, eDestino destinos[], int tamD )
{
    int esValido = 0;
    if (destinos != NULL && tamD > 0)
    {
        for (int i = 0; i < tamD; i++)
        {
            if (id == destinos[i].id)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}

int cargarDescripcionDestino( eDestino destinos[], int tamD, int idDestino, char descripcion[] )
{
    int todoOk = 0;
    int flag = 1;
    if (destinos != NULL && tamD > 0 && descripcion != NULL)
    {
        todoOk = 1;
        for (int i = 0; i < tamD; i++)
        {
            if (destinos[i].id == idDestino)
            {
                strcpy(descripcion, destinos[i].descripcion);
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            todoOk = -1; // no habia destino con el id que le pasaron
        }
    }
    return todoOk;
}

int cargarPrecioDestino( eDestino destinos[], int tamD, int idDestino, int* precio )
{
    int todoOk = 0;
    int flag = 1;

    if (destinos != NULL && tamD > 0 && precio != NULL)
    {
        todoOk = 1;
        for (int i = 0; i < tamD; i++)
        {
            if (destinos[i].id == idDestino)
            {
                *precio = destinos[i].precio;
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            todoOk = -1; // no habia precio con el id que le pasaron
        }
    }
    return todoOk;
}



