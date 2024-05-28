#ifndef REGLAS_JUEGO_H
#define REGLAS_JUEGO_H

#include <QPushButton>
#include <QWidget>
#include <QVector>
#include <QLabel>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>

#include "imagenes.h"
#include "partidas.h"

#define game_scale_factor 2
#define savegame_route "../savegame.txt"

class reglas_juego : public QObject
{
    Q_OBJECT
public:
    reglas_juego(QVector<QWidget *> &widgets);
    ~reglas_juego();   
private slots:
    void cargar();
    void salir();
    void iniciar();
private:
    QGraphicsView *graph;
    QVector<QLabel *> labels;
    QVector<QPushButton *> buttons;
    QVector<QWidget *> interfaces;
    QGraphicsScene *scene;
    partidas *saves;

    void main_menu();
    void hide_buttons(QVector<QPushButton *> &buttons);
    void show_buttons(QVector<QPushButton *> &buttons);
};

#endif // REGLAS_JUEGO_H
