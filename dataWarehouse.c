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

int idMicro[10] = { 100, 101, 102, 103, 104, 105, 106, 107, 108, 109};

int idDestino[10] = { 20000, 20001, 20002, 20003, 20002, 20001, 20002, 20000, 20003, 20000};

int fechasDia[10] =  {20, 20, 20, 20, 20, 20, 20, 20, 20, 20};

int fechasMes[10] = {02, 02, 02, 02, 02, 02, 02, 02, 02, 02};

int fechasAnio[10] = {2003, 2005, 2007, 2000, 2000, 2000, 2000, 2000, 2000, 2000};

int hardcodearViajes( eViaje viajes[], int tamV, int cant, int* pId )
{
    int contador = -1;
    if (viajes != NULL && tamV > 0 && cant >= 0 && cant <= tamV && pId != NULL)
    {
        contador = 0;
        for (int i = 0; i < cant;  i++)
        {
            viajes[i].id = *pId;
            (*pId)++;
            viajes[i].idMicro = idMicro[i];
            viajes[i].idDestino = idDestino[i];
            viajes[i].fecha.dia = fechasDia[i];
            viajes[i].fecha.mes = fechasMes[i];
            viajes[i].fecha.anio = fechasAnio[i];
            viajes[i].isEmpty = 0;
            contador++;
        }
    }
    return contador;
}


