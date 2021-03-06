#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "snakew.h"
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:
    void gameOver();
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    SnakeW *snake;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
