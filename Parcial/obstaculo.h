#ifndef OBSTACULO_H
#define OBSTACULO_H


#include<QObject>
#include<QGraphicsItem>
#include<QPainter>
#include<QGraphicsScene>
#include<math.h>
#include<QTimer>

class Obstaculo: public QObject, public QGraphicsItem
{
private:
    double posX=0,posY=0,ancho=0,alto=0;

public:
    Obstaculo(double _ancho,double _alto,double x_inicial,double y_inicial, QObject *parent=nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
    int getPosY();
    int getPosX();
    int getAncho() const;
};


/*

*/
#endif // OBSTACULO_H
