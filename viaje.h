#ifndef VIAJE_H_INCLUDED
#define VIAJE_H_INCLUDED

#include "fecha.h"
#include "micro.h"
#include "destino.h"

typedef struct
{
    int id;
    int idMicro;
    int idDestino;
    eFecha fecha;
    int isEmpty;


}eViaje;


int inicializarViajes( eViaje viajes[], int tamV );

int buscarLibreViaje( eViaje viajes[], int tamV );

int altaViaje( eViaje viajes[], int tamV, eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipoServicio tipoServicios[], int tamT, eDestino destinos[], int tamD, int* pIdViaje );

void mostrarViaje( eViaje unViaje, eMicro lista[], int tam, eEmpresa empresas[], int tamE,  eDestino destinos[], int tamD );

int mostrarViajes( eViaje viajes[], int tamV, eMicro lista[], int tam, eEmpresa empresas[], int tamE, eDestino destinos[], int tamD );


#endif // VIAJE_H_INCLUDED
