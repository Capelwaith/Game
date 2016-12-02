#include "bala.h"
#include "tank2.h"

bala::bala()
{
    //velocidad por pixeles?
    speed = 7;

    //Iniciar en posicion del objeto



}

QRectF bala::boundingRect() const
{
    return QRect(0,0,5,10);
}

void bala::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    QBrush Brocha(Qt::gray);

    //basic Collision detection

    if(scene()->collidingItems(this).isEmpty())
    {
        //no collision
        Brocha.setColor(Qt::green);
    }
    else
    {
        //collision!!!!
        Brocha.setColor(Qt::red);

        //Set the position
        DoCollision();
    }

    painter->fillRect(rec,Brocha);
    painter->drawRect(rec);

}

void bala::advance(int phase)
{
    if(!phase) return;

    QPointF location = this->pos();

    setPos(mapToParent(0,-(speed)));
}

void bala::DoCollision()
{


    //Giro siempre de 90 grados

    setRotation(rotation()+(90));



    //Ver si la nueva posicion esta dentro del escenario
    QPointF newpoint = mapToParent(-(boundingRect().width()), -(boundingRect().width() + 1));

    if(!scene()->sceneRect().contains((newpoint)))
    {
        //Si esta fuera de la escena
        newpoint = mapToParent(0,0);
    }
    else
    {
        //Define la nueva posicion
        setPos(newpoint);
    }

}
