#ifndef PANTALLA_JUGADOR1_H
#define PANTALLA_JUGADOR1_H

#include <QWidget>

namespace Ui {
class pantalla_jugador1;
}

class pantalla_jugador1 : public QWidget
{
    Q_OBJECT

public:
    explicit pantalla_jugador1(QWidget *parent = 0);
    ~pantalla_jugador1();

private slots:
    void on_pushButton_clicked();

private:
    Ui::pantalla_jugador1 *ui;
};

#endif // PANTALLA_JUGADOR1_H
