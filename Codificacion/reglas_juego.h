 #ifndef REGLAS_JUEGO_H
#define REGLAS_JUEGO_H

#include <QPushButton>
#include <QWidget>
#include <QVector>
#include <QLabel>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include <QMediaPlayer>


#include "barco.h"
#include "obstaculo.h"
#include "partidas.h"

#define main_menu_scene 0
#define main_menu_load_scene 1
#define middle_message_scene 2
#define max_x 7
#define max_y 7
#define max_money_per_coin 150
#define min_money_per_coin 50

#define savegame_route "../Codificacion/Savedata/savegame.txt"

class reglas_juego : public QObject
{
    Q_OBJECT
public:
    reglas_juego(QVector<QGraphicsView *> &graphics, QVector<QPushButton *> &shop_buttons);
    ~reglas_juego();
    void setup();
    void key_pressed(int key);
private:
    QVector<QLabel *> labels;
    QVector<QPushButton *> shop_buttons;
    QVector<QGraphicsView *> interfaces;
    QVector<QGraphicsScene *> scenes;

    partidas *saves;

    QTimer *game_timer;
    QTimer *change_scene_timer;
    QTimer *dispatch_obstacles_timer;

    unsigned short current_scene;
    unsigned short in_scene_obstacles;
    unsigned short next_scene;
    unsigned short current_stage;
    unsigned short random_int_range;

    unsigned int seed;
    unsigned int shop_prices[3];

    QMediaPlayer *reproductor;

    barco *ship;
    QVector<obstaculo*> active_obstacles;
    QVector<obstaculo*> moving_obstacles;
    QVector<obstaculo*> removed_obstacles;
    QVector<obstaculo*> shop_obstacles;

    void initial_conections();
    void stage_connections();
    void obstacle_connections(obstaculo *obstacle);
    bool is_colliding(QGraphicsProxyWidget *widget);
    bool is_outside_scene(QGraphicsProxyWidget *widget);
    void dispose_obstacles();
    void dispose_removed_obstacles();
    void setup_obstacles();
    void setup_stage();
    void setup_scene(QGraphicsScene *scene);
    void setup_shop();
    void switch_scenes();
    void main_menu();
    void main_menu_load();
    void show_middle_message(QString text);
    void hide_buttons(QVector<QPushButton *> &buttons);
    void show_buttons(QVector<QPushButton *> &buttons);
    void handle_menu_compra();
    void update_shop(unsigned short blocked_buttons);
private slots:
    void loadMenu(bool dato);
    void try_move(QPoint future_pos, QGraphicsProxyWidget *widget, bool crash_happening);
    void dispatch_obstacles();
    void handle_end_stage();
    void outside_removal(obstaculo *obs);
    void change_scene();
public slots:
    void manage_shop_buttons();
    void iniciar();
    void cargar();
signals:
    void crash(QGraphicsProxyWidget *widget);
    void crash_ship(float speed);
    void change_speed(short direction);
    void crear_archivo();
    void hide_screen(int screen);
    void show_screen(int screen);
    void shoot_label_change(int label_index, QString new_text, bool is_aligned);
    void deletion();
};

#endif // REGLAS_JUEGO_H
