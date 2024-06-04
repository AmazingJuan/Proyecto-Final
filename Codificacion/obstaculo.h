#ifndef OBSTACULO_H
#define OBSTACULO_H


#include <QLabel>
#include <QTimer>
#include <QObject>

#include "animations.h"
#include "fisicas.h"

#define prefix ":/gifs/Gifs/obstacle"
class obstaculo : public QGraphicsProxyWidget, public fisicas
{
    Q_OBJECT
public:
    obstaculo(unsigned short obs_number, float ship_mass, float ship_force, unsigned short max_pixels);
    ~obstaculo();
    void move(int direction);
    animations *getObstacle_animations();
    bool getIs_dangerous() const;
    void setIs_dangerous(bool newIs_dangerous);
    void start_movement();
    void stop_movement();
    bool getIs_out_scene() const;
    void setIs_out_scene(bool newIs_out_scene);

private:
    bool is_dangerous;
    bool is_out_scene;
    animations *obstacle_animations;
    QTimer *movement_timer;
    QTimer *crash_timer;
private slots:
    void handle_timeout();
    void crash_timeout();
public slots:
    void start_crash(QGraphicsProxyWidget *widget);
    void change_speed(short direction);
signals:
    void collect_coin();
    void surpassed_limit(obstaculo *obs);
    void crash_management();
    void ask_move(QPoint future_pos, QGraphicsProxyWidget *widget, bool crash_happening);
};

#endif // OBSTACULO_H
