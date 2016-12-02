#include "tank_user.h"

Tank_User::Tank_User(int x, int y)
{
    //velocidad por pixeles
    speed = 5;
    int StartX=x;
    int StartY=y;

    //Iniciar en posicion definida
    setPos(mapToParent(StartX,StartY));
}
