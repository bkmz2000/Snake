#ifndef SNAKEW_H
#define SNAKEW_H

#include <QWidget>
#include <QPushButton>
#include <field.h>

namespace Ui {
class SnakeW;
}

class SnakeW : public QWidget
{
    Q_OBJECT

public:
    explicit SnakeW(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *);
    bool done;
    ~SnakeW();

signals:
    bool hidden();

private slots:
    void on_up_clicked();
    void on_down_clicked();
    void on_right_clicked();
    void on_left_clicked();
    void gameLoop();

private:
    Ui::SnakeW *ui;
    Field field;


};

#endif // SNAKEW_H
