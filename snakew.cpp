#include "snakew.h"
#include "ui_snakew.h"

#include <QPainter>
#include <QColor>
#include <QDebug>
#include <QTimer>
#include <QKeyEvent>
#include <QString>
#include <math.h>

SnakeW::SnakeW(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SnakeW)
{
    done = false;
    ui->setupUi(this);

    ui->up->setGeometry(this->width()/20, this->width(), (this->width()/20)*5, (this->width()/20)*5);
    //ui->down->setGeometry(150, 600, 100, 100);
    //ui->left->setGeometry(50, 500, 100, 100);
    //ui->right->setGeometry(250, 500, 100, 100);

    //ui->up   ->setFlat(true);
    //ui->down ->setFlat(true);
    //ui->left ->setFlat(true);
    //ui->right->setFlat(true);

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(gameLoop()));
    timer->start(150);


    ui->up   ->setFlat(true);
    ui->down ->setFlat(true);
    ui->left ->setFlat(true);
    ui->right->setFlat(true);
}

void SnakeW::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    ui->up   ->setGeometry(this->width()/4,                      this->width()                    ,   (this->width()/20)*5, (this->width()/20)*5);
    ui->down ->setGeometry(this->width()/4,                      this->width()+(this->width()/20)*10, (this->width()/20)*5, (this->width()/20)*5);
    ui->left ->setGeometry(this->width()/4-(this->width()/20)*5, this->width()+(this->width()/20)*5,  (this->width()/20)*5, (this->width()/20)*5);
    ui->right->setGeometry(this->width()/4+(this->width()/20)*5, this->width()+(this->width()/20)*5,  (this->width()/20)*5, (this->width()/20)*5);

    for(int x = 0; x<20; x++)
        for(int y = 0; y<20; y++)
        {
            QColor color;
            if(field.cell(x, y) == field.NONE)
                color = Qt::yellow;
            if(field.cell(x, y) == field.SNAKE)
                color = Qt::green;
            if(field.cell(x, y) == field.FOOD)
                color = Qt::red;



            painter.fillRect(x*this->width()/20, y*this->width()/20, this->width()/20, this->width()/20, color);
        }


    painter.fillRect(this->width()/4,                      this->width()                    ,   (this->width()/20)*5, (this->width()/20)*5, Qt::blue);
    painter.fillRect(this->width()/4,                      this->width()+(this->width()/20)*10, (this->width()/20)*5, (this->width()/20)*5, Qt::blue);
    painter.fillRect(this->width()/4-(this->width()/20)*5, this->width()+(this->width()/20)*5,  (this->width()/20)*5, (this->width()/20)*5, Qt::blue);
    painter.fillRect(this->width()/4+(this->width()/20)*5, this->width()+(this->width()/20)*5,  (this->width()/20)*5, (this->width()/20)*5, Qt::blue);

    painter.setPen(Qt::black);

    for(int x = 0; x<20; x++)
        painter.drawLine(x*this->width()/20, this->width(), x*this->width()/20, 0);

    for(int y = 0; y<20; y++)
        painter.drawLine(0, y*this->width()/20, this->width(),  y*this->width()/20);
}

SnakeW::~SnakeW()
{
    delete ui;
}

void SnakeW::on_up_clicked()
{
    field.snake.setDir("up");
}

void SnakeW::on_down_clicked()
{
    field.snake.setDir("down");
}

void SnakeW::on_right_clicked()
{
    field.snake.setDir("right");
}

void SnakeW::on_left_clicked()
{
    field.snake.setDir("left");
}

void SnakeW::gameLoop()
{
    if(field.update() == true)
    {
        done = true;
        close();
    }
    repaint();
}

void SnakeW::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case 87:
        case 1062:
            field.snake.setDir("up");
            break;

        case 83:
        case 1067:
            field.snake.setDir("down");
            break;

        case 65:
        case 1060:
            field.snake.setDir("left");
            break;

        case 1042:
        case 68:
            field.snake.setDir("right");
            break;
    }
}
