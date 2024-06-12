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
    fisicas(int pos_x, int pos_y, float mass, float ship_force, unsigned short SPEED_MAX);
    float mru(short direction);
    float trabajo(short direction);
    float shm_x(unsigned int actual_time);
    QPoint mcu();

    float getSpeed() const;
    void setSpeed(float newSpeed);

    float getPos_x() const;
    void setPos_x(float newPos_x);

    float getPos_y() const;
    void setPos_y(float newPos_y);

    float getMass() const;
    void setMass(float newMass);

    float getShip_force() const;
    void setShip_force(float newShip_force);

    unsigned short getMax_speed() const;

protected:
    const float SPEED_MIN = 1;
    const float DEFAULT_SPEED = 2;
    unsigned short max_speed;

    //MAS
    float frequence = 0.05;
    double phase = M_PI / 2;
    float amplitude = 250;
    double initial_time;
    double initial_x;


    //MCU
    float center_x;
    float center_y;
    float angle = 0;
    float radius = 200;
    float mcu_speed = 1;


    //MRU / TRABAJO
    float pos_x;
    float pos_y;
    float mass;
    float speed;
    float ship_force;

    bool crash_happening;
    bool shm_happening;
    unsigned short crash_counter;
    unsigned short shm_counter;
    unsigned short mcu_counter;

    void calculate_initial_time();
private:
    unsigned short min_speed;
};


#endif // FISICAS_H
