#include <QFontDatabase>
#include <QMessageBox>
#include "ventana.h"
#include "reglas_juego.h"

ventana::ventana(QWidget *parent)
    : QMainWindow(parent)
{
    menu_nuevo_widget = new QWidget(this);
    menu_cargar_widget = new QWidget(this);
    middle_message_widget = new QWidget(this);
    stages_widget = new QWidget(this);
    menu_compra_widget = new QWidget(this);

    menu_nuevo.setupUi(menu_nuevo_widget);
    menu_cargar.setupUi(menu_cargar_widget);
    middle_message.setupUi(middle_message_widget);
    stages.setupUi(stages_widget);
    menu_compra.setupUi(menu_compra_widget);


    widgets.push_back(menu_nuevo_widget);
    widgets.push_back(menu_cargar_widget);
    widgets.push_back(middle_message_widget);
    widgets.push_back(stages_widget);
    widgets.push_back(menu_compra_widget);

    labels.push_back(middle_message.L_message);
    labels.push_back(menu_compra.L_1);
    labels.push_back(menu_compra.L_2);
    labels.push_back(menu_compra.L_3);
    labels.push_back(menu_compra.L_C);
    labels.push_back(stages.L_hp);
    labels.push_back(stages.L_time);

    shop_buttons.push_back(menu_compra.B_1);
    shop_buttons.push_back(menu_compra.B_2);
    shop_buttons.push_back(menu_compra.B_3);

    hideable_buttons.push_back(middle_message.B_salir);
    middle_message.B_salir -> setVisible(false);

    hide_widget(0);
    hide_widget(1);
    hide_widget(2);
    hide_widget(3);
    hide_widget(4);
    setup_game_rules();
    setup_font();
}



ventana::~ventana()
{
    delete game;
    delete menu_nuevo_widget;
    delete menu_cargar_widget;
}

void ventana::configure_graphics(QGraphicsView *graph)
{
    graph->setInteractive(false);
    graph->setFixedSize(700,700);
    graph->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    graph->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    graph->horizontalScrollBar()->setEnabled(false);
}

void ventana::keyPressEvent(QKeyEvent *event)
{
    game -> key_pressed(event->key());
}


void ventana::setup_game_rules()
{
    forms.push_back(menu_nuevo.graphicsView);
    configure_graphics(menu_nuevo.graphicsView);
    forms.push_back(menu_cargar.graphicsView);
    configure_graphics(menu_cargar.graphicsView);
    forms.push_back(middle_message.graphicsView);
    configure_graphics(middle_message.graphicsView);
    forms.push_back(stages.graphicsView);
    configure_graphics(stages.graphicsView);
    forms.push_back(menu_compra.graphicsView);
    configure_graphics(menu_compra.graphicsView);
    partidas = new partida(savegame_route);
    game = new reglas_juego(forms, shop_buttons, partidas);
    conexiones();
    setup_buttons();
    game -> setup();

}

void ventana::setup_font()
{
    int id = QFontDatabase::addApplicationFont(":/fuentes/Fuentes/pirata.ttf");
    QString stringAux = QFontDatabase::applicationFontFamilies(id).at(0);
    font = QFont(stringAux, 20);
}

void ventana::conexiones()
{
    connect(game, &reglas_juego::hide_screen, this, &ventana::hide_widget);
    connect(game, &reglas_juego::show_screen, this, &ventana::show_widget);
    connect(game, &reglas_juego::shoot_label_change, this, &ventana::change_label_text);
    connect(menu_nuevo.B_salir, &QPushButton::clicked, this, &ventana::close_window);
    connect(menu_cargar.B_salir, &QPushButton::clicked, this, &ventana::close_window);
    connect(menu_cargar.B_iniciar, &QPushButton::clicked, partidas, &partida::forbid_file_load);
    connect(menu_cargar.B_iniciar, &QPushButton::clicked, game, &reglas_juego::start_game);
    connect(menu_nuevo.B_iniciar, &QPushButton::clicked, partidas, &partida::forbid_file_load);
    connect(menu_nuevo.B_iniciar, &QPushButton::clicked, game, &reglas_juego::start_game);
    connect(menu_cargar.B_cargar, &QPushButton::clicked, partidas, &partida::allow_file_load);
    connect(menu_cargar.B_cargar, &QPushButton::clicked, game, &reglas_juego::start_game);
    connect(menu_compra.B_salir, &QPushButton::clicked, this, &ventana::close_window);
    connect(menu_compra.B_1, &QPushButton::clicked, game, &reglas_juego::manage_shop_buttons);
    connect(menu_compra.B_2, &QPushButton::clicked, game, &reglas_juego::manage_shop_buttons);
    connect(menu_compra.B_3, &QPushButton::clicked, game, &reglas_juego::manage_shop_buttons);
    connect(middle_message.B_salir, &QPushButton::clicked, this, &ventana::close_window);
    connect(game, &reglas_juego::shoot_button_change, this, &ventana::change_button_visibility);
    connect(partidas, &partida::error_occurred, this, [](const QString &errorMessage) {
        QMessageBox::critical(nullptr, "Error", errorMessage);
    });
}

void ventana::setup_buttons()
{
    menu_nuevo.B_iniciar->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    menu_nuevo.B_salir->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    menu_cargar.B_cargar->setStyleSheet("background-color: rgba(255, 255, 255, 0);");

    menu_cargar.B_iniciar->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    menu_cargar.B_salir->setStyleSheet("background-color: rgba(255, 255, 255, 0);");

    menu_compra.B_1->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    menu_compra.B_2->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    menu_compra.B_3->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    menu_compra.B_salir->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    middle_message.B_salir->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
}

void ventana::wheelEvent(QWheelEvent *event)
{
    event->ignore();
}

void ventana::close_window()
{
    close();
}

void ventana::change_label_text(unsigned short label_index, QString text, bool is_aligned)
{
    labels[label_index] -> setText(text);
    labels[label_index] -> setFont(font);
    if(label_index == 0) labels[label_index] -> setStyleSheet("QLabel { color : white; }");
    else labels[label_index] -> setStyleSheet("QLabel { color : black; }");
    if(is_aligned) labels[label_index]->setAlignment(Qt::AlignCenter);
}

void ventana::change_button_visibility(unsigned short button)
{
    bool aux = hideable_buttons[button] -> isVisible();
    hideable_buttons[button] -> setVisible(!aux);
}

void ventana::hide_widget(int number)
{
    widgets[number] ->  setVisible(false);
}

void ventana::show_widget(int number)
{
    widgets[number] ->  setVisible(true);
}


