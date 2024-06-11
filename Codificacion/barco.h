#ifndef BARCO_H
#define BARCO_H

#include <QGraphicsProxyWidget>
#include <QObject>

#include "animations.h"
#include "fisicas.h"

#define ship_animations_number 3
#define file_prefix "ship"
class barco : public QGraphicsProxyWidget, public fisicas
{
    Q_OBJECT
public:
    barco(unsigned short level, unsigned short hp, int pos_x, int pos_y);
    ~barco();
    void move(int key);
    animations *getShip_animations();
    unsigned short getMoney() const;
    void addMoney(unsigned short newMoney);
    void setMoney(unsigned short money);
    unsigned short getLevel() const;
    void setLevel(unsigned short newLevel);
    void level_up(unsigned short level);
    void stop_movement();
    unsigned short getHp() const;
    void setHp(unsigned short newHp);

private:
    int actual_animation;
    unsigned int money;
    unsigned  short level;
    unsigned short hp;
    float previous_speed;
    animations *ship_animations;
    QTimer *crash_timer;
    QTimer *shm_timer;
    QTimer *mcu_timer;
private slots:
    void crash_timeout();
    void shm_timeout();
    void mcu_timeout();
signals:
    void ask_move(QPoint future_pos, QGraphicsProxyWidget *widget, bool crash_happening);
    void crash_management();
    void mcu_finished();
public slots:
    void start_crash(float speed);
    void start_shm();
    void start_mcu();

};

#endif // BARCO_H
