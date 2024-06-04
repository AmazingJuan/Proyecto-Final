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
    fisicas(int pos_x, int pos_y, float mass, float ship_force);
    float mru(short direction);
    float trabajo(short direction);
    float shm_x(unsigned int actual_time);

    float getSpeed() const;
    void setSpeed(qreal newSpeed);

    float getPos_x() const;
    void setPos_x(float newPos_x);

    float getPos_y() const;
    void setPos_y(float newPos_y);

    float getMass() const;
    void setMass(float newMass);

    float getShip_force() const;
    void setShip_force(float newShip_force);

protected:
    float SPEED_MAX = 4;
    float SPEED_MIN = 1;
    float DEFAULT_SPEED = 2;
    float pos_x;
    float pos_y;
    float mass;
    float speed;
    float ship_force;
    float angular_speed;
    float initial_shm_x;
    float amplitude;
    float angular_velocity;
    bool crash_happening;
    unsigned short crash_counter;
private:
    qreal max_speed;
    qreal min_speed;
};


#endif // FISICAS_H
