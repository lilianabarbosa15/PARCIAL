#include "cuerpo.h"
#include "obstaculo.h"

#include <QDebug> //

Cuerpo::Cuerpo(double _radio, double X, double Y, double _V0, double _angulo, unsigned short _tipo, QObject *parent): QObject{parent}
{
    tipo=_tipo;
    radio=_radio;
    posX=X;
    posY=Y;
    angulo=_angulo; //Por default se tiene 3PI/2
    V0=_V0;
    setPos(posX,posY);

    connect(timer,SIGNAL(timeout()),this,SLOT(Mover()));
    timer->start(50);
}

QRectF Cuerpo::boundingRect() const
{
     return QRectF(-radio,-radio,2*radio,2*radio);
}

void Cuerpo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(tipo==1){
        painter->setBrush(Qt::green);
    }
    else if(tipo==2){
        painter->setBrush(Qt::red);
    }
    painter->drawEllipse(boundingRect());
}

void Cuerpo::rebotar(unsigned short int tipo)
{
    //Posible metodo para rebote
    if(tipo==1)
        Vy=-Vy;
    else if(tipo==2)
        Vx=-Vx;
    angulo=atan2(Vy,Vx);
    ActualizarVelocidad();
    ActualizarPosicion();
}

void Cuerpo::ActualizarPosicion()
{
    //Segun ecuaciones de MRUA
    posX+=Vx*delta;
    posY-=Vy*delta-0.5*a*delta*delta; //Resta por sistema de coordenadas de la escena
                                      //(Si al implementarlo se genera una parabola que abre hacia arriba entonces cambiar
                                      //por +=)
    setPos(posX,posY);
}

void Cuerpo::ActualizarVelocidad()
{
    //Segun ecuaciones de lanzamiento de proyectiles.
    Vx=V0*cos(angulo);
    Vy=V0*sin(angulo)-a*delta;
    V0=sqrt(Vy*Vy+Vx*Vx);
    angulo=atan2(Vy,Vx);
}

void Cuerpo::Mover()
{
    Colisiones();
    if(Colisiones()==true && tipo==1)   //Rebotar contra plataforma (tipo 1)
    {
        rebotar(1);
    }
    else if(Colisiones()==true && tipo==2)   //Rebotar contra plataforma (tipo 2)
    {
        rebotar(1);
        if(radio>1){
            radio--;
        }
        else{
            Desaparecer();
            delete this;
        }
    }
    else if(((int)posX)==0 || ((int)(posX+2*radio)==680)){  //Rebotar contra las paredes
        rebotar(2);
    }
    else if(((int)posY)==0){    //Rebotar contra el techo
        rebotar(1);
    }
    else if(posY<400)   //Caer
    {
        ActualizarVelocidad();
        ActualizarPosicion();
    }
    else{
        Desaparecer();
        delete this;
    }
}

void Cuerpo::Desaparecer()
{
    //Remover cuerpo de escena ingresada.
    scene()->removeItem(this);
}


void Cuerpo::setA(double value)
{
    a = value;
}

double Cuerpo::getPosX() const
{
    return posX;
}

double Cuerpo::getPosY() const
{
    return posY;
}

void Cuerpo::setDelta(int value)
{
    delta = value;
}

bool Cuerpo::Colisiones()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i=0, n=colliding_items.size(); i<n; i++){
        if((typeid(*(colliding_items[i]))==typeid (Obstaculo))){
            return true;
        }
    }
    return false;
}
