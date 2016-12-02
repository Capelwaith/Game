#ifndef DIALOG_H
#define DIALOG_H

#include <QtWidgets/QWidget>
#include <QtCore>
#include <QtWidgets>

namespace Ui {
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
    QGraphicsScene *escenario;
    QTimer *temporizador;
};

#endif // DIALOG_H
