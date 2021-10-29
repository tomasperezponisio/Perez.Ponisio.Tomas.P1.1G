#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

#include "micro.h"
#include "empresa.h"
#include "tipoServicio.h"

int menuInformes();

int informarMicrosEmpresa( eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipoServicio tipoServicios[], int tamT );

int informarMicrosIdEmpresa( int idEmpresa, eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipoServicio tipoServicios[], int tamT );

int informarMicrosTipo( eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipoServicio tipoServicios[], int tamT );

int informarMicrosIdTipo( int idTipoServicios, eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipoServicio tipoServicios[], int tamT );

int informarPorcentajeMicrosVip( eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipoServicio tipoServicios[], int tamT );

int informarMicrosPorEmpresa( eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipoServicio tipoServicios[], int tamT );

int informarEmpresasMayorCapacidad( eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipoServicio tipoServicios[], int tamT  );

int informarEmpresaMenorCantidadMicros( eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipoServicio tipoServicios[], int tamT  );



#endif // INFORMES_H_INCLUDED
