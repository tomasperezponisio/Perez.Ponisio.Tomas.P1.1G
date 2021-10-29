#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "informes.h"
#include "bibliotecaPersonal.h"


int menuInformes()
{
    int opcion = 0;
    system("cls");
    printf("     *** Informes Micros ***\n");
    printf("  1- Mostrar micros de la empresa seleccionada por el usuario.\n");
    printf("  2- Mostrar micros de un tipo seleccionado\n");
    printf("  3- Informar Promedio de micros de tipo Vip sobre el total de micros de una empresa\n");
    printf("  4- Mostrar un listado de los micros separados por empresa\n");
    printf("  5- Informar la o las empresas que pueden transportar más pasajeros (mayor acumulador de capacidades de sus micros)\n");
    printf("  6- Mostrar la empresa con menor cantidad de micros\n");
    printf("  7- Pedir un micro y mostrar todos los vuelos que hizo el mismo.\n");
    printf("  8- Pedir un micro e informar la suma de los precios (costo) de todos los vuelos que realizo.\n");
    printf("  9- Pedir un destino y mostrar los micros que viajaron a ese destino y en qué fecha\n");
    printf("  10- Pedir una fecha y mostrar todos los viajes realizados en la misma.\n");
    printf("  20- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    //printf("\n");
    return opcion;
}


int informarMicrosEmpresa( eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipoServicio tipoServicios[], int tamT )
{
    int todoOk = 0;
    int idEmpresa;

    if (lista != NULL && tam > 0 && empresas != NULL && tamE > 0 && tipoServicios != NULL && tamT > 0)
    {
        system("cls");
        printf("            ***   Micros por empresa  ***\n");
        printf("------------------------------------------------------------\n");

        mostrarEmpresas(empresas, tamE);

        if ( !validarEntero(&idEmpresa, "Ingrese id de Empresa: ", "Error, ingrese un id de empresa valido.\n ", empresas[0].id, empresas[tamE-1].id, 10)  )
        {
            printf("\nError al ingresar id de Empresa, id ingresado por default: %d\n", empresas[0].id);
            idEmpresa = empresas[0].id;

        }

        informarMicrosIdEmpresa(idEmpresa, lista, tam, empresas, tamE, tipoServicios, tamT);

        todoOk = 1;
    }
    return todoOk;
}

int informarMicrosIdEmpresa( int idEmpresa, eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipoServicio tipoServicios[], int tamT )
{
    int todoOk = 0;
    int flag = 1;
    char descEmpresa[20];
    if (lista != NULL && tam > 0 && empresas != NULL && tamE > 0 && tipoServicios != NULL && tamT > 0 )
    {
        printf(" ID    Empresa             Tipo de Servicio      Cantidad de pasajeros     \n");
        printf("-----------------------------------------------------------------------------------\n");

        for (int i = 0; i < tam; i++)
        {
            if ( !lista[i].isEmpty && lista[i].idEmpresa == idEmpresa)
            {
                mostrarMicro(lista[i], empresas, tamE, tipoServicios, tamT);
                flag = 0;
            }
        }
        if (flag)
        {
            cargarDescripcionEmpresa(empresas, tamE, idEmpresa, descEmpresa);
            printf("   No hay micros de la empresa %s.\n", descEmpresa);
        }
        todoOk = 1;
    }
    return todoOk;
}

int informarMicrosTipo( eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipoServicio tipoServicios[], int tamT )
{
    int todoOk = 0;
    int idTipoServicios;
    if (lista != NULL && tam > 0 && empresas != NULL && tamE > 0 && tipoServicios != NULL && tamT > 0)
    {
        system("cls");
        printf("            ***   Micros por tipo de servicio  ***\n");
        printf("------------------------------------------------------------\n");

        mostrarTipoServicio(tipoServicios, tamT);

        if ( !validarEntero(&idTipoServicios, "Ingrese id de tipo de coche: ", "Error, ingrese un id de tipo de coche valido.\n ", tipoServicios[0].id, tipoServicios[tamT-1].id, 10)  )
        {
            printf("\nError al ingresar id de tipo de coche, id ingresado por default: %d\n", tipoServicios[0].id);
            idTipoServicios = tipoServicios[0].id;
        }

        informarMicrosIdTipo(idTipoServicios, lista, tam, empresas, tamE, tipoServicios, tamT);

        todoOk = 1;
    }
    return todoOk;
}

int informarMicrosIdTipo( int idTipoServicios, eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipoServicio tipoServicios[], int tamT )
{
    int todoOk = 0;
    int flag = 1;
    char descTipoServicio[20];
    if (lista != NULL && tam > 0 && empresas != NULL && tamE > 0 && tipoServicios != NULL && tamT > 0 )
    {
        printf(" ID    Empresa             Tipo de Servicio      Cantidad de pasajeros     \n");
        printf("-----------------------------------------------------------------------------------\n");

        for (int i = 0; i < tam; i++)
        {
            if ( !lista[i].isEmpty && lista[i].idTipo == idTipoServicios)
            {
                mostrarMicro(lista[i], empresas, tamE, tipoServicios, tamT);
                flag = 0;
            }
        }
        if (flag)
        {
            cargarDescripcionTipoServicio(tipoServicios, tamT, idTipoServicios, descTipoServicio);
            printf("   No hay micros del tipo de servicio %s.\n", descTipoServicio);
        }
        todoOk = 1;
    }
    return todoOk;
}

int informarPorcentajeMicrosVip( eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipoServicio tipoServicios[], int tamT )
{
    int todoOk = 0;
    int idEmpresa;
    char descEmpresa[15];
    int flag = 1;
    int contTotal = 0;
    int contVip = 0;
    float porcVip = 0;

    if ( lista != NULL && tam > 0 && empresas != NULL && tamE > 0 && tipoServicios != NULL && tamT > 0 )
    {
        system("cls");
        printf("            ***   Micros VIP por empresa  ***\n");
        printf("------------------------------------------------------------\n");

        mostrarEmpresas(empresas, tamE);

        if ( !validarEntero(&idEmpresa, "Ingrese id de Empresa: ", "Error, ingrese un id de empresa valido.\n ", empresas[0].id, empresas[tamE-1].id, 10)  )
        {
            printf("\nError al ingresar id de Empresa, id ingresado por default: %d\n", empresas[0].id);
            idEmpresa = empresas[0].id;
        }

        cargarDescripcionEmpresa(empresas, tamE, idEmpresa, descEmpresa);

        for (int i = 0; i < tam; i++)
        {
            if (!lista[i].isEmpty && lista[i].idEmpresa == idEmpresa)
            {
                contTotal++;
                if ( lista[i].idTipo == 5003 )
                {
                    contVip++;
                }
                flag = 0;
            }
        }
        if (!flag)
        {
            printf("\n");
            printf("En la empresa %s hay %d colectivos que bridan el servicio VIP.\n", descEmpresa, contVip);
            porcVip = (float) contVip / contTotal * 100;
            printf("Sobre un total de %d representan el %.2f%%\n", contTotal, porcVip);
            printf("\n");
        }
        else
        {
            printf("No hay micros VIP en esta empresa.\n");

        }
        todoOk = 1;
    }
    return todoOk;
}

int informarMicrosPorEmpresa( eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipoServicio tipoServicios[], int tamT )
{
    int todoOk = 0;

    if ( lista != NULL && tam > 0 && empresas != NULL && tamE > 0 && tipoServicios != NULL && tamT > 0 )
    {
        system("cls");
        printf("               ***  Micros de una  empresa  ***\n");
        printf("------------------------------------------------------------\n");

        for (int i = 0; i < tamE; i++)
        {
            printf("\n");
            printf("Empresa: %s\n", empresas[i].descripcion);
            informarMicrosIdEmpresa( lista[i].idEmpresa, lista, tam, empresas, tamE, tipoServicios, tamT );

            printf("\n------------------------------------------------------------\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

int informarEmpresasMayorCapacidad( eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipoServicio tipoServicios[], int tamT  )
{
    int todoOk = 0;

    int acumuladores[tamE] ;
    for (int i = 0; i < tamE; i++)
    {
        acumuladores[i] = 0;
    }

    int flag = 1;
    int empresaMayorCapacidad = 0;

    if (  lista != NULL && tam > 0 && empresas != NULL && tamE > 0 && tipoServicios != NULL && tamT > 0 )
    {
        system("cls");
        printf("            *** Empresa con mayor capacidad de transporte   ***\n");

        for (int i = 0; i < tam; i++)
        {
            for (int j = 0; j < tamE; j++)
            {
                if ( !lista[i].isEmpty && lista[i].idEmpresa == empresas[j].id)
                {
                    acumuladores[j] += lista[i].capacidad ;
                }
            }
        }
        //ya sabemos la capacidad de cada empresa
        for (int i = 0; i < tamE; i++)
        {
            if (flag || acumuladores[i] > empresaMayorCapacidad )
            {
                empresaMayorCapacidad = acumuladores[i];
                flag = 0;
            }
        }
        //ya sabemos la mayor cantidad de pasajeros de todas las empresas
        for (int i = 0; i < tamE; i++)
        {
            if (acumuladores[i] == empresaMayorCapacidad)
            {
                printf("\n");
                printf("La empresa con mayor capacidad de transporte es %s\n", empresas[i].descripcion);
            }
        }
        printf("Con %d pasajeros.\n", empresaMayorCapacidad);
        printf("\n");
        todoOk = 1;
    }
    return todoOk;
}

int informarEmpresaMenorCantidadMicros( eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipoServicio tipoServicios[], int tamT  )
{
    int todoOk = 0;

    int contadores[tamE] ;
    for (int i = 0; i < tamE; i++)
    {
        contadores[i] = 0;
    }

    int flag = 1;
    int empresaMenorCantidadMicros = 0;

    if (  lista != NULL && tam > 0 && empresas != NULL && tamE > 0 && tipoServicios != NULL && tamT > 0 )
    {
        system("cls");
        printf("            *** Empresa con menor cantidad de micros   ***\n\n");

        for (int i = 0; i < tam; i++)
        {
            for (int j = 0; j < tamE; j++)
            {
                if ( !lista[i].isEmpty && lista[i].idEmpresa == empresas[j].id)
                {
                    contadores[j]++;
                }
            }
        }
        //ya sabemos la cantidad de micros de cada empresa
        for (int i = 0; i < tamE; i++)
        {
            if (flag || contadores[i] < empresaMenorCantidadMicros )
            {
                empresaMenorCantidadMicros = contadores[i];
                flag = 0;
            }
        }
        //ya sabemos la menor cantidad de micros de todas las empresas
        for (int i = 0; i < tamE; i++)
        {
            if (contadores[i] == empresaMenorCantidadMicros)
            {

                printf("La empresa con menor cantidad de micros es %s\n", empresas[i].descripcion);
            }
        }
        printf("Con %d micros.\n", empresaMenorCantidadMicros);
        printf("\n");
        todoOk = 1;
    }
    return todoOk;

}

int informarViajesMicro( eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipoServicio tipoServicios[], int tamT, eDestino destinos[], int tamD, eViaje viajes[], int tamV )
{

    int todoOk = 0;
    int idMicro;
    if ( lista != NULL && tam > 0 && empresas != NULL && tamE > 0 && tipoServicios != NULL && tamT > 0 )
    {
        system("cls");
        printf("               ***  Viajes por micro  ***\n");
        printf("------------------------------------------------------------\n");

        mostrarMicros(lista, tam, empresas, tamE, tipoServicios, tamT);

        printf("\n");
        printf("Ingrese id de auto: ");
        scanf("%d", &idMicro);

        while ( !validarMicroId(lista, tam, idMicro)  )
        {
            printf("Error, ingrese id de micro valido: ");
            scanf("%d", &idMicro);
        }



        todoOk = 1;
    }
    return todoOk;
}

int informarViajeMicro( eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipoServicio tipoServicios[], int tamT, eDestino destinos[], int tamD, eViaje viajes[], int tamV, int idMicro )
{
    int todoOk = 0;
    int flag = 1;

    if ( lista != NULL && tam > 0 && empresas != NULL && tamE > 0 && tipoServicios != NULL && tamT > 0 )
    {
        system("cls");
        printf("            ***   Viajes realizados por micro  ***\n");
        printf("-------------------------------------------------------------------------------\n");
        printf(" idTr.     Marca           Color           Servicio      Precio      Fecha\n");
        printf("-------------------------------------------------------------------------------\n");
        for (int i = 0; i < tamT; i++)
        {
            if (  viajes[i].isEmpty == 0 && viajes[i].idMicro == idMicro)
            {
                mostrarViaje(viajes[i], lista, tam, empresas, tamE, destinos, tamD);

                flag = 0;
            }
        }
        if (flag)
        {
            printf("   No se hizo viajes el micro seleccionado\n");
        }
        todoOk = 1;

    }
    return todoOk;
}
