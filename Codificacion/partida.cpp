#include <QTextStream>
#include "partida.h"
#include "utilities.h"

partida::partida(QString ruta) {
    nombreArchivo = ruta; //Establece el atributo nombre de archivo.
    wants_load = false; //Pone por defecto la variable de control "quiere cargar" como falsa.
    archivo.setFileName(nombreArchivo); //Settea el nombre del archivo.
    open_file(); //Abre el archivo en modo escritura/lectura..
}

partida::~partida()
{
    archivo.close();
}

void partida::open_file() {
    try { //Se maneja la excepcion para abrir el archivo.
        if (!archivo.open(QIODevice::ReadWrite | QIODevice::Text)) { //Evalua si el archivo se abrió correctamente o no.
            error = true; //Se establece la variable de control error como verdadero.
            throw std::runtime_error("No se pudo abrir el archivo" ); //Lanza una excepcion.
        }
    }
    catch (const std::exception &e) {
        emit error_occurred(e.what()); //Emite un error con el mensaje que contiene la excepción.
    }
    catch (...) {
        emit error_occurred("Se produjo un error desconocido al abrir el archivo para lectura/escritura."); //Emite un error desconocido.
    }
}

void partida::save_data() {
    QString aux = ""; //Inicializa un string auxiliar vacio.
    for (unsigned short cont = 0; cont < 5; cont++) {
        aux.append(QString::number(data[cont])); //Se concatena al string auxiliar el dato en la posicion que indica el contador.
        if (cont != 4) aux.append("\n"); //Si no es el ultimo dato se concatena un salto de linea.
    }
    archivo.resize(0); //Elimina todo lo que contiene el archivo, volviendolo de tamaño 0.
    archivo.write(aux.toUtf8()); //Escribe los datos que contiene el string auxiliar.
    archivo.flush(); //Actualiza el archivo.
}

void partida::save_load()
{
    if(wants_load){
        try {
            QTextStream in(&archivo); //Crea un buffer que contiene los datos del archivo
            int cont = 0; //Contador de lineas.
            while (!in.atEnd()) { //Ciclo que se ejecuta mientras no se llegue al final del archivo.
                QString line = in.readLine(); //Lee la linea siguiente.
                if(check_integrity(line, cont)) data.push_back(line.toInt()); //Verifica la integridad de la linea (verifica que los datos sean válidos)
                else {
                    error = true; //Si algun dato no es válido se activa un error y se lanza una excepcion que le indique al usuario que su archivo está corrupto.
                    throw std::runtime_error("El archivo de guardado esta corrupto, debe iniciar una nueva partida.");
                }
                cont++;
            }
            if(data.size() != 5){
                error = true; //Si los datos están incompletos se activa un error y se lanza una excepcion que le indique al usuario que su archivo está corrupto.
                throw std::runtime_error("El archivo de guardado esta corrupto, debe iniciar una nueva partida.");
            }
            error = false; //Si no se lanzó ninguna excepcion no hubo errores.
        } catch (const std::exception &e) {
            emit error_occurred(e.what()); //Emite un error con el mensaje que contiene la excepción.
        } catch (...) {
            emit error_occurred("Se produjo un error desconocido."); //Emite un error desconocido.
        }
    }
    else{
        load_defaults(); //Si no quiere cargar, sino que iniciar una partida nueva se carga una partida con datos por defecto.
        error = false; //No hay error dado que no se abrio ningun archivo ni se hizo ninguna verificación.
    }
}


void partida::update_data(unsigned short level, unsigned int coins, unsigned short stage, unsigned short hp, unsigned short time)
{
    //Actualiza el arreglo de datos, y también guarda la partida.
    data[0] = level;
    data[1] = coins;
    data[2] = stage;
    data[3] = hp;
    data[4] = time;
    save_data();
}

void partida::exists_file()
{
    //Si no existe el archivo se emite una señal indicando este hecho (Sirve para los menus de inicio).
    if (!archivo.exists() || archivo.size() == 0) {
        emit exists_save(false);
    }
    else{
        emit exists_save(true);
    }
}

bool partida::check_integrity(QString line, unsigned short parameter)
{      
    bool is_number = is_numeric(line); //Verifica que la linea sea un numero.
    switch(parameter){
    case 0: // El parametro 0 indica el nivel del barco.
        if(is_number){
            return line.toInt() <= 4;
        }
        else return false;
    case 1: //Indica las monedas que tiene.
        return is_number;
    case 2: //Indica la stage.
        if(is_number){
            return line.toInt() <= 3;
        }
        else return false;
    case 3: //Indica la vida
        return is_number;
    case 4: //Indica los segundos restantes.
        return is_number;
    }
}

void partida::load_defaults()
{
    //Establece los parametros por defecto para iniciar una partida nueva.
    data.push_back(1);
    data.push_back(0);
    data.push_back(1);
    data.push_back(data[0] * 50);
    data.push_back(60);
}

bool partida::getError() const
{
    return error;
}

void partida::setError(bool newError)
{
    error = newError;
}

QVector<int> partida::getData() const
{
    return data;
}

void partida::setData(const QVector<int> &newData)
{
    data = newData;
}

void partida::allow_file_load()
{
    wants_load = true;
}

void partida::forbid_file_load()
{
    wants_load = false;
}
