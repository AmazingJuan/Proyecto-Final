#include "imagenes.h"

void show_image(QGraphicsScene *scene, QString url){
    QPixmap imagen(url);
    scene -> addPixmap(imagen);
}
