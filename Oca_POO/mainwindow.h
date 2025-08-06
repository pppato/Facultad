
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <juego.h>
#include <QString>

#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Oca; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Juego* juego;
    void TirarTurno();
    void crearTablero(Juego* juego);
    QVector<QLabel*> casillasVisuales;
    QVector<QPoint> posicionesCasillas;
    QVector<QLabel*> fichas;

    Ui::Oca *ui;
    void on_botonIniciar_clicked();
    void crearFichas(int cantidadJugadores);
    void actualizarFichas();
};

#endif // MAINWINDOW_H
