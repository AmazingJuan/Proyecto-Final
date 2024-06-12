#include "barco.h"

barco::barco(unsigned short level, unsigned short hp, int pos_x, int pos_y) : fisicas(pos_x, pos_y, level * 5, 0.1 * level, 4)
{
    //CARACTERISTICAS DEL BARCO.
    QString aux = file_prefix + QString::number(level);
    ship_animations = new animations(aux, ship_animations_number, 100);
    this -> level = level;
    this -> hp = hp;
    this -> setWidget(ship_animations -> getMain_label());
    ship_animations -> set_animation(0);
    setX(pos_x);
    setY(pos_y);
    speed = 2 + 0.5 * (level - 1);

    //TIMERS
    crash_timer = new QTimer;
    shm_timer = new QTimer;
    mcu_timer = new QTimer;

    //CONEXIONES
    connect(crash_timer, &QTimer::timeout, this, &barco::crash_timeout);
    connect(shm_timer, &QTimer::timeout, this, &barco::shm_timeout);
    connect(mcu_timer, &QTimer::timeout, this, &barco::mcu_timeout);

    //BOOLEANOS DE MOVIMIENTO
    crash_happening = false;
    shm_happening = false;
}

barco::~barco()
{
    setWidget(nullptr); //Se desliga el label con el QMovie del QGraphicsProxyWidget.
    //Se borran los timer y las animaciones.
    delete crash_timer;
    delete shm_timer;
    delete mcu_timer;
    delete ship_animations;
}


void barco::move(int animation)
{
    ship_animations -> set_animation(animation); //Cambia de animación.
    //Emite una señal que pide permiso para moverse, sea a la izquierda o a la derecha.
    if(animation == 1){
        emit ask_move(QPoint(x() + mru(-1), y()), this, crash_happening);
    }
    else if(animation == 2){
        emit ask_move(QPoint(x() + mru(1), y()), this, crash_happening);
    }
}

void barco::level_up(unsigned short level)
{
    speed += 0.5; //Aumenta la velocidad del barco.
    this -> level = level; //Actualiza la variable nivel del barco.
    mass = level * 5; //Actualiza la variable masa del barco.
    ship_force *= level; //Actualiza la variable fuerza del barco.
    QString aux = file_prefix + QString::number(level); //Actualiza el prefijo de las animaciones del barco.
    ship_animations -> change_animations(aux, 3); //Cambia de gif al correspondiente al nuevo nivel.
    max_speed++; //Aumenta la velocidad máxima a la que puede ir el barco.
    hp = level*50;
}

void barco::stop_movement()
{
    //Detiene todos los timer de movimiento fisico.
    crash_timer -> stop();
    shm_timer -> stop();
    mcu_timer -> stop();
}

void barco::crash_timeout()
{
    if(crash_counter < 40){
        QPoint aux = QPoint(x(), y() + mru(1)); //Pareja ordenada que contiene la nueva ubicacion del barco.
        speed = trabajo(-1); //Disminuye la velocidad del barco en direccion contraria al a que se mueve.
        emit ask_move(aux, this, crash_happening); //Emite la señal que pide permiso para moverse.
        crash_counter++; //Aumenta el contador en uno.
    }
    else if(y() != 400){ //Condicion que se activa cuando ya el contador de choque sobrepaso el numero 40, y sirve para regresar al bote a su posición Y original.
        QPoint aux = QPoint(x(), y() + mru(-1)); //Pareja ordenada que contiene la nueva ubicacion del barco.
        emit ask_move(aux, this, crash_happening); //Emite la señal que pide permiso para moverse.
        if(aux.y() <= 400){ //Verifica si la nueva ubicación tiene una coordenada Y menor a 400, es decir, volvió a su posición original;
            crash_timer -> stop(); //Para el reloj de choques.
            crash_counter = 0;
            crash_happening = false; //Indica que ya no está sucediendo choque.
        }
        speed = 2 + 0.5 * (level - 1); //Le devuelve la velocidad original que tenía el barco.
    }
}

void barco::shm_timeout()
{
    if(shm_counter < 600){ //Verifica si han pasado 15 segundos. (600 * 25ms = 15000ms = 15 s).
        shm_counter++; //Se incrementa el contador del tiempo
        QPoint aux = QPoint(shm_x(float(shm_counter)/2), y()); //Se calcula la nueva posición del movimiento armónico simple, aumentando en 0.5 la función que computa la posición.
        emit ask_move(aux, this, shm_happening); //Emite la señal que pide permiso para moverse.
    }
    else{
        shm_timer -> stop(); //Si han pasado 15 segundos se para el timer.
        speed = 2 + 0.5 * (level - 1); //Le devuelve la velocidad original que tenía el barco.
    }
}

void barco::mcu_timeout()
{
    if(radius > 50){ //Verifica que el radio sea mayor a 50, mientras eso pase el movimiento circular se lleva a cabo.
        mcu_counter++;
        emit ask_move(mcu(), this, shm_happening); //Emite la señal que pide permiso para moverse.
    }
    else{
        stop_movement(); //Para todo tipo de movimiento.
        emit mcu_finished(); //Emite una señal que indica que el movimiento circular termino (este movimiento solo se usa para simular un tornado).
    }
}

void barco::start_crash(float speed)
{
    //Inicia el choque, con la velocidad que llevaba el obstaculo.
    crash_happening = true; //Booleano que indica que está sucediendo un choque.
    crash_counter = 0;
    if(!crash_timer->isActive()) crash_timer -> start(25); //Se activa el timer de choque.
    this -> speed = speed; //Se establece la velocidad del barco. Esta velocidad es la que llevaba el obstaculo con quien chocó.
}

void barco::start_shm()
{
    shm_happening = true; //Activa la variable de control que indica que está sucediendo un MAS
    shm_counter = 0; //Contador de tiempo se inicializa en 0.
    initial_x = x(); //Se establece como posición inicial, la posición actual del widget.
    calculate_initial_time(); //Se calcula en que tiempo del movimiento armonico simple se encuentra.
    if(!shm_timer->isActive()) shm_timer -> start(25); //Comienza el movimiento armonico simple.
}

void barco::start_mcu(){
    center_x = 300; //Establece el centro en x del MC.
    center_y = 300; //Establece el centro en x del MC.
    mcu_counter = 0; //Inicializa el contador en cero.
    angle = 0; //Inicializa el angulo en cero.
    if(!mcu_timer -> isActive()) mcu_timer -> start(25); //Se inicia el temporizador del MC.
}


animations *barco::getShip_animations()
{
    return ship_animations;
}

unsigned short barco::getMoney() const
{
    return money;
}

void barco::addMoney(unsigned short newMoney)
{
    money += newMoney;
}

void barco::setMoney(unsigned short money)
{
    this -> money = money;
}

unsigned short barco::getLevel() const
{
    return level;
}

void barco::setLevel(unsigned short newLevel)
{
    level = newLevel;
}

unsigned short barco::getHp() const
{
    return hp;
}

void barco::setHp(unsigned short newHp)
{
    hp = newHp;
}


