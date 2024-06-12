#include "animations.h"

animations::animations(QString file_prefix, int number_animations, unsigned short max_pixels)
{
    main_label = new QLabel; //Inicializa un nuevo QLabel.
    this -> max_pixels = max_pixels; //Se establece el tamaño de los pixeles
    setup_label(max_pixels); //Hace las modificaciones pertinentes al label.
    this -> file_prefix = file_path + file_prefix; //Se establece la ruta del archivo de la animación.
    animations_number = number_animations; //Se establecen el numero de animaciones.
    initialize_movies(); //Se inicializan los QMovies que permitirán almacenar las animaciones.
}

animations::animations(QString route, unsigned short max_pixels)
{
    main_label = new QLabel; //Inicializa un nuevo QLabel.
    this -> max_pixels = max_pixels; //Se establece el tamaño de los pixeles
    setup_label(max_pixels); //Hace las modificaciones pertinentes al label.
    animations_number = 1; //Se establecen el numero de animaciones.
    movies.push_back(new QMovie(route)); //Se pone como unica animacion la que se indique en el QString route.
    movies[0]->start(); //Se inicia la QMovie.
    main_label->setMovie(movies[0]); //Se le da un QMovie al main_label.
}

animations::~animations()
{
    dispose_movies(); //Se libera la memoria ocupada por las QMovies.
    delete main_label; //Borra el main label.
}

void animations::change_animations(QString file_prefix, int number_animations)
{
    this -> file_prefix = file_path + file_prefix; //Se establece la nueva ruta de las animaciones.
    main_label -> setMovie(nullptr); //Quita la movie actual del label.
    dispose_movies(); //Se libera la memoria ocupada por las QMovies viejas.
    animations_number = number_animations; //Se establece el nuevo numero de animaciones.
    initialize_movies(); //Se inicializan las QMovies nuevas.
}

void animations::initialize_movies()
{
    QString string = file_prefix; //Se inicializa un string auxiliar.
    for(int cont = 1; cont <= animations_number; cont++){
        string.append("_" + std::to_string(cont) + ".gif"); //Se le agrega al string auxiliar el numero de animacion y la extension del archivo.
        movies.push_back(new QMovie(string)); //Se inicializa una nueva QMovie y se agrega al vector de movies.
        movies[movies.size() - 1] -> start(); //Se reproduce la QMovie recientemente agregada.
        string = file_prefix;  //Se inicializa de nuevo un string auxiliar.
    }
    main_label->setMovie(movies[0]); //Se le da el primer QMovie al label.
}

void animations::setup_label(unsigned short max_pixels)
{
    main_label->setFixedSize(max_pixels,max_pixels); //Ajusta el tamaño del label
    main_label->setScaledContents(true); //Estala los contenidos que tenga el label.
    main_label->setStyleSheet("background-color: transparent;"); //Pone el fondo del label transparente.
}

void animations::dispose_movies()
{
    for(short cont = movies.size() -1; cont >= 0; cont--){
        movies[cont]->stop(); //Detiene la QMovie en el indice del vector que indique el contador.
        delete movies[cont]; //Libera la memoria de tal QMovie.
    }
    movies.clear(); //Limpia el vector.
}



QLabel *animations::getMain_label()
{
    return main_label;
}


void animations::set_animation(unsigned short animation_number)
{
    main_label -> setMovie(movies[animation_number]);
}


