#include "mainwindow.h"
#include "ui_mainwindow.h"

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

    srand(unsigned(time(nullptr)));

    timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(Actualizar()));
    timer->start(dt);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_objetoEspecial_clicked()
{
    qDebug() << "Nuevo cuerpo";
    x_random = rand() % 650 + 10;
    x_random = rand() % 200 + 10;
    Pelotas.push_back(new Cuerpo(12, x_random, y_random,0,2));
    Pelotas.back()->setFlag(QGraphicsItem::ItemIsFocusable);
    escena->addItem(Pelotas.back());
}

void MainWindow::Actualizar()
{
    contTime++;

    qDebug() << "Nuevo cuerpo";
    if(contTime%2==0){
        x_random = rand() % 650 + 10;
        y_random = rand() % 100 + 10;
        Pelotas.push_back(new Cuerpo(10, x_random, y_random,5,0));
        Pelotas.back()->setFlag(QGraphicsItem::ItemIsFocusable);
        escena->addItem(Pelotas.back());
    }

    x_random = rand() % 600 + 10;
    y_random = rand() % 300 + 220;
    Obstaculos.push_back(new Obstaculo(40,10,x_random,y_random));
    escena->addItem(Obstaculos.back());
}
