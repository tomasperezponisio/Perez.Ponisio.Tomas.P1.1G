#ifndef EMPRESA_H_INCLUDED
#define EMPRESA_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eEmpresa;

int mostrarEmpresas( eEmpresa empresas[], int tamE );

int validarIdEmpresa( int id, eEmpresa empresas[], int tamE );

int cargarDescripcionEmpresa( eEmpresa empresas[], int tamE, int idEmpresa, char descripcion[] );

#endif // EMPRESA_H_INCLUDED
