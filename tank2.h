#ifndef TANK2_H
#define TANK2_H

#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <QKeyEvent>


class tank2 : public QGraphicsItem
{
public:
    tank2();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void keyPressEvent(QKeyEvent *event);

private:
    qreal speed;
    void DoCollision();





};

#endif // TANK2_H
