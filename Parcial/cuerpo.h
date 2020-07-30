#ifndef CUERPO_H
#define CUERPO_H


#include<QObject>
#include<QGraphicsItem>
#include<QPainter>
#include<QGraphicsScene>
#include<math.h>
#include<QTimer>

class Cuerpo: public QObject, public QGraphicsItem
{
    /*
      El tipo 1 corresponde a los objetos en caída que rebotan contra los obstáculos, la parte superior de la escena,
      las partes laterales de la escena y desaparecen al tocar la parte inferior. E tipo 2 corresponde a los objetos
      especiales que van disminuyendo su tamaño cada que tocan un obstaculo hasta desaparecer.
    */
    Q_OBJECT
private:
    double posX=0, posY=0, V0=0, Vx=0,Vy=0;
    double angulo=0, radio=0;
    double a=9.8,delta=0.1;    //delta: cambio en el tiempo (variar segun timer para mayor o
                                                    //menor velocidad de la animacion)
    unsigned int tipo=0;        //para implementacion de rebotes
    QTimer *timer=new QTimer;

public:
    Cuerpo(double _radio, double X, double Y, double _V0, double _angulo=(3*M_PI)/2, unsigned short _tipo=1,QObject *parent=nullptr);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);

    void rebotar();
    void ActualizarPosicion();
    void ActualizarVelocidad();

    void Desaparecer();
    void setA(double value);
    double getPosX() const;
    double getPosY() const;
    void setDelta(int value);
    bool Colisiones();

private slots:
    void Mover();
};

#endif // CUERPO_H
