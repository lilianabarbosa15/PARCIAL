#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cuerpo.h"

#include <QDebug> //

extern QGraphicsScene *escena;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    escena = new QGraphicsScene(this);
    escena->setSceneRect(0,0,680,400);
    ui->Grafica->setScene(escena);
    ui->Grafica->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->Grafica->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(nuevoCuerpo()));
    timer->start(dt);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_objetoEspecial_clicked()
{

}

void MainWindow::nuevoCuerpo()
{
    qDebug() << "Nuevo cuerpo";
    //x_random = rand() % 650 + 10;
    //Pelotas.push_back(new Cuerpo(3,))
}
