#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipoServicio.h"

int mostrarTipoServicio ( eTipoServicio tipoServicios[], int tamT   )
{
    int todoOk = 0;
    if (tipoServicios != NULL && tamT > 0 )
    {
        printf("      *** Empresas *** \n\n");
        printf("  Id         Descripcion\n");
        for (int i = 0; i < tamT; i++)
        {
            printf("  %d       %-10s\n", tipoServicios[i].id, tipoServicios[i].descripcion);
        }
        //printf("\n");
        todoOk = 1;
    }

    return todoOk;
}


int validarIdTipoServicio( int id, eTipoServicio tipoServicios[], int tamT )
{
    int esValido = 0;
    if (tipoServicios != NULL && tamT > 0)
    {
        for (int i = 0; i < tamT; i++)
        {
            if (id == tipoServicios[i].id)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}

int cargarDescripcionTipoServicio( eTipoServicio tipoServicios[], int tamT, int idTipoServicio, char descripcion[] )
{
    int todoOk = 0;
    int flag = 1;
    if (tipoServicios != NULL && tamT > 0 && descripcion != NULL)
    {
        todoOk = 1;
        for (int i = 0; i < tamT; i++)
        {
            if (tipoServicios[i].id == idTipoServicio)
            {
                strcpy(descripcion, tipoServicios[i].descripcion);
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            todoOk = -1; // no habia marca con el id que le pasaron
        }
    }
    return todoOk;
}
