#include "dialog.h"
#include "ui_dialog.h"
#include "tank.h"
#include "tank2.h"
#include <QMediaPlayer>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    escenario = new QGraphicsScene(this);
    ui->graphicsView->setScene(escenario);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    escenario->setSceneRect(-200,-200,300,300);
    QMediaPlayer* musica;
    musica=new QMediaPlayer;
    musica->setMedia(QUrl::fromLocalFile("/Desktop/Animation/Macintosh.mp3"));
    musica->play();

    QPen mi_trazo = QPen(Qt::black);

    QLineF TopLine(escenario->sceneRect().topLeft(), escenario->sceneRect().topRight());
    QLineF LeftLine(escenario->sceneRect().topLeft(), escenario->sceneRect().bottomLeft());
    QLineF RightLine(escenario->sceneRect().topRight(), escenario->sceneRect().bottomRight());
    QLineF BottomLine(escenario->sceneRect().bottomLeft(), escenario->sceneRect().bottomRight());
    QRect Muro0(50, -90, 50, 10);
    QRectF Muro_0(Muro0);
    QRect Muro1(-200, 60, 50, 10);
    QRectF Muro_1(Muro1);
    QRect Muro2(-100, -50, 10, 50);
    QRectF Muro_2(Muro2);
    QRect Muro3(-50, -200, 10, 50);
    QRectF Muro_3(Muro3);

    //Los contornos del juego
    escenario->addLine(TopLine,mi_trazo);
    escenario->addLine(LeftLine,mi_trazo);
    escenario->addLine(RightLine,mi_trazo);
    escenario->addLine(BottomLine,mi_trazo);
    //Los muros por poner (Falta arreglar, esta buggeado)
    escenario->addRect(Muro_0);
    escenario->addRect(Muro_1);
    escenario->addRect(Muro_2);
    escenario->addRect(Muro_3);




    //Los 4 tanques enemigos
        Tank_Npc *Esquina1 = new Tank_Npc(-200,-200);
        escenario->addItem(Esquina1);
        Tank_Npc *Esquina2 = new Tank_Npc(100, -200);
        escenario->addItem(Esquina2);
        Tank_Npc *Esquina3 = new Tank_Npc(-200, 100);
        escenario->addItem(Esquina3);
        Tank_Npc *Esquina4 = new Tank_Npc(100, 100);
        escenario->addItem(Esquina4);

    //El tanque del usuario
        tank2 *User = new tank2();
        escenario->addItem(User);
        User->setFlag(QGraphicsItem::ItemIsFocusable); //Esto permite que el Objeto "User" reciba los comandos de las teclas presionadas
        User->setFocus();



    temporizador = new QTimer(this);
    connect(temporizador, SIGNAL(timeout()), escenario,SLOT(advance()));
    temporizador->start(100);




}

Dialog::~Dialog()
{
    delete ui;
}
