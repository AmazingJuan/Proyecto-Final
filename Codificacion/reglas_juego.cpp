#include "reglas_juego.h"
#include "utilities.h"

reglas_juego::reglas_juego(QVector<QGraphicsView *> &graphics)
{
    seed = std::chrono::system_clock::now().time_since_epoch().count();
    next_scene = -1;
    in_scene_obstacles = 0;
    current_matrix_fila = 0;
    current_scene = -1;
    change_scene_timer = new QTimer();
    interfaces = graphics;
    saves = new partidas(savegame_route);
    initial_conections();
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
}

void reglas_juego::setup()
{
    scenes.push_back(new QGraphicsScene);
    scenes[scenes.size()-1]->setSceneRect(0, 0, 700, 700);
    scenes.push_back(new QGraphicsScene);
    scenes[scenes.size()-1]->setSceneRect(0, 0, 700, 700);
    scenes.push_back(new QGraphicsScene);
    scenes[scenes.size()-1]->setSceneRect(0, 0, 700, 700);
    scenes.push_back(new QGraphicsScene);
    scenes[scenes.size()-1]->setSceneRect(0, 0, 700, 700);
    int indice = 0;
    for(auto it = scenes.begin(); it != scenes.end(); it++) {
        interfaces[indice]->setScene(scenes[indice]);
        indice++;
    }
    scenes[2] -> setBackgroundBrush(Qt::black);
    saves->abrirArchivo();
}

void reglas_juego::key_pressed(int key)
{
    if(current_scene == 3){
        if(key == Qt::Key_W){
            ship -> move(0);
            emit change_speed(1);
        }
        else if(key == Qt::Key_A){
            ship -> move(1);
        }
        else if(key == Qt::Key_D){
            ship -> move(2);
        }
        else if(key == Qt::Key_S){
            emit change_speed(-1);
        }
    }
}

void reglas_juego::obstacle_connections(obstaculo *obstacle)
{
    connect(obstacle, &obstaculo::ask_move, this, &reglas_juego::try_move);
    connect(this, &reglas_juego::crash, obstacle, &obstaculo::start_crash);
    connect(this, &reglas_juego::change_speed, obstacle, &obstaculo::change_speed);
    if(!obstacle -> getIs_dangerous()) connect(obstacle, &obstaculo::collect_coin, ship, &barco::recieve_coin);
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
    next_scene = 3;
    ship = new barco(1, "ship1", 0 ,0);
    scenes[3] -> addItem(ship);
    ship -> setX(300);
    ship -> setY(400);
    setup_obstacles();
    connect(this, &reglas_juego::crash, ship, &barco::start_crash);
    connect(ship, &barco::ask_move, this, &reglas_juego::try_move);

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

void reglas_juego::try_move(QPoint pos, QGraphicsProxyWidget *widget, bool crash_happening)
{

    bool aux = is_colliding(widget);
    auto auxObs = dynamic_cast<obstaculo*>(widget);
    if(!crash_happening){
        if(!aux && widget->isActive()){
            widget->setX(pos.x());
            widget->setY(pos.y());
        }
        else if(widget->isActive()){
            ship -> setMoney(500);
        }
        else if(!aux){
            ship -> setMoney(500);
        }
        else if(aux && auxObs -> getIs_dangerous()){
            emit crash(widget);
        }
        else{

        }
    }
    else{
        widget->setX(pos.x());
        widget->setY(pos.y());
    }

}

void reglas_juego::show_middle_message(QString text)
{
    next_scene = 2;
    change_scene();
    emit shoot_label_change(0, text);
}

void reglas_juego::initial_conections()
{
    connect(this, &reglas_juego::crear_archivo, saves, &partidas::creacion);
    connect(saves, &partidas::hayPartidas, this, &reglas_juego::loadMenu);
    connect(change_scene_timer, &QTimer::timeout, this, &reglas_juego::change_scene);
}

bool reglas_juego::is_colliding(QGraphicsProxyWidget *widget)
{
    if(widget != ship){
        return widget->collidesWithItem(ship);
    }
    else{
        return false;
    }
}

void reglas_juego::setup_obstacles()
{
    for(unsigned short fila = 0; fila < max_y; fila++){
        obstacles.push_back(new QVector<obstaculo*>);
        QVector<obstaculo*> aux = *obstacles[fila];
        for (unsigned short columna = 0; columna < max_x; columna++) {
            if(random_bool(seed)) aux.push_back(new obstaculo(4, ship -> getMass()));
            else aux.push_back(new obstaculo(random_short(1,current_scene, seed), ship -> getMass()));
            scenes[3] -> addItem(aux[columna]);
            aux[columna] -> setX(columna * 100);
            aux[columna] -> setY(-1*(fila + 1) * 100);
            obstacle_connections(aux[columna]);
            aux[columna]->start_movement();
        }
    }
}
