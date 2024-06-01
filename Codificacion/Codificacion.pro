QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    animations.cpp \
    barco.cpp \
    fisicas.cpp \
    main.cpp \
    obstaculo.cpp \
    partidas.cpp \
    reglas_juego.cpp \
    utilities.cpp \
    ventana.cpp

HEADERS += \
    animations.h \
    barco.h \
    fisicas.h \
    obstaculo.h \
    partidas.h \
    reglas_juego.h \
    utilities.h \
    ventana.h

FORMS += \
    Menu1.ui \
    Menu2.ui \
    MenuCompra.ui \
    MiddleMessage.ui \
    Stage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
