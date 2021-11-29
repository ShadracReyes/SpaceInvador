#pragma once

#include <Windows.h>

class Bullet
{

private:
    int posX;
    int posY;
    int speedX;
    int speedY;

public:
    char value = '.';

public:
    void setX();
    void setY();
    int getX();
    int getY();
    void drawBullet();
};


