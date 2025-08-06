#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "casillapuente.h"
#include "casillaoca.h"
#include "casillaposada.h"
#include "casillapozo.h"
#include "casillalaberinto.h"
#include "casillacarcel.h"
#include "casillacalavera.h"
#include "casillajardindelaoca.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , juego(nullptr),ui(new Ui::Oca)
{
    ui->setupUi(this);
    connect(ui->dado,&QPushButton::clicked,this,&MainWindow::TirarTurno);
    connect(ui->botonIniciar, &QPushButton::clicked, this, &MainWindow::on_botonIniciar_clicked);
}

void MainWindow::TirarTurno(){
    juego->JugarTurno();
    actualizarFichas();

    QString mensaje=juego->getMsj();
    if (!mensaje.isEmpty()){
        ui->informacion->append(mensaje);
        juego->BorrarMsj();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_botonIniciar_clicked() {

    juego = new Juego(ui->spinBox->value());
    crearTablero(juego);
    ui->informacion->clear();

    QStringList rutasimag = {
        ":/imagenes/fichaRoja.png",
        ":/imagenes/fichaAzul.png",
        ":/imagenes/fichaVerde.png",
        ":/imagenes/fichaAmarilla.png"
    };

    for (int i = 0; i < juego->cantJugadores(); ++i) {
        QLabel* ficha = new QLabel(this);
        ficha->setFixedSize(30, 30);
        ficha->setPixmap(QPixmap(rutasimag[i]).scaled(30, 30, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        ficha->setStyleSheet("background-color: transparent;");
        ficha->setAttribute(Qt::WA_TranslucentBackground);
        ficha->raise(); // que quede encima de las casillas
        ficha->show();

        fichas.append(ficha);
    }

}

void MainWindow::crearTablero(Juego* juego) {
    QGridLayout* layout = ui->tableroLayout;


    casillasVisuales.clear();
    Mapa* mapa = juego->getMapa();
    int columnas = 8;

    for (int i = 0; i < 64; ++i) {
        Casilla* c = mapa->getCasilla(i);


        QString texto = (i == 0) ? "Inicio" : QString::number(c->getNumCasilla());
        QLabel* label = new QLabel(texto);
        label->setAlignment(Qt::AlignCenter);
        label->setFixedSize(45, 45);
        casillasVisuales.append(label);
        // Elegir color según tipo de casilla
        QString color;
        if (dynamic_cast<CasillaPuente*>(c)) {
            color = "#ADD8E6"; // celeste
        } else if (dynamic_cast<CasillaOca*>(c)) {
            color = "#90EE90"; // verde claro
        } else if (dynamic_cast<CasillaPosada*>(c)) {
            color = "#FFD700"; // dorado
        } else if (dynamic_cast<CasillaPozo*>(c)) {
            color = "#6495ED"; // azul
        } else if (dynamic_cast<CasillaLaberinto*>(c)) {
            color = "#FFA07A"; // salmón
        } else if (dynamic_cast<CasillaCarcel*>(c)) {
            color = "#FF6347"; // rojo tomate
        } else if (dynamic_cast<CasillaCalavera*>(c)) {
            color = "#8B0000"; // rojo oscuro
        } else if (dynamic_cast<CasillaJardinDeLaOca*>(c)) {
            color = "#DA70D6"; // púrpura
        } else {
            color = "#F0F0F0"; // gris claro para normales
        }

        label->setStyleSheet(QString("border: 1px solid black; background-color: %1;").arg(color));
        label->setProperty("casillaPtr", QVariant::fromValue(static_cast<void*>(c)));

        int fila = i / columnas;
        int col;
        if (fila % 2 == 0) {
            col = i % columnas;
        } else {
            col = columnas - 1 - (i % columnas);
        }
        layout->addWidget(label, fila, col);
        casillasVisuales.append(label);
    }

    actualizarFichas();
}

void MainWindow::actualizarFichas() {
    int anchoCasilla = 60;
    int altoCasilla = 60;
    int columnas = 8;
    int offsetX = 50;
    int offsetY = 100;

    for (int i = 0; i < fichas.size(); ++i) {
        Jugador* jugador = juego->getJugador(i);
        if (!jugador) continue;

        int pos = jugador->getPos();
        int fila = pos / columnas;
        int col = (fila % 2 == 0) ? (pos % columnas) : (columnas - 1 - (pos % columnas));

        int baseX = offsetX + col * anchoCasilla;
        int baseY = offsetY + fila * altoCasilla;


        int separacionX = (i % 2) * 15;
        int separacionY = (i / 2) * 15;

        fichas[i]->move(baseX + separacionX, baseY + separacionY);
    }
}




