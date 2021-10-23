#ifndef MICRO_H_INCLUDED
#define MICRO_H_INCLUDED

#include "empresa.h"
#include "tipoServicio.h"


typedef struct
{
    int id; // pk
    int idEmpresa; //fk
    int idTipo; //fk
    int capacidad;
    int isEmpty; //1 esta vacio, 0 esta lleno
} eMicro;

/** \brief
 *
 * \return int
 *
 */
int menu();

/** \brief
 *
 * \param lista[] eAuto
 * \param tam int
 * \return int
 *
 */
int inicializarMicros( eMicro lista[], int tam );

/** \brief
 *
 * \param lista[] eAuto
 * \param tam int
 * \return int
 *
 */
int buscarLibre( eMicro lista[], int tam ); // -1 si esta todo lleno o el indice de la primer estructura vacia

/** \brief
 *
 * \param lista[] eAuto
 * \param tam int
 * \param marcas[] eMarca
 * \param tamM int
 * \param colores[] eColor
 * \param tamC int
 * \param pId int*
 * \return int
 *
 */

int altaMicro( eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipoServicio tipoServicios[], int tamT, int* pId  );

/** \brief
 *
 * \param unAuto eAuto
 * \param marcas[] eMarca
 * \param tamM int
 * \param colores[] eColor
 * \param tamC int
 * \return void
 *
 */
void mostrarMicro( eMicro unMicro, eEmpresa empresas[], int tamE, eTipoServicio tipoServicios[], int tamT );

/** \brief
 *
 * \param lista[] eAuto
 * \param tam int
 * \param marcas[] eMarca
 * \param tamM int
 * \param colores[] eColor
 * \param tamC int
 * \return int
 *
 */
int mostrarMicros( eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipoServicio tipoServicios[], int tamT );

/** \brief
 *
 * \param lista[] eAuto
 * \param tam int
 * \return int
 *
 */
int ordenarMicros( eMicro lista[], int tam );


/** \brief
 *
 * \param lista[] eAuto
 * \param tam int
 * \param marcas[] eMarca
 * \param tamM int
 * \param colores[] eColor
 * \param tamC int
 * \return int
 *
 */
int bajaMicro( eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipoServicio tipoServicios[], int tamT );

/** \brief
 *
 * \param lista[] eAuto
 * \param tam int
 * \param Id int
 * \return int
 *
 */
int buscarMicroId( eMicro lista[], int tam, int Id );


/** \brief
 *
 * \param lista[] eAuto
 * \param tam int
 * \param marcas[] eMarca
 * \param tamM int
 * \param colores[] eColor
 * \param tamC int
 * \return int
 *
 */
int modificarMicro( eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipoServicio tipoServicios[], int tamT );

/** \brief
 *
 * \param lista[] eAuto
 * \param tam int
 * \param indice int
 * \param marcas[] eMarca
 * \param tamM int
 * \param colores[] eColor
 * \param tamC int
 * \return int
 *
 */
int menuModificar( eMicro lista[], int tam, int indice, eEmpresa empresas[], int tamE, eTipoServicio tipoServicios[], int tamT );

/** \brief
 *
 * \param lista[] eAuto
 * \param tam int
 * \param marcas[] eMarca
 * \param tamM int
 * \param idAuto int
 * \param marca[] char
 * \return int
 *
 */
int cargarEmpresaMicro( eMicro lista[], int tam, eEmpresa empresas[], int tamE, int idMicro, char empresa[] );



#endif // MICRO_H_INCLUDED
