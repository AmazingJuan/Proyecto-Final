#ifndef PARTIDA_H
#define PARTIDA_H

#define max_slots 3
#include <QFile>
#include <QObject>

class partida : public QObject
{
    Q_OBJECT
public:
    partida(QString ruta);
    ~partida();
    void save_load();
    void save_data();
    void update_data(unsigned short level, unsigned int coins, unsigned short stage, unsigned short hp, unsigned short time);
    void exists_file();

    bool getError() const;
    void setError(bool newError);
    QVector<int> getData() const;
    void setData(const QVector<int> &newData);
private:
    QString nombreArchivo;
    QFile archivo;
    bool error;
    bool wants_load;
    QVector<int> data;

    bool check_integrity(QString line, unsigned short parameter);
    void load_defaults();
    void open_file();
signals:
    void error_occurred(const QString &errorMessage);
    void exists_save(bool dato);
public slots:
    void allow_file_load();
    void forbid_file_load();
};

#endif // PARTIDA_H
