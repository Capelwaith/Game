#ifndef TANK_USER_H
#define TANK_USER_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>

class Tank_User
{
public:
    Tank_User(int x, int y);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    void advance(int phase);

private:
    qreal speed;
};

#endif // TANK_USER_H
