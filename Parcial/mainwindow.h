#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "cuerpo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_objetoEspecial_clicked();
    void nuevoCuerpo();

private:
    Ui::MainWindow *ui;
    QTimer *timer=new QTimer;
    unsigned short int dt = 1000;
    QVector<Cuerpo *> Pelotas = {};
    unsigned short int x_random;
    unsigned short int y_random;
};

#endif // MAINWINDOW_H
