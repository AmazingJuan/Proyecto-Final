#ifndef VENTANA_H
#define VENTANA_H

#include <QMainWindow>
#include "reglas_juego.h"
#include "ui_Menu1.h"
#include "ui_Menu2.h"
#include "ui_Stage.h"
#include "ui_MenuCompra.h"
#include "ui_MiddleMessage.h"

#define custom_size 26;

class ventana : public QMainWindow
{
    Q_OBJECT
public:
    ventana(QWidget *parent = nullptr);
    ~ventana();

private:
    Ui::Menu1 menu_nuevo;
    Ui::Menu2 menu_cargar;
    Ui::Stage stages;
    Ui::MenuCompra menu_compra;
    Ui::MiddleMessage middle_message;

    QWidget *menu_nuevo_widget;
    QWidget *menu_cargar_widget;
    QWidget *middle_message_widget;
    QWidget *stages_widget;

    QVector<QGraphicsView *> forms;
    QVector<QLabel *> labels;
    QVector<QPushButton *> buttons;
    QVector<QWidget *> widgets;
    reglas_juego *game;

    QFont font;

    void keyPressEvent(QKeyEvent *event);
    void setup_game_rules();
    void setup_font();
    void conexiones();
private slots:
    void close_window();
    void change_label_text(int label_index, QString text);
    void hide_widget(int number);
    void show_widget(int number);
};

#endif // VENTANA_H

