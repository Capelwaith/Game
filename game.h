#ifndef GAME_H
#define GAME_H

#include <QMainWindow>

namespace Ui {
class Game;
}

class Game : public QMainWindow
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = 0);
    ~Game();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Game *ui;
};

#endif // GAME_H
