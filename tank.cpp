#include "tank.h"

Tank_Npc::Tank_Npc(int x, int y)
{
    //velocidad por pixeles?
    speed = 5;

    //Iniciar en posicion "aleatoria" 100% real no faik
    int StartX=x;
    int StartY=y;
    setPos(mapToParent(StartX,StartY));
}

QRectF Tank_Npc::boundingRect() const
{
    return QRect(0,0,20,20);
}

void Tank_Npc::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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

void Tank_Npc::advance(int phase)
{
    if(!phase) return;

    QPointF location = this->pos();

    setPos(mapToParent(0,-(speed)));
}

void Tank_Npc::DoCollision()
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
