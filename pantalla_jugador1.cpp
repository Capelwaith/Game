#include "pantalla_jugador1.h"
#include "instrucciones.h"

pantalla_jugador1::pantalla_jugador1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pantalla_jugador1)
{
    ui->setupUi(this);
}

pantalla_jugador1::~pantalla_jugador1()
{
    delete ui;
}

void pantalla_jugador1::on_pushButton_clicked()
{
    Instrucciones *inst=new Instrucciones();
    inst->show();
    this->hide();
}
