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

#define game_scale_factor 2
#define main_menu_scene 0
#define main_menu_load_scene 1
#define middle_message_scene 2


#define savegame_route "../Codificacion/Savedata/savegame.txt"

class reglas_juego : public QObject
{
    Q_OBJECT
public:
    reglas_juego(QVector<QGraphicsView *> &graphics);
    ~reglas_juego();
    void setup();
    void key_pressed(int key);
private:
    QVector<QLabel *> labels;
    QVector<QPushButton *> buttons;
    QVector<QGraphicsView *> interfaces;
    QVector<QGraphicsScene *> scenes;

    partidas *saves;

    QTimer *time;
    QTimer *change_scene_timer;
    QTimer *events_timer;
    QTimer *collisions_timer;

    unsigned short current_scene;
    unsigned short next_scene;

    QMediaPlayer *reproductor;


    barco *ship;
    obstaculo *obstacle;
    bool crash_happening;

    void conexiones();
    bool is_colliding(QGraphicsProxyWidget *widget);
    void setup_stage();
    void setup_scene(QGraphicsScene *scene);
    void main_menu();
    void main_menu_load();
    void show_middle_message(QString text);
    void hide_buttons(QVector<QPushButton *> &buttons);
    void show_buttons(QVector<QPushButton *> &buttons);
private slots:
    void loadMenu(bool dato);
    void try_move(QPoint future_pos, QGraphicsProxyWidget *widget, bool crash_happening);

    void cargar();
    void salir();
    void iniciar();
    void change_scene();
signals:
    void crash(QGraphicsProxyWidget *widget);
    void crear_archivo();
    void hide_screen(int screen);
    void show_screen(int screen);
    void shoot_label_change(int label_index, QString new_text);
};

#endif // REGLAS_JUEGO_H
