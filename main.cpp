#include <QtWidgets/QApplication>
#include "dialog.h"
#include "mainwindow.h"
#include <QMediaPlayer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow m;
    m.show();


    return a.exec();
}
