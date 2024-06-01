#ifndef FISICAS_H
#define FISICAS_H

#include <QGraphicsProxyWidget>
#include <QObject>
#include <QTimer>
#include <QPoint>

#define sampling_time 25
class fisicas
{
public:
    static const int SPEED_MAX = 6;
    static const int SPEED_MIN = 1;
    static const int DEFAULT_SPEED = 2;
    fisicas(int pos_x, int pos_y, float mass);
    float mru(short direction);
    float trabajo(float net_force);
    float getSpeed() const;
    void setSpeed(qreal newSpeed);

    float getPos_x() const;
    void setPos_x(float newPos_x);

    float getPos_y() const;
    void setPos_y(float newPos_y);

    float getMass() const;
    void setMass(float newMass);

protected:
    float pos_x;
    float pos_y;
    float mass;
    float speed;
    bool crash_happening;
    unsigned short crash_counter;
private:
    qreal max_speed;
    qreal min_speed;
};


#endif // FISICAS_H
