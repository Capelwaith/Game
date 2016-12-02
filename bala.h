#ifndef BALA_H
#define BALA_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>

class bala : public QGraphicsItem
{
public:
    bala();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    void advance(int phase);

private:
    qreal speed;
    void DoCollision();

};

#endif // MYITEM_H
