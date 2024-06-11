#include <QTextStream>
#include "partida.h"
#include "utilities.h"

partida::partida(QString ruta) {
    nombreArchivo = ruta;
    wants_load = false;
    archivo.setFileName(nombreArchivo);
    open_file();
}

partida::~partida()
{
    archivo.close();
}

void partida::open_file() {
    try {
        if (!archivo.open(QIODevice::ReadWrite | QIODevice::Text)) {
            error = true;
            throw std::runtime_error("No se pudo abrir el archivo" );
        }
    }
    catch (const std::exception &e) {
        emit error_occurred(e.what());
    }
    catch (...) {
        emit error_occurred("Se produjo un error desconocido al abrir el archivo para lectura.");
    }
}

void partida::save_data() {
    QString aux = "";
    for (unsigned short cont = 0; cont < 5; cont++) {
        aux.append(QString::number(data[cont]));
        if (cont != 4) aux.append("\n");
    }
    archivo.resize(0);
    archivo.write(aux.toUtf8());
    archivo.flush();
}

void partida::save_load()
{
    if(wants_load){
        try {
            QTextStream in(&archivo);
            int cont = 0;
            while (!in.atEnd()) {
                QString line = in.readLine();
                if(check_integrity(line, cont)) data.push_back(line.toInt());
                else {
                    error = true;
                    throw std::runtime_error("El archivo de guardado esta corrupto, debe iniciar una nueva partida.");
                }
                cont++;
            }
            if(data.size() != 5){
                error = true;
                throw std::runtime_error("El archivo de guardado esta corrupto, debe iniciar una nueva partida.");
            }
            error = false;
        } catch (const std::exception &e) {
            emit error_occurred(e.what());
        } catch (...) {
            emit error_occurred("Se produjo un error desconocido.");
        }
    }
    else{
        load_defaults();
        error = false;
    }
}


void partida::update_data(unsigned short level, unsigned int coins, unsigned short stage, unsigned short hp, unsigned short time)
{
    data[0] = level;
    data[1] = coins;
    data[2] = stage;
    data[3] = hp;
    data[4] = time;
    save_data();
}

void partida::exists_file()
{
    if (!archivo.exists() || archivo.size() == 0) {
        emit exists_save(false);
    }
    else{
        emit exists_save(true);
    }
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

bool partida::check_integrity(QString line, unsigned short parameter)
{
    bool is_number = is_numeric(line);
    switch(parameter){
    case 0:
        if(is_number){
            return line.toInt() <= 4;
        }
        else return false;
    case 1:
        return is_number;
    case 2:
        if(is_number){
            return line.toInt() <= 3;
        }
        else return false;
    case 3:
        return is_number;
    case 4:
        return is_number;
    }
}

void partida::load_defaults()
{
    data.push_back(1);
    data.push_back(0);
    data.push_back(1);
    data.push_back(data[0] * 50);
    data.push_back(60);
}

void partida::allow_file_load()
{
    wants_load = true;
}

void partida::forbid_file_load()
{
    wants_load = false;
}
