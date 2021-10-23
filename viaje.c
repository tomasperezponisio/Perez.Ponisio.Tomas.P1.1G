#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "viaje.h"

int inicializarViajes( eViaje viajes[], int tamV )
{
    int todoOk = 0;
    if (viajes != NULL && tamV > 0)
    {
        todoOk = 1;
        for (int i = 0; i < tamV; i++)
        {
            viajes[i].isEmpty = 1;
        }
    }
    return todoOk;
}

int buscarLibreViaje( eViaje viajes[], int tamV )
{
    int indice = -1;
    for (int i = 0; i < tamV; i++)
    {
        if (viajes[i].isEmpty)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int altaViaje( eViaje viajes[], int tamV, eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipoServicio tipoServicios[], int tamT, eDestino destinos[], int tamD, int* pIdViaje )
{
    int todoOk = 0;
    int indice;
    eViaje auxViaje;

    if (viajes != NULL && tamV > 0 && lista != NULL && tam > 0 && empresas != NULL && tamE > 0 && tipoServicios != NULL && tamT > 0 && destinos != NULL && tamD > 0  && pIdViaje != NULL )
    {
        system("cls");
        printf("  ***Alta Viaje*** \n\n");
        indice = buscarLibreViaje(viajes, tamV);
        if (indice == -1)
        {
            printf("No hay lugar\n");
        }
        else
        {
            auxViaje.id = *pIdViaje;
            (*pIdViaje)++;

            mostrarMicros(lista, tam, empresas, tamE, tipoServicios, tamT);
            printf("Ingrese id de micro: ");
            scanf("%d", &auxViaje.idMicro);
            while ( buscarMicroId(lista, tam, auxViaje.idMicro) == -1  )
            {
                printf("Error, ingrese id de micro  valido: ");
                scanf("%d", &auxViaje.idMicro);
            }

            mostrarDestinos(destinos, tamD);
            printf("Ingrese id de destino: ");
            scanf("%d", &auxViaje.idDestino);
            while ( !validarIdDestino(auxViaje.idDestino, destinos, tamD)    )
            {
                printf("Error, ingrese id de destino  valido: ");
                scanf("%d", &auxViaje.idDestino);
            }

            printf("Ingrese fecha: ");
            scanf("%d/%d/%d", &auxViaje.fecha.dia, &auxViaje.fecha.mes, &auxViaje.fecha.anio);

            auxViaje.isEmpty = 0;

            viajes[indice] = auxViaje;

            todoOk = 1;
        }
    }
    return todoOk;
}

void mostrarViaje( eViaje unViaje, eMicro lista[], int tam, eEmpresa empresas[], int tamE, eDestino destinos[], int tamD )
{
    char descEmpresa[20];
    char descDestino[20];

    if ( cargarEmpresaMicro(lista, tam, empresas, tamE, unViaje.idMicro, descEmpresa) == 1 &&
            cargarDescripcionDestino(destinos, tamD, unViaje.idDestino, descDestino) == 1 )
    {
        printf(" %d     %-10s        %-10s       %2d/%2d/%4d\n",
               unViaje.id,
               descEmpresa,
               descDestino,
               unViaje.fecha.dia,
               unViaje.fecha.mes,
               unViaje.fecha.anio );
    }

}

int mostrarViajes( eViaje viajes[], int tamV, eMicro lista[], int tam, eEmpresa empresas[], int tamE, eDestino destinos[], int tamD )
{
    int todoOk = 0;
    int flag = 1;
    if ( viajes != NULL && tamV > 0 && lista != NULL && tam > 0 && empresas != NULL && tamE > 0 && destinos != NULL && tamD > 0 )
    {
        //system("cls");
        printf("                     ***Lista de Viajes  ***\n");
        printf("----------------------------------------------------------------------\n");
        printf(" ID        Empresa Micro     Destino          Fecha\n");
        printf("----------------------------------------------------------------------\n");
        for (int i = 0; i < tam; i++)
        {
            if ( !viajes[i].isEmpty )
            {
                mostrarViaje( viajes[i], lista, tam, empresas, tamE, destinos, tamD);
                flag = 0;
            }
        }
        if (flag)
        {
            printf("No hay viajes para mostrar.\n");

        }
        todoOk = 1;
    }
    return todoOk;
}
