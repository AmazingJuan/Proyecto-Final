#ifndef PARTIDAS_H
#define PARTIDAS_H

#define max_slots 3
#include <QFile>
#include <QObject>

class partidas : public QObject
{
    Q_OBJECT
public:
    partidas(char *ruta);
    ~partidas();
    void abrirArchivo();
private:
    char *nombreArchivo;
    QFile archivo;

signals:
    void hayPartidas(bool hayPartidas);
public slots:
    void creacion();

};

#endif // PARTIDAS_H
