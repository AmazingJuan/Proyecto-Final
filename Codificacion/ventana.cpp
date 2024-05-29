#include <QFontDatabase>
#include "ventana.h"
#include "reglas_juego.h"

ventana::ventana(QWidget *parent)
    : QMainWindow(parent), menu_nuevo_widget(0), menu_cargar_widget(0), middle_message_widget(0)
{
    menu_nuevo_widget = new QWidget(this);
    menu_cargar_widget = new QWidget(this);
    middle_message_widget = new QWidget(this);

    menu_nuevo.setupUi(menu_nuevo_widget);
    menu_cargar.setupUi(menu_cargar_widget);
    middle_message.setupUi(middle_message_widget);


    widgets.push_back(menu_nuevo_widget);
    widgets.push_back(menu_cargar_widget);
    widgets.push_back(middle_message_widget);

    buttons.push_back(menu_nuevo.B_iniciar);
    buttons.push_back(menu_nuevo.B_salir);
    buttons.push_back(menu_cargar.B_iniciar);
    buttons.push_back(menu_cargar.B_cargar);
    buttons.push_back(menu_cargar.B_salir);

    labels.push_back(middle_message.L_message);


    hide_widget(0);
    hide_widget(1);
    hide_widget(2);
    setup_game_rules();
    setup_font();
}



ventana::~ventana()
{
    delete menu_nuevo_widget;
    delete menu_cargar_widget;
}


void ventana::setup_game_rules()
{
    forms.push_back(menu_nuevo.graphicsView);
    forms.push_back(menu_cargar.graphicsView);
    forms.push_back(middle_message.graphicsView);

    game = new reglas_juego(forms);
    conexiones();
    game -> setup();
}

void ventana::setup_font()
{
    int id = QFontDatabase::addApplicationFont(":/fuentes/Fuentes/pirata.ttf");
    QString stringAux = QFontDatabase::applicationFontFamilies(id).at(0);
    font = QFont(stringAux, 25);
}

void ventana::conexiones()
{
    connect(game, &reglas_juego::hide_screen, this, &ventana::hide_widget);
    connect(game, &reglas_juego::show_screen, this, &ventana::show_widget);
    connect(game, SIGNAL(shoot_label_change(int, QString)), this, SLOT(change_label_text(int, QString)));
    connect(menu_nuevo.B_salir, SIGNAL(clicked(bool)), this, SLOT(close_window()));
    connect(menu_cargar.B_salir, SIGNAL(clicked(bool)), this, SLOT(close_window()));
    connect(menu_cargar.B_iniciar, SIGNAL(clicked(bool)), game, SLOT(iniciar()));
    connect(menu_nuevo.B_iniciar, SIGNAL(clicked(bool)), game, SLOT(iniciar()));
}

void ventana::close_window()
{
    close();
}

void ventana::change_label_text(int label_index, QString text)
{
    labels[label_index] -> setText(text);
    labels[label_index] -> setFont(font);
    labels[label_index] -> setStyleSheet("QLabel { color : white; }");

}

void ventana::hide_widget(int number)
{
    //widgets[number] ->  setFixedSize(this -> size());
    widgets[number] ->  setVisible(false);
}

void ventana::show_widget(int number)
{
   // widgets[number] ->  setFixedSize(this -> size());
    widgets[number] ->  setVisible(true);
}


