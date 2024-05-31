#include "imagenes.h"
#include <QLabel>

void show_image(QGraphicsScene *scene, QString url){
    QLabel * label = new QLabel;
    QPixmap imagen(url);
    label -> setPixmap(imagen);
    label -> setFixedSize(700,700);
    label->setScaledContents(true);
    scene -> addWidget(label);
}
