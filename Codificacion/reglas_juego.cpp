#include "reglas_juego.h"

reglas_juego::reglas_juego(QVector<QWidget *> &widgets)
{
    interfaces = widgets;
    scene = new QGraphicsScene;
    graph -> setScene(scene);
    main_menu();
}

void reglas_juego::main_menu(){
    saves = new partidas;
    show_image(scene, QString(":/imagenes/Imagenes/menuppal.png"));
}


reglas_juego::~reglas_juego()
{
    delete scene;
}

void reglas_juego::cargar()
{

}

void reglas_juego::salir()
{

}

void reglas_juego::iniciar()
{

}
