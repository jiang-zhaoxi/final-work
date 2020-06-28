#ifndef GAMESCENCE_H
#define GAMESCENCE_H

#include <QMainWindow>
#include"tower.h"
#include"choosebutton.h"
#include"enemy.h"
#include<QList>
#include<QTimer>
class gamescence : public QMainWindow
{
    Q_OBJECT
public:
    explicit gamescence(QWidget *parent = 0);
void  paintEvent(QPaintEvent*);
tower *twr[16];
choosebutton *btn[16][7],*signbutton;
QList<enemy*>myenemy;
void setenemy();
void enemymove();
void begin();
void check();
void bulletmove();
void healthcheck();
void testdraw(QPainter*);
int gametime=0;
int money=40000,amount=60,difficult=4;
int winstate=0,losestate=0;
QPushButton*your_money,*enemy_amount;
int test;
signals:
private slots:
};
#endif // GAMESCENCE_H
