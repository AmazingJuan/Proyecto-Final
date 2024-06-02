#include "partidas.h"

partidas::partidas(char *ruta) {
    nombreArchivo = ruta;
    QFile archivo;
}

partidas::~partidas()
{
}

void partidas::abrirArchivo()
{
    archivo.setFileName(nombreArchivo);
    emit hayPartidas(archivo.exists());
}

void partidas::creacion()
{


}
