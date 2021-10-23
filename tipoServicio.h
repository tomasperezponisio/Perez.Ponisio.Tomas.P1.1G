#ifndef TIPOSERVICIO_H_INCLUDED
#define TIPOSERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];

}eTipoServicio;


int mostrarTipoServicio ( eTipoServicio tipoServicios[], int tamT   );

int validarIdTipoServicio( int id, eTipoServicio tipoServicios[], int tamT );

int cargarDescripcionTipoServicio( eTipoServicio tipoServicios[], int tamT, int idTipoServicio, char descripcion[] );


#endif // TIPOSERVICIO_H_INCLUDED
