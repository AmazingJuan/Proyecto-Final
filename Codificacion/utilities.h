#ifndef UTILITIES_H
#define UTILITIES_H

#include <QGraphicsScene>
#include <QString>
#include <QVector>
#include <QLabel>
#include <QMediaPlayer>
#include <QAudioOutput>

void show_image(QGraphicsScene *scene, QString url, QVector<QLabel *> &images);
unsigned short random_short(unsigned short begin, unsigned short end);
bool random_bool();
float calculate_distance(QPointF pos1, QPointF pos2);
bool is_numeric(QString text);
void play_music(QString route, QMediaPlayer *reproductor, QAudioOutput *output, bool is_obs);

#endif // UTILITIES_H
