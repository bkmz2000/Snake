#include "snake.h"

Snake::Snake()
{
    X = 10;
    Y = 10;

    Length = 5;

    Xs.push_back(X);
    Ys.push_back(Y);

    dir = "up";
}

void Snake::move()
{
    if(dir == "up")
        Y--;

    if(dir == "down")
        Y++;

    if(dir == "right")
        X++;

    if(dir == "left")
        X--;



    if(X>=20)
    {
        X=0;
        Length--;
        Xs.push_back(X);
        Ys.push_back(Y);
    }

    if(X<=0)
    {
        X=20;
        Length--;
        Xs.push_back(X);
        Ys.push_back(Y);
    }

    if(Y>=20)
    {
        Y=0;
        Length--;
        Xs.push_back(X);
        Ys.push_back(Y);
    }

    if(Y<=0)
    {
        Y=20;
        Length--;
        Xs.push_back(X);
        Ys.push_back(Y);
    }

    Xs.push_back(X);
    Ys.push_back(Y);
}

void Snake::setDir(QString str)
{
    dir = str;
}


int Snake::x()
{
    return X;
}

int Snake::y()
{
    return Y;
}

void Snake::x(int a)
{
    X = a;
}

void Snake::y(int a)
{
    Y = a;
}
