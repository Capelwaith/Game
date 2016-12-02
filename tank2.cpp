#include "tank2.h"
#include "bala.h"
#include <QKeyEvent>
#include <QMediaPlayer>

tank2::tank2()
{
    speed = 5;

    //Iniciar en posicion "aleatoria" 100% real no faik
    int StartX=0;
    int StartY=0;
    setPos(mapToParent(StartX,StartY));
}
QRectF tank2::boundingRect() const
{
    return QRect(0,0,20,20);
}
void tank2::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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



void tank2::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left)
    {
        setPos(x()-10, y());

    }

    else if (event->key() == Qt::Key_Right)
    {
        setPos(x()+10, y());

    }
    else if (event->key() == Qt::Key_Up)
    {
        setPos(x(), y()-10);

    }
    else if (event->key() == Qt::Key_Down)
    {
        setPos(x(), y()+10);
    }
}


void tank2::DoCollision()
{

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
