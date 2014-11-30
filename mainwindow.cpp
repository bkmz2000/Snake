#include "ui_mainwindow.h"
#include "mainwindow.h"

#include <QDebug>
#include <QLabel>
#include <QLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    snake = new SnakeW;

    ui->label->setGeometry(this->width()/2, this->height()/2, 191, 16);
    this->setCentralWidget(snake);

    this->resize(400, 700);

    connect(snake, SIGNAL(hidden()), this, SLOT(gameOver()));

}

void MainWindow::gameOver()
{
    qDebug()<<"done";

    ui->label->setGeometry(this->width()/2, this->height()/2, 61, 20);
    ui->label->setText("Game Over");
}

MainWindow::~MainWindow()
{
    delete ui;
}
