#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "micro.h"
#include "bibliotecaPersonal.h"


int menu()
{
    int opcion = 0;
    system("cls");
    printf("     *** Servicio de viaje de omnibus ***\n");
    printf("  1- Alta Micro\n");
    printf("  2- Modificar Micro\n");
    printf("  3- Baja Micro\n");
    printf("  4- Listar Micros\n");
    printf("  5- Listar Empresas\n");
    printf("  6- Listar Tipos\n");
    printf("  7- Listar Destinos\n");
    printf("  8- Alta Viaje\n");
    printf("  9- Listar Viajes\n");
    printf("  20- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    //printf("\n");
    return opcion;
}


int inicializarMicros(eMicro lista[], int tam)
{
    int todoOk = 0;
    if (lista != NULL && tam > 0)
    {
        todoOk = 1;
        for (int i = 0; i < tam; i++)
        {
            lista[i].isEmpty = 1;
        }
    }
    return todoOk;
}

int buscarLibre(eMicro lista[], int tam)
{
    int indice = -1;
    for (int i = 0; i < tam; i++)
    {
        if (lista[i].isEmpty)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int altaMicro( eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipoServicio tipoServicios[], int tamT, int* pId  )
{
    int todoOk = 0;
    int indice;
    eMicro auxMicro;
    if (lista != NULL && tam > 0 && empresas != NULL && tamE > 0 && tipoServicios != NULL && tamT > 0 && pId != NULL)
    {
        system("cls");
        printf("  ***Alta Micro*** \n\n");
        indice = buscarLibre(lista, tam);
        if (indice == -1)
        {
            printf("No hay lugar\n");
        }
        else
        {
            auxMicro.id = *pId;
            (*pId)++;

            mostrarEmpresas(empresas, tamE);

            if ( !validarEntero(&auxMicro.idEmpresa, "Ingrese id de Empresa: ", "Error, ingrese un id de empresa valido.\n ", empresas[0].id, empresas[tamE-1].id, 10)  )
            {
                printf("\nError al ingresar id de Empresa, id ingresado por default: %d\n", empresas[0].id);
                auxMicro.idEmpresa = empresas[0].id;

            }

            mostrarTipoServicio(tipoServicios, tamT);
            if ( !validarEntero(&auxMicro.idTipo, "Ingrese id de tipo de coche: ", "Error, ingrese un id de tipo de coche valido.\n ", tipoServicios[0].id, tipoServicios[tamT-1].id, 10)  )
            {
                printf("\nError al ingresar id de tipo de coche, id ingresado por default: %d\n", tipoServicios[0].id);
                auxMicro.idTipo = tipoServicios[0].id;
            }

           if ( !validarEntero(&auxMicro.capacidad, "Ingrese la cantidad de pasajeros ( 1 - 50 ) : ", "Error, ingrese una cantidad valida ( 1 - 50 ).\n ", 1, 50, 10)  )
            {
                printf("\nError al ingresar la cantidad de pasajeros, cantidad ingresada por default: %d\n", 1);
                auxMicro.capacidad = 1;
            }

            auxMicro.isEmpty = 0;

            lista[indice] = auxMicro;

            todoOk = 1;
        }
    }
    return todoOk;
}

void mostrarMicro( eMicro unMicro, eEmpresa empresas[], int tamE, eTipoServicio tipoServicios[], int tamT )
{
    char descEmpresa[20];
    char descTipoServicio[20];

    if ( ( cargarDescripcionEmpresa( empresas, tamE, unMicro.idEmpresa, descEmpresa ) == 1 ) &&
            ( cargarDescripcionTipoServicio( tipoServicios, tamT, unMicro.idTipo, descTipoServicio ) == 1 )   )
    {
        printf(" %d   %-10s           %-10s                 %d \n",
               unMicro.id,
               descEmpresa,
               descTipoServicio,
               unMicro.capacidad );
    }

}

int mostrarMicros( eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipoServicio tipoServicios[], int tamT )
{
    int todoOk = 0;
    int flag = 1;
    if ( lista != NULL && tam > 0 && empresas != NULL && tamE > 0 && tipoServicios != NULL && tamT > 0 )
    {
        system("cls");
        printf("                     ***Lista de Micros  ***\n");
        printf("-----------------------------------------------------------------------------------\n");
        printf(" ID    Empresa             Tipo de Servicio      Cantidad de pasajeros     \n");
        printf("-----------------------------------------------------------------------------------\n");
        for (int i = 0; i < tam; i++)
        {
            if (!lista[i].isEmpty)
            {
                ordenarMicros(lista, tam);

                mostrarMicro( lista[i], empresas, tamE, tipoServicios, tamT );
                flag = 0;
            }
        }
        if (flag)
        {
            printf("No hay micros para mostrar.\n");

        }
        todoOk = 1;
    }
    return todoOk;
}


int ordenarMicros(eMicro lista[], int tam)
{
    int todoOk = 0;
    eMicro auxMicro;

    if (lista != NULL && tam >0)
    {
        for (int i = 0; i < tam -1; i++)
        {
            for (int j = i+1; j < tam; j++)
                {
                    // ordeno por empresa y por capacidad
                    if( lista[i].idEmpresa < lista[j].idEmpresa ||
                            (lista[i].idEmpresa == lista[j].idEmpresa && lista[i].capacidad > lista[j].capacidad) )
                    {
                        auxMicro = lista[i];
                        lista[i] = lista[j];
                        lista[j] = auxMicro;
                    }
                }
        }
    }

    return todoOk;
}

int bajaMicro( eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipoServicio tipoServicios[], int tamT )
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    if ( lista != NULL && tam > 0 && empresas != NULL && tamE > 0 && tipoServicios != NULL && tamT > 0 )
    {
        system("cls");
        printf("   *** Baja Micro *** \n\n");
        mostrarMicros(lista, tam, empresas, tamE, tipoServicios, tamT);
        printf("------------------------------------------------------------\n");
        printf("Ingrese id: ");
        scanf("%d", &id);

        indice = buscarMicroId(lista, tam, id);

        if (indice == -1)
        {
            printf("El id: %d no esta registrado en el sistema\n", id);
        }
        else
        {
            mostrarMicro(lista[indice], empresas, tamE, tipoServicios, tamT );
            printf("Confirma baja? (S/N): ");
            fflush(stdin);
            scanf("%c", &confirma);
            if (confirma == 's')
            {
                lista[indice].isEmpty = 1;
                todoOk = 1;
            }
            else
            {
                printf("Baja cancelada por el usuario.\n");
            }
        }
    }
    return todoOk;
}

int buscarMicroId( eMicro lista[], int tam, int Id )
{
    int indice = -1;
    for (int i = 0; i < tam; i++)
    {
        if (lista[i].id == Id && lista[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


int modificarMicro( eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipoServicio tipoServicios[], int tamT )
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    char seguir = 's';
    char salir;
    eMicro auxMicro;

    if (lista != NULL && tam > 0 && empresas != NULL && tamE > 0 && tipoServicios != NULL && tamT > 0)
    {
        system("cls");
        printf("   *** Modificar Micro *** \n\n");
        mostrarMicros(lista, tam, empresas, tamE, tipoServicios, tamT);
        printf("------------------------------------------------------------\n");
        printf("Ingrese id: ");
        scanf("%d", &id);

        indice = buscarMicroId(lista, tam, id);

        if (indice == -1)
        {
            printf("El id: %d no esta registrado en el sistema\n", id);
        }
        else
        {
            do
            {
                switch ( menuModificar(lista, tam, indice, empresas, tamE, tipoServicios, tamT) )
                {
                case 1:
                    mostrarEmpresas(empresas, tamE);
                    printf("Modificar id empresa: ");
                    scanf("%d", &auxMicro.idEmpresa);
                    printf("Confirma cambio de id empresa? (S/N)\n");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                    if (confirma == 'S')
                    {
                        lista[indice].idEmpresa = auxMicro.idEmpresa;
                    }
                    else
                    {
                        printf("Edición cancelada\n");
                    }
                    break;
                case 2:
                    mostrarTipoServicio(tipoServicios, tamT);
                    printf("Modificar id de tipo de servicio: ");
                    scanf("%d", &auxMicro.idTipo);
                    printf("Confirma cambio de id de tipo de servicio? (S/N)\n");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                    if (confirma == 'S')
                    {
                        lista[indice].idTipo = auxMicro.idTipo;
                    }
                    else
                    {
                        printf("Edición cancelada\n");
                    }
                    break;
                case 10:
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

            todoOk = 1;
        }
    }
    return todoOk;
}

int menuModificar( eMicro lista[], int tam, int indice, eEmpresa empresas[], int tamE, eTipoServicio tipoServicios[], int tamT )
{
    int opcion = 0;
    system("cls");
    printf("------------------------------------------------------------\n");
    mostrarMicro(lista[indice], empresas, tamE, tipoServicios, tamT );
    printf("------------------------------------------------------------\n");
    printf("1- Editar Empresa\n");
    printf("2- Editar Tipo de Servicio\n");
    printf("10- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    //system("pause");
    //printf("\n");
    return opcion;
}

int cargarEmpresaMicro( eMicro lista[], int tam, eEmpresa empresas[], int tamE, int idMicro, char empresa[] )
{
    int todoOk = 0;
    int flag = 1;
    char descripcion[20];
    if (lista != NULL && tam > 0 && empresas != NULL && tamE > 0 && empresa != NULL)
    {
        todoOk = 1;
        for (int i = 0; i < tam; i++)
        {
            if (lista[i].id == idMicro)
            {
                cargarDescripcionEmpresa(empresas, tamE, lista[i].idEmpresa, descripcion);
                strcpy(empresa, descripcion);
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            todoOk = -1; // no habia localidad con el id que le pasaron
        }
    }
    return todoOk;
}
