#include "utilities.h"
#include <QLabel>
#include <random>


void show_image(QGraphicsScene *scene, QString url){
    QLabel * label = new QLabel;
    QPixmap imagen(url);
    label -> setPixmap(imagen);
    label -> setFixedSize(700,700);
    label->setScaledContents(true);
    scene -> addWidget(label);
}

unsigned short random_short(unsigned short begin, unsigned short end, unsigned int seed)
{
    std::default_random_engine engine(seed);
    std::uniform_int_distribution<int> distribution(begin, end);
    return distribution(engine);
}

bool random_bool(unsigned int seed){
    return random_short(0,1, seed);
}
