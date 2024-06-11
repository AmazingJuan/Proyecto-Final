#ifndef UTILITIES_H
#define UTILITIES_H

#include <QGraphicsScene>
#include <QString>
#include <QMediaPlayer>
#include <QAudioOutput>

void show_image(QGraphicsScene *scene, QString url);
unsigned short random_short(unsigned short begin, unsigned short end, unsigned int seed);
bool random_bool(unsigned int seed);
float calculate_distance(QPointF pos1, QPointF pos2);
bool is_numeric(QString text);
void play_music(QString route, QMediaPlayer *reproductor, QAudioOutput *output, bool is_obs);

#endif // UTILITIES_H
