#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include"button.h"
#include"gamescence.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setWindowFlags(Qt::FramelessWindowHint);//ÎÞ±ß¿ò
    setAttribute(Qt::WA_TranslucentBackground);//±³¾°Í¸Ã÷

    this->setFixedSize(1400,875);
    ui->setupUi(this);
    gamescence *scene=new gamescence;
    button *btn=new button(":/bu.png");
    btn->setParent(this);
    btn->move(150,120);
    connect(btn,&QPushButton::clicked,this,[=](){
        this->close();
        scene->show();
    });
    button *btn1=new button(":/introduction/towerintro.png");
    btn1->setParent(this);
    btn1->move(1100,50);
    button *btn2=new button(":/introduction/enemyintro.png");
    btn2->setParent(this);
    btn2->move(1200,300);
    button *btn3=new button(":/introduction/back.png");
    btn3->setParent(this);
    btn3->move(500,700);
    btn3->hide();
    connect(btn1,&QPushButton::clicked,this,[=](){
        state1=1;
        btn->hide();
        btn1->hide();
        btn2->hide();
        btn3->show();
        update();
    });
    connect(btn2,&QPushButton::clicked,this,[=](){
        state2=1;
        btn->hide();
        btn1->hide();
        btn2->hide();
        btn3->show();
        update();
    });
    connect(btn3,&QPushButton::clicked,this,[=](){
        state1=0;state2=0;
        btn->show();
        btn1->show();
        btn2->show();
        btn3->hide();
        update();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter paint(this);
    QPixmap img1(":/bac.jpg");
    paint.drawPixmap(0,0,1400,875,img1);
    if(state1==1){
     QPixmap img2(this->towerintroduce);
    paint.drawPixmap(0,0,img2);
    }
    if(state2==1){
    QPixmap img3(this->enenmyintroduce);
   paint.drawPixmap(0,0,img3);
    }
}
