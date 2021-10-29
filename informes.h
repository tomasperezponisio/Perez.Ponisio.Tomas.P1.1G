#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

#include "micro.h"
#include "empresa.h"
#include "tipoServicio.h"
#include "destino.h"
#include "viaje.h"

int menuInformes();

int informarMicrosEmpresa( eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipoServicio tipoServicios[], int tamT );

int informarMicrosIdEmpresa( int idEmpresa, eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipoServicio tipoServicios[], int tamT );

int informarMicrosTipo( eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipoServicio tipoServicios[], int tamT );

int informarMicrosIdTipo( int idTipoServicios, eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipoServicio tipoServicios[], int tamT );

int informarPorcentajeMicrosVip( eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipoServicio tipoServicios[], int tamT );

int informarMicrosPorEmpresa( eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipoServicio tipoServicios[], int tamT );

int informarEmpresasMayorCapacidad( eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipoServicio tipoServicios[], int tamT  );

int informarEmpresaMenorCantidadMicros( eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipoServicio tipoServicios[], int tamT  );

int informarViajesMicro( eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipoServicio tipoServicios[], int tamT, eDestino destinos[], int tamD, eViaje viajes[], int tamV );

int informarViajeMicro( eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipoServicio tipoServicios[], int tamT, eDestino destinos[], int tamD, eViaje viajes[], int tamV, int idMicro );


#endif // INFORMES_H_INCLUDED
