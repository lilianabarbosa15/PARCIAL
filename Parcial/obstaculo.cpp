#include "obstaculo.h"

Obstaculo::Obstaculo(double _ancho, double _alto, double x_inicial, double y_inicial, QObject *parent): QObject{parent}
{
    posX=x_inicial;
    posY=y_inicial;
    ancho=_ancho;
    alto=_alto;
    setPos(posX,posY);
}

QRectF Obstaculo::boundingRect() const
{
    return QRectF(-ancho,-alto,2*ancho,2*alto);
}

void Obstaculo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::cyan);
    painter->drawRect(boundingRect());
}

int Obstaculo::getPosY()
{
    return posY;
}

int Obstaculo::getPosX()
{
    return posX;
}

int Obstaculo::getAncho() const
{
    return ancho;
}
