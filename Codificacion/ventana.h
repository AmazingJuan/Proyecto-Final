#ifndef VENTANA_H
#define VENTANA_H

#include <QMainWindow>
#include "reglas_juego.h"
#include "ui_Menu1.h"
#include "ui_Menu2.h"

class ventana : public QMainWindow
{
    Q_OBJECT
public:
    ventana(QWidget *parent = nullptr);
    ~ventana();

private:
    Ui::Menu1 menuNuevo;
    Ui::Menu2 menuCargar;
    QWidget *menuNuevoWidget;
    QWidget *menuCargarWidget;
    QVector<QWidget *> forms;
    reglas_juego *game;
    void setup_game_rules();
};

#endif // VENTANA_H

