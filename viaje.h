#ifndef VIAJE_H_INCLUDED
#define VIAJE_H_INCLUDED

#include "fecha.h"
#include "micro.h"
#include "destino.h"
#include "fecha.h"

typedef struct
{
    int id;
    int idMicro;
    int idDestino;
    eFecha fecha;
    int isEmpty;

}eViaje;


/** \brief
 *
 * \param viajes[] eViaje
 * \param tamV int
 * \return int
 *
 */
int inicializarViajes( eViaje viajes[], int tamV );

/** \brief
 *
 * \param viajes[] eViaje
 * \param tamV int
 * \return int
 *
 */
int buscarLibreViaje( eViaje viajes[], int tamV );

/** \brief
 *
 * \param viajes[] eViaje
 * \param tamV int
 * \param lista[] eMicro
 * \param tam int
 * \param empresas[] eEmpresa
 * \param tamE int
 * \param tipoServicios[] eTipoServicio
 * \param tamT int
 * \param destinos[] eDestino
 * \param tamD int
 * \param pIdViaje int*
 * \return int
 *
 */
int altaViaje( eViaje viajes[], int tamV, eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipoServicio tipoServicios[], int tamT, eDestino destinos[], int tamD, int* pIdViaje );

void mostrarViaje( eViaje unViaje, eMicro lista[], int tam, eEmpresa empresas[], int tamE,  eDestino destinos[], int tamD );

/** \brief
 *
 * \param viajes[] eViaje
 * \param tamV int
 * \param lista[] eMicro
 * \param tam int
 * \param empresas[] eEmpresa
 * \param tamE int
 * \param destinos[] eDestino
 * \param tamD int
 * \return int
 *
 */
int mostrarViajes( eViaje viajes[], int tamV, eMicro lista[], int tam, eEmpresa empresas[], int tamE, eDestino destinos[], int tamD );

/** \brief Pide una fecha en el formato dd/mm/aaaa , los campos dia, mes y anio se gurdan en una variable eFecha
 *
 * \return eFecha
 *
 */
//eFecha pedirFecha();

int pedirFecha(eFecha* unaFecha);


#endif // VIAJE_H_INCLUDED
