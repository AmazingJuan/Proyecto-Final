#ifndef ANIMATIONS_H
#define ANIMATIONS_H

#include <QLabel>
#include <QMovie>
#include <QGraphicsProxyWidget>

#define movies_separator "_"
#define file_path ":/gifs/Gifs/"

class animations
{
public:
    animations(QString file_prefix, int number_animations);
    animations(QString route);
    ~animations();
    QLabel *getMain_label();
    void set_animation(unsigned short animation_number);
    void setWidget(QGraphicsProxyWidget *widget);
    QGraphicsProxyWidget *getWidget();

private:
    QString file_prefix;
    QGraphicsProxyWidget *widget;
    QLabel *main_label;
    QVector<QMovie *> movies;
    unsigned short animations_number;


    void initialize_movies();
    void setup_label();
};

#endif // ANIMATIONS_H
