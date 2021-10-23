#ifndef EMPRESA_H_INCLUDED
#define EMPRESA_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eTipo;

int mostrarTipo( eTipo tipos[], int tamT );

int validarIdTipo( int id, eTipo tipos[], int tamT );

int cargarDescripcionTipo( eTipo tipos[], int tamT, int idTipo, char descripcion[] );

#endif // EMPRESA_H_INCLUDED
