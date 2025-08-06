QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    casilla.cpp \
    casillacalavera.cpp \
    casillacarcel.cpp \
    casillajardindelaoca.cpp \
    casillalaberinto.cpp \
    casillaoca.cpp \
    casillaposada.cpp \
    casillapozo.cpp \
    casillapuente.cpp \
    casillasinefecto.cpp \
    dado.cpp \
    juego.cpp \
    jugador.cpp \
    main.cpp \
    mainwindow.cpp \
    mapa.cpp

HEADERS += \
    casilla.h \
    casillacalavera.h \
    casillacarcel.h \
    casillajardindelaoca.h \
    casillalaberinto.h \
    casillaoca.h \
    casillaposada.h \
    casillapozo.h \
    casillapuente.h \
    casillasinefecto.h \
    dado.h \
    juego.h \
    jugador.h \
    mainwindow.h \
    mapa.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    archivos.qrc
