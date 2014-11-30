#include "field.h"
#include <QDebug>
Field::Field()
{
    for(int x = 0; x<20; x++)
        for(int y = 0; y<20; y++)
        {
            field[x][y] = NONE;
        }

    setFood();
    cell(snake.x(), snake.y(), SNAKE);
}

int Field::cell(int x, int y)
{
    return field[x][y];
}

void Field::cell(int x, int y, int state)
{
    if(x<20&&x>0)
        if(y<20&&y>0)
            field[x][y] = state;
}

int Field::update()
{

    snake.move();

    if(cell(snake.x(), snake.y()) == SNAKE)
        return 1;

    if(snake.Length<=1)
        return  1;

    cell(snake.x(), snake.y(), SNAKE);



    if(snake.x() == foodX)
        if(snake.y() == foodY)
        {
            snake.Length++;
            setFood();
        }

    for(int i = 0; i<3; i++)
        cell(snake.Xs[snake.Xs.size()-snake.Length-i], snake.Ys[snake.Ys.size()-snake.Length-i], NONE);


    return 0;
}

void Field::setFood()
{
    srand(time(NULL));

    foodX = rand() % 19 + 1;
    foodY = rand() % 19 + 1;

    if(cell(foodX, foodY) == NONE)
        cell(foodX, foodY, FOOD);

    else
        setFood();
}
