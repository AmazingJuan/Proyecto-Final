#include "utilities.h"
#include <QGraphicsProxyWidget>
#include <random>

void show_image(QGraphicsScene *scene, QString url, QVector<QLabel *> &images){
    QLabel * label = new QLabel; //Se aloja memoria para un nuevo QLabel
    images.push_back(label); //Se añade el label a el arreglo de labels que contienen imagenes.
    QPixmap imagen(url); //Se crea un pixmap con la ruta de la imagen especificada.
    label -> setPixmap(imagen); //Se establece la imagen al label
    label -> setFixedSize(700,700); //Se pone la imagen del tamaño de la ventana
    label->setScaledContents(true); //Se escala el contenido.
    scene -> addWidget(label) -> setZValue(-1); //Se pone el label al fondo de la escena.
}

unsigned short random_short(unsigned short begin, unsigned short end)
{
    if(begin == end) return begin; //Se devuelve el numero si es que el inicio y el final son iguales.
    std::random_device rd; //Se inicializa el generador de numeros aleatorios con una semilla "aleatoria"
    std::mt19937 gen(rd()); //Se inicializa el motor que generará el numero basado en el algoritmo mersene twister.
    std::uniform_int_distribution<> distr(begin, end); //Producción de numeros enteros en un rango uniforme de el numero 'begin' hasta el numero 'end'
    return distr(gen); //genera un numero aleatorio de la distribución
}

bool random_bool(){
    return random_short(0,1); //Devuelve un booleano aleatorio de 0 a 1.
}

float calculate_distance(QPointF pos1, QPointF pos2){
    //Utiliza el teorema de pitagorás para calcular la distancia.
    float dist_x = pos1.x() - pos2.x();
    float dist_y = pos1.y() - pos2.y();
    return sqrt((dist_x*dist_x) + (dist_y * dist_y));
}

bool is_numeric(QString text){
    //Verifica cada caracter del QString y revisa si es digito o no.
    for (QChar c : text) {
        if (!c.isDigit()) {
            return false;
        }
    }
    return true;
}

void play_music(QString route, QMediaPlayer *reproductor, QAudioOutput *output, bool is_obs)
{
    reproductor -> stop(); //Para el reproductor en el caso de que se este reproduciendo algun medio.
    reproductor-> setSource(QUrl(route)); //Establece un nuevo medio al reproductor.
    if(!is_obs) reproductor -> setLoops(QMediaPlayer::Infinite); //Si no es un obstaculo se establece un loop infinito.
    output->setVolume(0.2f); //Ajusta el volumen a uno moderado.
    reproductor -> play(); //Reproduce la musica.
}
