#include "animations.h"

animations::animations(QString file_prefix, int number_animations)
{
    main_label = new QLabel;
    setup_label();
    this -> file_prefix = file_path + file_prefix;
    animations_number = number_animations;
    initialize_movies();







}

animations::animations(QString route)
{
    main_label = new QLabel;
    setup_label();
    animations_number = 1;
    movies.push_back(new QMovie(route));
    movies[0]->start();
    main_label->setMovie(movies[0]);
}

animations::~animations()
{
    delete main_label;
}

QLabel *animations::getMain_label()
{
    return main_label;
}

void animations::set_animation(unsigned short animation_number)
{
    main_label -> setMovie(movies[animation_number]);
}

void animations::initialize_movies()
{
    QMovie *aux = nullptr;
    QString string = file_prefix;
    for(int cont = 0; cont < animations_number; cont++){
        string.append("_" + std::to_string(cont+1) + ".gif");
        aux = new QMovie(string);
        aux -> start();
        movies.push_back(aux);
        string = file_prefix;
    }
}

void animations::setup_label()
{
    main_label->setFixedSize(100,100);
    main_label -> setVisible(true);
    main_label->setScaledContents(true);
    main_label -> setVisible(true);
    main_label->setStyleSheet("background-color: transparent;");
}

void animations::setWidget(QGraphicsProxyWidget *widget)
{
    this ->widget = widget;
}

QGraphicsProxyWidget *animations::getWidget()
{
    return widget;
}
