#include "reglas_juego.h"
#include "imagenes.h"

reglas_juego::reglas_juego(QVector<QGraphicsView *> &graphics)
{
    next_scene = -1;
    current_scene = -1;
    change_scene_timer = new QTimer();

    interfaces = graphics;
    saves = new partidas(savegame_route);
    conexiones();
}


void reglas_juego::main_menu(){
    emit show_screen(main_menu_scene);
    current_scene = 0;
    show_image(scenes[current_scene], QString(":/imagenes/Imagenes/menuppal.png"));
}

void reglas_juego::main_menu_load()
{
    emit show_screen(main_menu_load_scene);
    current_scene = 1;
    show_image(scenes[current_scene], QString(":/imagenes/Imagenes/menuppal_carga.png"));
}


reglas_juego::~reglas_juego()
{
    delete saves;
    delete change_scene_timer;
    delete graph;
}

void reglas_juego::setup()
{
    scenes.push_back(new QGraphicsScene);
    scenes.push_back(new QGraphicsScene);
    scenes.push_back(new QGraphicsScene);
    int indice = 0;
    for(auto it = scenes.begin(); it != scenes.end(); it++) {
        interfaces[indice]->setScene(scenes[indice]);
        indice++;
    }
    scenes[2] -> setBackgroundBrush(Qt::black);
    saves->abrirArchivo();
}


void reglas_juego::cargar()
{

}

void reglas_juego::salir()
{

}

void reglas_juego::iniciar()
{
    change_scene_timer -> start(5000);
    show_middle_message("Texto_prueba");
    next_scene = 0;
}

void reglas_juego::change_scene()
{
    emit hide_screen(current_scene);
    emit show_screen(next_scene);
    current_scene = next_scene;
    if(change_scene_timer->remainingTime() == 0){
        change_scene_timer -> stop();
    }
}

void reglas_juego::loadMenu(bool dato)
{
    if(dato) main_menu_load();
    else main_menu();
}

void reglas_juego::show_middle_message(QString text)
{
    next_scene = 2;
    change_scene();
    emit shoot_label_change(0, text);
}

void reglas_juego::conexiones()
{
    connect(this, &reglas_juego::crear_archivo, saves, &partidas::creacion);
    connect(saves, &partidas::hayPartidas, this, &reglas_juego::loadMenu);
    connect(change_scene_timer, &QTimer::timeout, this, &reglas_juego::change_scene);
}
