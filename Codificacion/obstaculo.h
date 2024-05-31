#ifndef OBSTACULO_H
#define OBSTACULO_H


#include <QLabel>
#include <QTimer>
#include <QObject>

#include "animations.h"
#include "fisicas.h"

#define file_prefix ":/gifs/Gifs/obstacle"
class obstaculo : public QGraphicsProxyWidget, public fisicas
{
    Q_OBJECT
public:
    obstaculo(unsigned short obs_number, float ship_mass);
    void move(int direction);
    animations *getObstacle_animations();
private:

    animations *obstacle_animations;
    QTimer *movement_timer;
    QTimer *crash_timer;
private slots:
    void handle_timeout();
    void crash_timeout();
public slots:
    void start_crash(QGraphicsProxyWidget *widget);
signals:
    void crash_management();
    void ask_move(QPoint future_pos, QGraphicsProxyWidget *widget, bool crash_happening);
};

#endif // OBSTACULO_H
