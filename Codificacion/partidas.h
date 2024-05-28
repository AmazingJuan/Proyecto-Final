#ifndef PARTIDAS_H
#define PARTIDAS_H

#define max_slots 3
#import <QFile.h>

class partidas
{
public:
    partidas(char *ruta);
    ~partidas();
private:
    char *nombreArchivo;
    QFile archivo;

    void abrirArchivo();




};

#endif // PARTIDAS_H
