#include "ui_mainwindow.h"
#include "mainwindow.h"

#include <QDebug>
#include <QLabel>
#include <QLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    snake = new SnakeW;
    ui->setupUi(this);
    this->setCentralWidget(snake);
    this->resize(400, 700);
    while(1)
    {
        qDebug() << snake->done;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
