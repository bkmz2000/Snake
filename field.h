#ifndef FIELD_H
#define FIELD_H

#include <snake.h>
#include <stdlib.h>
#include <time.h>

class Field
{
private:
    int field[20][20];
    int foodX;
    int foodY;
public:
    Snake snake;

    Field();
    int cell(int, int);
    void cell(int, int, int);

    void setFood();

    int update();

    enum {NONE, SNAKE, FOOD};
};

#endif // FIELD_H
#ifndef FIELD_H
#define FIELD_H

#include <snake.h>
#include <stdlib.h>
#include <time.h>

class Field
{
private:
    int field[20][20];
    int foodX;
    int foodY;
public:
    Snake snake;

    Field();
    int cell(int, int);
    void cell(int, int, int);

    void setFood();

    int update();

    enum {NONE, SNAKE, FOOD};
};

#endif // FIELD_H
