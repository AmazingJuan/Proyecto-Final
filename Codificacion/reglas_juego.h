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
#include <QAudioOutput>

#include "barco.h"
#include "obstaculo.h"
#include "partida.h"

#define game_duration 60
#define main_menu_scene 0
#define main_menu_load_scene 1
#define middle_message_scene 2
#define max_x 7
#define max_y 7
#define max_money_per_coin 150
#define min_money_per_coin 50
#define stage_1 "En el inicio de su viaje,\nCristóbal Colón y su tripulación\nhicieron una parada estratégica\nen las Islas Canarias. Este\narchipiélago fue el último punto\nde abastecimiento antes de\nadentrarse en el vasto océano\nAtlántico, donde comenzaron\nsu audaz travesía hacia\nlo desconocido."
#define stage_2 "Después de semanas de\nnavegación, Colón llegó a\nlas Islas del Caribe, marcando\nun hito monumental en la historia.\nEste encuentro inicial con el\nNuevo Mundo reveló tierras\nexuberantes y culturas desconocidas,\nexpandiendo el horizonte de\nla exploración europea."
#define stage_3 "Finalmente, el viaje de\ndescubrimiento culminó en el\narchipiélago de las Bahamas.\nEl 12 de octubre de 1492, Colón\ndesembarcó en una de estas islas,\na la que llamó San Salvador.\nEste evento histórico señaló el\nprimer contacto europeo con el\ncontinente americano, cambiando\npara siempre el curso de la\nhistoria mundial."


class reglas_juego : public QObject
{
    Q_OBJECT
public:
    reglas_juego(QVector<QGraphicsView *> &graphics, QVector<QPushButton *> &shop_buttons, partida *partida);
    ~reglas_juego();
    void setup();
    void key_pressed(int key);
private:
    QVector<QLabel *> labels;
    QVector<QPushButton *> shop_buttons;
    QVector<QGraphicsView *> interfaces;
    QVector<QGraphicsScene *> scenes;

    partida *saves;

    QTimer *game_timer;
    QTimer *change_scene_timer;
    QTimer *dispatch_obstacles_timer;
    QTimer *wave_timer;

    unsigned short current_scene;
    unsigned short in_scene_obstacles;
    unsigned short next_scene;
    unsigned short current_stage;
    unsigned short random_int_range;
    unsigned short game_time_counter;

    unsigned int seed;
    unsigned int shop_prices[3];

    bool twister_death;

    QMediaPlayer *reproductor;

    QAudioOutput *output;

    barco *ship;



    QVector<obstaculo*> moving_obstacles;
    QVector<obstaculo*> removed_obstacles;
    QVector<obstaculo*> shop_obstacles;
    QVector<QString> stage_messages;

    void initial_conections();
    void stage_connections();
    void obstacle_connections(obstaculo *obstacle);
    bool is_colliding(QGraphicsProxyWidget *widget);
    void dispose_obstacles();
    void dispose_removed_obstacles();
    void dispose_shop_obstacles();
    void setup_obstacles();
    void setup_stage();
    void setup_scene(QGraphicsScene *scene);
    void setup_shop();
    void switch_scenes();
    void main_menu();
    void main_menu_load();
    void show_middle_message(QString text);
    void handle_menu_compra();
    void update_shop(unsigned short blocked_buttons);
    void handle_end_stage();
    void gameover();
    void win();
    void stop_game();
public slots:
    void loadMenu(bool dato);
    void try_move(QPoint future_pos, QGraphicsProxyWidget *widget, bool crash_happening);
    void dispatch_obstacles();
    void wave_event();
    void outside_removal(obstaculo *obs);
    void change_scene();
    void timer_changed();
    void handle_mcu_finish();
    void manage_shop_buttons();
    void start_game();
    void cargar();
signals:
    void crash(QGraphicsProxyWidget *widget);
    void shm();
    void mcu();
    void crash_ship(float speed);
    void change_speed(short direction);
    void crear_archivo();
    void hide_screen(unsigned short screen);
    void show_screen(unsigned short  screen);
    void hide_button(unsigned short button);
    void shoot_label_change(unsigned short label_index, QString new_text, bool is_aligned);
    void shoot_button_change(unsigned short button_index);
    void deletion();
};

#endif // REGLAS_JUEGO_H
