#ifndef OBSTACULO_H
#define OBSTACULO_H


#include<QObject>
#include<QGraphicsItem>
#include<QPainter>

class Obstaculo: public QGraphicsPixmapItem//public QGraphicsItem
{
private:
    double posX=0,posY=0,ancho=0,alto=0;
    //QPixmap apariencia;
public:
    Obstaculo(double _ancho,double _alto,double x_inicial,double y_iniciale);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
    int getPosY();
    int getPosX();
    int getAncho() const;
};


/*

*/
#endif // OBSTACULO_H
