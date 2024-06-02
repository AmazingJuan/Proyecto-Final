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
    animations(QString file_prefix, int number_animations, unsigned short max_pixels);
    animations(QString route, unsigned short max_pixels);
    ~animations();
    QLabel *getMain_label();

    void change_animations(QString file_prefix, int number_animations);
    void set_animation(unsigned short animation_number);
private:
    QString file_prefix;
    QLabel *main_label;
    QVector<QMovie *> movies;
    unsigned short animations_number;
    unsigned short max_pixels;
    void initialize_movies();
    void setup_label(unsigned short max_pixels);
    void dispose_movies();
};

#endif // ANIMATIONS_H
