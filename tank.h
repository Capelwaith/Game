#ifndef TANK_H
#define TANK_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>

class Tank_Npc : public QGraphicsItem
{
public:
    Tank_Npc(int x, int y);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    void advance(int phase);

private:
    qreal speed;
    void DoCollision();

};

#endif // MYITEM_H
