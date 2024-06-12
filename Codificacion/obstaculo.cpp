#include "obstaculo.h"
#include "utilities.h"

obstaculo::obstaculo(unsigned short obs_number, float ship_mass, float ship_force, unsigned short max_pixels, unsigned short SPEED_MAX) : fisicas(0, 0, ship_mass, ship_force, SPEED_MAX) {

    //LOGICA PARA ESTABLECER ANIMACIÓN.
    QString aux = prefix;
    aux.append("_" + std::to_string(obs_number) + ".gif");
    obstacle_animations = new animations(aux, max_pixels);
    setWidget(obstacle_animations -> getMain_label());

    //VARIABLES DE ESTADO DEL OBSTACULO.
    if(obs_number != 4) {
        is_dangerous = true;
        if(obs_number == 9) is_twister = true;
        else is_twister = false;
    }
    else is_dangerous = false;

    //LOGICA PARA LA REPRODUCCIÓN DE AUDIO.
    reproductor = new QMediaPlayer;
    output = new QAudioOutput;
    reproductor -> setAudioOutput(output);
    determine_audio_route(obs_number);


    //VARIABLES FISICAS.
    if(obs_number < 4) issued_damage = 10 * obs_number;
    crash_happening = false;
    crash_counter = 0;
    speed = SPEED_MIN;

    //TIMERS
    movement_timer = new QTimer;
    crash_timer = new QTimer;

    //CONEXIONES DE TIMERS
    connect(movement_timer, &QTimer::timeout, this, &obstaculo::handle_timeout);
    connect(crash_timer, &QTimer::timeout, this, &obstaculo::crash_timeout);
}

obstaculo::~obstaculo()
{
    //LIBERACIÓN DE TIMERS.
    delete movement_timer;
    delete crash_timer;
    //LIBERACION DE ANIMACIONES.
    setWidget(nullptr);
    delete obstacle_animations;
    this -> disconnect();
    //LIBERACIÓN DE AUDIO.
    delete reproductor;
    delete output;
}

void obstaculo::handle_timeout()
{
    QPoint aux = QPoint(x(), y() + mru(1)); //Calcula la nueva ubicación del obstaculo.
    emit ask_move(aux, this, crash_happening); //Pide permiso para moverse.
    if(y() > 700) {
        emit surpassed_limit(this); //Si pasa el limite de la escena emite una señal que permite remover el objeto
    }
}

void obstaculo::crash_timeout()
{
    if(crash_counter < 40){
        QPoint aux = QPoint(x(), y() + mru(-1)); //Pareja ordenada que contiene la nueva ubicacion del obstaculo.
        speed = trabajo(-1); //Disminuye la velocidad del obstaculo en direccion contraria al a que se mueve.
        emit ask_move(aux, this, crash_happening); //Emite la señal que pide permiso para moverse.
        crash_counter++; //Aumenta el contador en uno.
    }
    else{
        crash_timer -> stop(); //Interrupme el temporizador de choque.
        if(!movement_timer->isActive()) movement_timer -> start(25); //Inicializa nuevamente el movimiento del obstaculo.
        crash_happening = false; //Establece el estado de choque como falso.
        crash_counter = 0; //Vuelve otra vez el contador a cero.
    }
}

void obstaculo::start_crash(QGraphicsProxyWidget *widget)
{
    if(widget == this && is_dangerous){ //Verifica que el widget se choco sea él mismo, y también si es peligroso o no.
        crash_happening = true; //Establece el estado de choque como verdadero.
        movement_timer -> stop(); //Detiene el movimiento usual del obstaculo.
        crash_timer -> start(25); //Inicia el temporizador cada 25ms.
    }
}

void obstaculo::determine_audio_route(unsigned short obs_number)
{
    //Ayuda a establecer el audio que emitirá cada obstaculo según su numero.
    if(obs_number <= 3){
        audio_route = "qrc:/audio/Audios/crash.ogg";
    }
    else if(obs_number == 4) audio_route = "qrc:/audio/Audios/coin.wav";
    else if(obs_number == 6) audio_route = "qrc:/audio/Audios/buy.mp3";
    else if(obs_number == 7) audio_route = "qrc:/audio/Audios/error.mp3";
    else if(obs_number == 8) audio_route = "qrc:/audio/Audios/wave.mp3";
}

void obstaculo::start_movement(){
    movement_timer->start(25); //Inicia el temporizador cada 25ms.
}

void obstaculo::stop_movement()
{
    movement_timer -> stop(); //Detiene el temporizador de movimiento usual.
    crash_timer -> stop(); //Detiene el temporizador de choque.
}

animations *obstaculo::getObstacle_animations()
{
    return obstacle_animations;
}

bool obstaculo::getIs_dangerous() const
{
    return is_dangerous;
}

void obstaculo::setIs_dangerous(bool newIs_dangerous)
{
    is_dangerous = newIs_dangerous;
}


bool obstaculo::getIs_twister() const
{
    return is_twister;
}

void obstaculo::setIs_twister(bool newIs_twister)
{
    is_twister = newIs_twister;
}

unsigned short obstaculo::getIssued_damage() const
{
    return issued_damage;
}

void obstaculo::setIssued_damage(unsigned short newIssued_damage)
{
    issued_damage = newIssued_damage;
}

void obstaculo::play_own_music()
{
    play_music(audio_route, reproductor, output, true);
}

void obstaculo::change_speed(short direction)
{
    if(!crash_happening) speed = trabajo(direction);
}

