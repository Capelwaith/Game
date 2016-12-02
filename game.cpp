#include "game.h"
#include "instrucciones.h"

Game::Game(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
}

Game::~Game()
{
    delete ui;
}

void Game::on_pushButton_clicked()
{
    Instrucciones *inst=new Instrucciones();
    inst->show();
    this->hide();
}
