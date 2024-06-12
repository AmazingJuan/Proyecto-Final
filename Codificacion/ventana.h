#ifndef VENTANA_H
#define VENTANA_H

#include <QMainWindow>
#include <QScrollBar>
#include "reglas_juego.h"
#include "ui_Menu1.h"
#include "ui_Menu2.h"
#include "ui_Stage.h"
#include "ui_MenuCompra.h"
#include "ui_MiddleMessage.h"

#define custom_size 26;
#define savegame_route "Savedata.txt"

class ventana : public QMainWindow
{
    Q_OBJECT
public:
    ventana(QWidget *parent = nullptr);
    ~ventana();

private:
    //INSTANCIAS EN PILA UI.
    Ui::Menu1 menu_nuevo;
    Ui::Menu2 menu_cargar;
    Ui::Stage stages;
    Ui::MenuCompra menu_compra;
    Ui::MiddleMessage middle_message;

    //WIDGETS EN HEAP.
    QWidget *menu_nuevo_widget;
    QWidget *menu_cargar_widget;
    QWidget *middle_message_widget;
    QWidget *stages_widget;
    QWidget *menu_compra_widget;

    //VECTORES DERIVADOS DE LOS WIDGET, SE BORRAN CUANDO BORRO EL WIDGET.
    QVector<QGraphicsView *> forms;
    QVector<QLabel *> labels;
    QVector<QPushButton *> shop_buttons;
    QVector<QPushButton *> hideable_buttons;
    QVector<QWidget *> widgets;

    //INSTANCIA DE REGLAS DE JUEGO.
    reglas_juego *game;

    QFont font;

    //PARTIDA GUARDADA
    partida *partidas;

    void configure_graphics(QGraphicsView *graph);
    void keyPressEvent(QKeyEvent *event) override;
    void setup_game_rules();
    void setup_font();
    void conexiones();
    void setup_buttons();
    void dispose_widgets();
private slots:
    void close_window();
    void change_label_text(unsigned short label_index, QString text, bool is_aligned);
    void enable_button_visibility(unsigned short button);
    void hide_widget(unsigned short number);
    void show_widget(unsigned short number);
};

#endif // VENTANA_H

