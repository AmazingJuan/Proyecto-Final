#include "utilities.h"
#include "qgraphicsproxywidget.h"
#include <QLabel>
#include <random>


void show_image(QGraphicsScene *scene, QString url){
    QLabel * label = new QLabel;
    QPixmap imagen(url);
    label -> setPixmap(imagen);
    label -> setFixedSize(700,700);
    label->setScaledContents(true);
    scene -> addWidget(label) -> setZValue(-1);
}

unsigned short random_short(unsigned short begin, unsigned short end, unsigned int seed)
{
    if(begin == end) return begin;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(begin, end);
    return distr(gen);
}

bool random_bool(unsigned int seed){
    return random_short(0,1, seed);
}
