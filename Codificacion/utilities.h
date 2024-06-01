#ifndef UTILITIES_H
#define UTILITIES_H

#include <QGraphicsScene>
#include <QString>

void show_image(QGraphicsScene *scene, QString url);
unsigned short random_short(unsigned short begin, unsigned short end, unsigned int seed);
bool random_bool(unsigned int seed);

#endif // UTILITIES_H
