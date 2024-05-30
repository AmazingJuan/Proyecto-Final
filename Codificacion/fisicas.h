#ifndef FISICAS_H
#define FISICAS_H

#include <QGraphicsProxyWidget>
#include <QObject>
#include <QTimer>
#include <QPoint>

#define sampling_time 500
class fisicas : public QObject
{
    Q_OBJECT
public:
    fisicas(int pos_x, int pos_y, float mass);
    float mru(short direction);
    float trabajo(int y_actual, float net_force);
    qreal getSpeed() const;
    void setSpeed(qreal newSpeed);

    float getPos_x() const;
    void setPos_x(float newPos_x);

    float getPos_y() const;
    void setPos_y(float newPos_y);

protected:
    float pos_x;
    float pos_y;
    qreal mass;
    float speed;
    QGraphicsProxyWidget *widget;
private:
    qreal max_speed;
    qreal min_speed;
};


#endif // FISICAS_H
