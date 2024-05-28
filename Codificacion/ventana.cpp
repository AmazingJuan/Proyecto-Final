#include "ventana.h"
#include "reglas_juego.h"

ventana::ventana(QWidget *parent)
    : QMainWindow(parent), menuNuevoWidget(0), menuCargarWidget(0)
{
    menuNuevoWidget = new QWidget(this);
    menuNuevo.setupUi(menuNuevoWidget);
    menuCargarWidget = new QWidget(this);
    menuNuevo.setupUi(menuCargarWidget);
    setup_game_rules();
}


ventana::~ventana()
{
    delete menuNuevoWidget;
    delete menuCargarWidget;
}


void ventana::setup_game_rules()
{
    /*
    buttons.push_back(ui -> B_salir);

    buttons.push_back(ui -> B_iniciar);
    buttons.push_back(ui -> B_cargar);
    connect(ui -> B_salir, SIGNAL(clicked(bool)), game, SLOT(salir()));
    connect(ui -> B_cargar, SIGNAL(clicked(bool)), game, SLOT(salir()));
    connect(ui -> B_iniciar, SIGNAL(clicked(bool)), game, SLOT(salir()));
    */
    game = new reglas_juego(ui -> graphicsView);

}
