#include "utilities.h"
#include <QGraphicsProxyWidget>
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

float calculate_distance(QPointF pos1, QPointF pos2){
    float dist_x = pos1.x() - pos2.x();
    float dist_y = pos1.y() - pos2.y();
    return sqrt((dist_x*dist_x) + (dist_y * dist_y));
}

bool is_numeric(QString text){
    for (QChar c : text) {
        if (!c.isDigit()) {
            return false;
        }
    }
    return true;
}

void play_music(QString route, QMediaPlayer *reproductor, QAudioOutput *output, bool is_obs)
{
    reproductor -> stop();
    reproductor-> setSource(QUrl(route));
    if(!is_obs) reproductor -> setLoops(QMediaPlayer::Infinite);
    output->setVolume(0.2f);
    reproductor -> play();
}
