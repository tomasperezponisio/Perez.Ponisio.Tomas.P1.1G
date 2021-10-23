#include <string.h>
#include "dataWarehouse.h"

char capacidad[10] = { 10, 20, 30, 40, 45, 45, 40, 35, 25, 15 };

int idEmpresa[10] = { 1000, 1002, 1001, 1002, 1000, 1001, 1003, 1000, 1002, 1003};

int idTipoServicios[10] = { 5000, 5003, 5001, 5000, 5002, 5001, 5002, 5000, 5001, 5001};

int hardcodearMicros( eMicro lista[], int tam, int cant, int* pId )
{
    int contador = -1;
    if (lista != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL)
    {
        contador = 0;
        for (int i = 0; i < cant;  i++)
        {
            lista[i].id = *pId;
            (*pId)++;
            lista[i].idEmpresa = idEmpresa[i];
            lista[i].idTipo = idTipoServicios[i];
            lista[i].capacidad = capacidad[i];
            lista[i].isEmpty = 0;
            contador++;
        }
    }
    return contador;
}
