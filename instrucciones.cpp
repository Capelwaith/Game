#include "instrucciones.h"
#include "game.h"
#include "pantalla_jugador1.h"



Instrucciones::Instrucciones(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Instrucciones)
{
    ui->setupUi(this);
}

Instrucciones::~Instrucciones()
{
    delete ui;
}

void Instrucciones::on_pushButton_clicked()
{
    pantalla_jugador1 *inst=new pantalla_jugador1();
    inst->show();
    this->hide();
}

void Instrucciones::on_pushButton_2_clicked()
{
    pantalla_jugador2 *inst=new pantalla_jugador2();
    inst->show();
    this->hide();
}

void Instrucciones::on_pushButton_3_clicked()
{
    Game *inst=new Game();
    inst->show();
    this->hide();
}

void Instrucciones::on_pushButton_4_clicked()
{
    credits *inst=new credits();
    inst->show();
    this->hide();
}
