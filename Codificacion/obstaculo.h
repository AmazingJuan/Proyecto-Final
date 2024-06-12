#ifndef OBSTACULO_H
#define OBSTACULO_H


#include <QLabel>
#include <QTimer>
#include <QObject>
#include <QMediaPlayer>
#include <QAudioOutput>

#include "animations.h"
#include "fisicas.h"

#define prefix ":/gifs/Gifs/obstacle"
class obstaculo : public QGraphicsProxyWidget, public fisicas
{
    Q_OBJECT
public:
    obstaculo(unsigned short obs_number, float ship_mass, float ship_force, unsigned short max_pixels, unsigned short SPEED_MAX);
    ~obstaculo();

    QMediaPlayer *reproductor;
    QAudioOutput *output;

    //GETTERS Y SETTERS.
    animations *getObstacle_animations();
    bool getIs_dangerous() const;
    void setIs_dangerous(bool newIs_dangerous);
    bool getIs_out_scene() const;
    void setIs_out_scene(bool newIs_out_scene);
    bool getIs_twister() const;
    void setIs_twister(bool newIs_twister);
    unsigned short getIssued_damage() const;
    void setIssued_damage(unsigned short newIssued_damage);

    void play_own_music();
    void start_movement();
    void stop_movement();
private:
    //VARIABLES DE ESTADO
    bool is_dangerous;
    bool is_twister;
    unsigned short issued_damage;

    animations *obstacle_animations;

    //TIMERS FISICOS
    QTimer *movement_timer;
    QTimer *crash_timer;

    //AUDIO
    QString audio_route;
    void determine_audio_route(unsigned short obs_number);
private slots:
    //SLOTS FISICOS
    void handle_timeout();
    void crash_timeout();
public slots:
    //SLOTS FISICOS
    void start_crash(QGraphicsProxyWidget *widget);
    void change_speed(short direction);
signals:
    void surpassed_limit(obstaculo *obs);
    void ask_move(QPoint future_pos, QGraphicsProxyWidget *widget, bool crash_happening);
};
#endif // OBSTACULO_H
