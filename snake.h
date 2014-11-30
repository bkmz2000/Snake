#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <QString>

using std::vector;

class Snake
{
private:
    int X;
    int Y;

    QString dir;

public:

    int Length;


    vector<int> Xs;
    vector<int> Ys;

    void move();
    void setDir( QString str);

    int x();
    int y();

    void x(int a);
    void y(int a);

    Snake();
};

#endif // SNAKE_H
