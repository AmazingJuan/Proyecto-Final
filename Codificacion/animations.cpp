#include "animations.h"

animations::animations(QString file_prefix, int number_animations, unsigned short max_pixels)
{
    main_label = new QLabel;
    this -> max_pixels = max_pixels;
    setup_label(max_pixels);
    this -> file_prefix = file_path + file_prefix;
    animations_number = number_animations;
    initialize_movies();
}

animations::animations(QString route, unsigned short max_pixels)
{
    main_label = new QLabel;
    this -> max_pixels = max_pixels;
    setup_label(max_pixels);
    animations_number = 1;
    movies.push_back(new QMovie(route));
    movies[0]->start();
    main_label->setMovie(movies[0]);
}

animations::~animations()
{
    for(int cont = movies.size() - 1; cont >= 0; cont--) {
        delete movies[cont];
        movies.remove(cont);
    }
    delete main_label;
}

QLabel *animations::getMain_label()
{
    return main_label;
}

void animations::change_animations(QString file_prefix, int number_animations)
{
    this -> file_prefix = file_path + file_prefix;
    main_label -> setMovie(nullptr);
    dispose_movies();
    animations_number = number_animations;
    initialize_movies();
}

void animations::set_animation(unsigned short animation_number)
{
    main_label -> setMovie(movies[animation_number]);
}

void animations::initialize_movies()
{
    QMovie *aux = nullptr;
    QString string = file_prefix;
    for(int cont = 1; cont <= animations_number; cont++){
        string.append("_" + std::to_string(cont) + ".gif");
        aux = new QMovie(string);
        aux -> start();
        movies.push_back(aux);
        string = file_prefix;
    }
    main_label->setMovie(movies[0]);
}

void animations::setup_label(unsigned short max_pixels)
{
    main_label->setFixedSize(max_pixels,max_pixels);
    main_label->setScaledContents(true);
    main_label->setStyleSheet("background-color: transparent;");
}

void animations::dispose_movies()
{
    for(short cont = movies.size() -1; cont >= 0; cont--){
        movies[cont]->stop();
        delete movies[cont];
        movies.removeOne(movies[cont]);
    }
}
