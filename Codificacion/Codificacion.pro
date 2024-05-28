QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    barco.cpp \
    fisicas.cpp \
    imagenes.cpp \
    main.cpp \
    partidas.cpp \
    reglas_juego.cpp \
    sprites.cpp \
    ventana.cpp

HEADERS += \
    barco.h \
    fisicas.h \
    imagenes.h \
    partidas.h \
    reglas_juego.h \
    sprites.h \
    ventana.h

FORMS += \
    Menu1.ui \
    Menu2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
