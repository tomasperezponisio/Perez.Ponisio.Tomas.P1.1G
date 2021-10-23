#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "dataWarehouse.h"
#include "micro.h"
#include "empresa.h"
#include "tipoServicio.h"
#include "destino.h"
#include "viaje.h"

#define TAM 10
#define TAM_E 4
#define TAM_T 4
#define TAM_D 4
#define TAM_V 10

int main()
{
    char seguir = 's';
    char salir;
    int nextIdMicro = 100;
    int nextIdVIaje = 50000;
    eMicro lista[TAM];
    eViaje viajes[TAM_V];
    eEmpresa empresas[TAM_E] =
    {
        { 1000, "Plusmar" },
        { 1001, "Flecha Bus" },
        { 1002, "Tas" },
        { 1003, "El Rapido" }
    };

    eTipoServicio tipos[TAM_T] =
    {
        { 5000, "Comun" },
        { 5001, "CocheCama" },
        { 5002, "Doble" },
        { 5003, "Vip" }
    };

    eDestino destinos[TAM_D] =
    {
        { 20000, "Calafate", 22250},
        { 20001, "Bariloche", 103000 },
        { 20002, "Iguazu", 84400},
        { 20003, "Mendoza", 95600 }
    };

    if ( !inicializarMicros(lista, TAM) )
    {
        printf("Error al iniciar micros\n");
    }

    hardcodearMicros(lista, TAM, 8, &nextIdMicro);

    do
    {
        switch (menu())
        {
        case 1:
            //printf("Alta micro\n");
            if( !altaMicro(lista, TAM, empresas, TAM_E, tipos, TAM_T, &nextIdMicro) )
            {
                printf("No se pudo realizar el alta\n");
            }
            else
            {
                printf("Alta exitosa\n");
            }
            break;
        case 2:
            if(!modificarMicro(lista, TAM, empresas, TAM_E, tipos, TAM_T))
            {
                printf("No se pudo modificar\n");
            }
            else
            {
                printf("Cambios realizados con exito\n");
            }
            break;
        case 3:

            if(!bajaMicro(lista, TAM, empresas, TAM_E, tipos, TAM_T))
            {
                printf("No se pudo realizar la baja\n");
            }
            else
            {
                printf("Baja exitosa\n");
            }
            break;
        case 4:
            system("cls");
            if ( !mostrarMicros(lista, TAM, empresas, TAM_E, tipos, TAM_T) )
            {
                printf("No se pudo mostrar los autos\n");
            }
            break;
        case 5:
            system("cls");
            if ( !mostrarEmpresas(empresas, TAM_E ))
            {
                printf("No se pudo mostrar las empresas\n");
            }
            break;
        case 6:
            system("cls");
            if ( !mostrarTipoServicio(tipos, TAM_T ))
            {
                printf("No se pudo mostrar los tipos de servicio\n");
            }

            break;
        case 7:
            system("cls");
            if ( !mostrarDestinos(destinos, TAM_D) )
            {
                printf("No se pudo mostrar los destinos\n");
            }
            break;
        case 8:
             if( !altaViaje(viajes, TAM_V, lista, TAM, empresas, TAM_E, tipos, TAM_T, destinos, TAM_D, &nextIdVIaje )  )
            {
                printf("No se pudo realizar el alta de viaje\n");
            }
            else
            {
                printf("Alta trabajo exitosa\n");
            }
            break;
        case 9:
             system("cls");
            if( !mostrarViajes(viajes, TAM_V, lista, TAM, empresas, TAM_E, destinos, TAM_D ) )
            {
                printf("No se pudo mostrar los viajes\n");
            }
            else
            {
                printf("Mostrar viajes exitosa\n");
            }
            break;
        case 20:
            printf("Esta seguro que quiere salir? (S/N)\n");
            fflush(stdin);
            scanf("%c", &salir);
            salir = toupper(salir);
            if (salir == 'S')
            {
                seguir = 'n';
            }
            else
            {
                break;
            }
            break;
        default:
            printf("Opcion invalida\n");
        }
        system("pause");

    }
    while(seguir == 's');


    return 0;
}
