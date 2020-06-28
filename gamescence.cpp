#include "gamescence.h"
#include"tower.h"
#include"button.h"
#include<QMediaPlayer>
#include<QPainter>
#include<QTimer>
#include<iostream>
using namespace std;
gamescence::gamescence(QWidget *parent) : QMainWindow(parent)
{
     int i,j,k=0;
      test=0;
      your_money=new QPushButton;
      your_money->setParent(this);
      your_money->setFont(QFont("ËÎÌו",20,0));
      your_money->setFlat(true);
      your_money->setFixedSize(400,50);
      your_money->move(125,760);
      your_money->setText(QString("%1$").arg(money));
      enemy_amount=new QPushButton;
      enemy_amount->setParent(this);
      enemy_amount->setFont(QFont("ËÎÌו",20,0));
      enemy_amount->setFlat(true);
      enemy_amount->setFixedSize(400,50);
     enemy_amount->move(1000,760);
      enemy_amount->setText(QString("%1").arg(amount));
     this->setFixedSize(1400,875);
     button* beginbutton=new button(":/button/callon.png");
     beginbutton->setParent(this);
     beginbutton->move(625,700);
     signbutton=new choosebutton;
     signbutton->setParent(this);
     signbutton->setFont(QFont("Arial",30,0));
     signbutton->setFlat(true);
     signbutton->setFixedSize(400,100);
     signbutton->setText(" ");
     signbutton->hide();
     connect(beginbutton,&QPushButton::clicked,this,[=](){
         beginbutton->close();
         signbutton->move(500,725);
         signbutton->show();
     });
   for(i=0;i<4;i++){
       for(j=0;j<4;j++){
           twr[k]=new tower;
           twr[k]->setParent(this);
           twr[k]->pos.setX(100+j*130);
           twr[k]->pos.setY(40+165*i);
           twr[k]->move(100+j*130,40+165*i);
           k++;
       }
   }
   for(i=0;i<16;i++)
   { QPixmap ex(":/tower/init.png");twr[i]->setimg(ex);}
   for(i=0;i<16;i++){
       for(j=0;j<7;j++){
           btn[i][j]=new choosebutton;
           btn[i][j]->setParent(this);
           if(j==0){btn[i][j]->setText(QString("knight %1$").arg(twr[i]->upgradefund));}
           else if(j==1){btn[i][j]->setText(QString("archer %1$").arg(twr[i]->upgradefund));}
           else if(j==2){btn[i][j]->setText(QString("wizard %1$").arg(twr[i]->upgradefund));}
           else if(j==3){btn[i][j]->setText(QString("cannon %1$").arg(twr[i]->upgradefund));}
           else if(j==4){btn[i][j]->setText("close");}
           else if(j==5){btn[i][j]->setText("remove");}
           else {btn[i][j]->setText("update");}
           btn[i][j]->hide();
       }
   }
   for(i=0;i<16;i++)
   {
       connect(twr[i],&QPushButton::clicked,twr[i],[=](){
           int k;
           if(twr[i]->level==0){
           for(k=0;k<5;k++){
           btn[i][k]->move(twr[i]->pos.x(),twr[i]->pos.y()+40*(k+2));
           btn[i][k]->show();
           }
           }
           else if(twr[i]->level==1||twr[i]->level==2){
               for(k=5;k<7;k++){
                   btn[i][k]->move(twr[i]->pos.x(),twr[i]->pos.y()+40*(k-3));
                   btn[i][k]->show();
               }
               btn[i][4]->move(twr[i]->pos.x(),twr[i]->pos.y()+40*4);
               btn[i][4]->show();
           }
           else{
               btn[i][5]->move(twr[i]->pos.x(),twr[i]->pos.y()+40*2);
               btn[i][5]->show();
               btn[i][4]->move(twr[i]->pos.x(),twr[i]->pos.y()+40*3);
               btn[i][4]->show();
           }
       });
       connect(btn[i][0],&QPushButton::clicked,twr[i],[=](){
           btn[i][0]->hide();btn[i][1]->hide();btn[i][2]->hide();btn[i][3]->hide();btn[i][4]->hide();
           QString type("knight");
           if(money-twr[i]->upgradefund>=0){
           money-=twr[i]->upgradefund;
           your_money->setText(QString("%1").arg(money));
           twr[i]->update(type);
           btn[i][6]->setText(QString("update %1$").arg(twr[i]->upgradefund));}
           else{
               signbutton->setText("no money");
               QTimer::singleShot(2000,signbutton,[=](){
                   signbutton->setText(" ");
               });
           }
       });
       connect(btn[i][1],&QPushButton::clicked,twr[i],[=](){
           btn[i][0]->hide();btn[i][1]->hide();btn[i][2]->hide();btn[i][3]->hide();btn[i][4]->hide();
           QString type("archer");
           if(money-twr[i]->upgradefund>=0){
           money-=twr[i]->upgradefund;
           your_money->setText(QString("%1$").arg(money));
           twr[i]->update(type);
           btn[i][6]->setText(QString("update %1$").arg(twr[i]->upgradefund));}
           else{
               signbutton->setText("no money");
               QTimer::singleShot(2000,signbutton,[=](){
                   signbutton->setText(" ");
               });
           }
       });
       connect(btn[i][2],&QPushButton::clicked,twr[i],[=](){
           btn[i][0]->hide();btn[i][1]->hide();btn[i][2]->hide();btn[i][3]->hide();btn[i][4]->hide();
           QString type("wizard");
           if(money-twr[i]->upgradefund>=0){
           money-=twr[i]->upgradefund;
           your_money->setText(QString("%1$").arg(money));
           twr[i]->update(type);
           btn[i][6]->setText(QString("update %1$").arg(twr[i]->upgradefund));}
           else{
               signbutton->setText("no money");
               QTimer::singleShot(2000,signbutton,[=](){
                   signbutton->setText(" ");
               });
           }
       });
       connect(btn[i][3],&QPushButton::clicked,twr[i],[=](){
           btn[i][0]->hide();btn[i][1]->hide();btn[i][2]->hide();btn[i][3]->hide();btn[i][4]->hide();
           QString type("cannon");
           if(money-twr[i]->upgradefund>=0){
           money-=twr[i]->upgradefund;
           your_money->setText(QString("%1$").arg(money));
           twr[i]->update(type);
           btn[i][6]->setText(QString("update %1$").arg(twr[i]->upgradefund));}
           else{
               signbutton->setText("no money");
               QTimer::singleShot(2000,signbutton,[=](){
                   signbutton->setText(" ");
               });
           }
       });
       connect(btn[i][4],&QPushButton::clicked,twr[i],[=](){
           btn[i][0]->hide();btn[i][1]->hide();btn[i][2]->hide();btn[i][3]->hide();btn[i][4]->hide();
           btn[i][5]->hide();btn[i][6]->hide();
       });
       connect(btn[i][5],&QPushButton::clicked,twr[i],[=](){
           btn[i][4]->hide();btn[i][5]->hide();btn[i][6]->hide();
           twr[i]->remove();
       });
       connect(btn[i][6],&QPushButton::clicked,twr[i],[=](){
           btn[i][4]->hide();btn[i][5]->hide();btn[i][6]->hide();
           if(money-twr[i]->upgradefund>=0){
           money-=twr[i]->upgradefund;
           your_money->setText(QString("%1$").arg(money));
           twr[i]->update();
           btn[i][6]->setText(QString("update %1$").arg(twr[i]->upgradefund));}
           else{
               signbutton->setText("no money");
               QTimer::singleShot(2000,signbutton,[=](){
                   signbutton->setText(" ");
               });
           }
       });
   }
   QTimer*timer=new QTimer(this);
   connect(timer,&QTimer::timeout,this,[=](){update();});
   timer->start(50);
   connect(beginbutton,&QPushButton::clicked,this,&gamescence::begin);
   connect(beginbutton,&QPushButton::clicked,beginbutton,&QPushButton::close);
}
void gamescence::testdraw(QPainter *paint)
{
    QPixmap test(":/bu.png");
    paint->drawPixmap(QPoint(140,500),test);
}
void gamescence::paintEvent(QPaintEvent *)
{
int i;
QPainter paint(this);
QPixmap img(":/scene.png");
QPixmap picture1(":/winbac.jpg");
QPixmap picture2(":/losebac.png");
paint.drawPixmap(0,0,1400,875,img);
for(i=0;i<16;i++){
    this->twr[i]->show(&paint);
}
foreach(enemy*enemy,myenemy){
    enemy->appear(&paint);
}
for(i=0;i<16;i++){
foreach(bullet*bullet,twr[i]->mybullet)
    bullet->appear(&paint);
}
if(winstate==1){
    paint.drawPixmap(0,0,1400,875,picture1);
    QTimer::singleShot(4000,this,[=](){this->close();
    });
}
if(losestate==1){
    paint.drawPixmap(0,0,1400,875,picture2);
QTimer::singleShot(4000,this,[=](){this->close();
});
}
}
void gamescence::setenemy()
{
    int AppearLine=rand()%10;
    if(AppearLine<=2){
    enemy*newenemy=new enemy(QPoint(1200,40),rand()%difficult);
    myenemy.push_back(newenemy);
    }
    else if(AppearLine==3||AppearLine==4){
    enemy*newenemy=new enemy(QPoint(1200,40+165),rand()%difficult);
    myenemy.push_back(newenemy);
    }
    else if(AppearLine==5||AppearLine==6){
    enemy*newenemy=new enemy(QPoint(1200,40+165*2),rand()%difficult);
    myenemy.push_back(newenemy);
    }
    else {
    enemy*newenemy=new enemy(QPoint(1200,40+165*3),rand()%difficult);
    myenemy.push_back(newenemy);
    }
}
void gamescence::enemymove()
{
    foreach(enemy*enemy,myenemy)
        {
            int line=(enemy->pos.y()-40)/165;
            if(enemy->pos.x()<=0){
                losestate=1;
                 update();
            }
            for(int i=4*line+3;i>=4*line;i--){
                if(enemy->pos.x()-twr[i]->pos.x()<50&&enemy->pos.x()-twr[i]->pos.x()>0&&twr[i]->level!=0){
                    twr[i]->health=int((twr[i]->health*10-enemy->attack/4)/10);
                    break;
                }
                if(i==4*line)
                    enemy->pos.setX(enemy->pos.x()-enemy->speed);
            }
        }
    }
void gamescence::begin(){
    QTimer*timer1=new QTimer(this);
    connect(timer1,&QTimer::timeout,this,[=](){this->setenemy();gametime++;
    });
    timer1->start(3000);
    QTimer*timer2=new QTimer(this);
    connect(timer2,&QTimer::timeout,this,&gamescence::enemymove);
    timer2->start(50);
    QTimer*timer3=new QTimer(this);
    connect(timer3,&QTimer::timeout,this,&gamescence::check);
    timer3->start(1250);
    QTimer*timer4=new QTimer(this);
    connect(timer4,&QTimer::timeout,this,&gamescence::bulletmove);
    timer4->start(100);
    QTimer::singleShot(500,this,[=](){
        QMediaPlayer * player = new QMediaPlayer;
        player->setMedia(QUrl("qrc:/bgm/gamebgm.mp3"));
        player->setVolume(20);
        player->play();
    });
    QTimer*music=new QTimer(this);
    connect(music,&QTimer::timeout,this,[=](){
        QMediaPlayer * player = new QMediaPlayer;
        player->setMedia(QUrl("qrc:/bgm/gamebgm.mp3"));
        player->setVolume(20);
        player->play();
    });
    music->start(45000);
    QTimer*timer5=new QTimer(this);
    connect(timer5,&QTimer::timeout,this,&gamescence::healthcheck);
    timer5->start(500);
}
void gamescence::check()
{
    int i;
    for(i=0;i<16;i++){
        foreach(enemy*enemy,myenemy){
            if(enemy->pos.y()==twr[i]->pos.y()&&twr[i]->level!=0&&enemy->pos.x()>=twr[i]->pos.x()){
                         this->twr[i]->CreatBullet();
                        break;
                    }
                }

             }
}
void gamescence::bulletmove()
{
    for(int i=0;i<16;i++)
        foreach(bullet*bullet,twr[i]->mybullet){
            bullet->pos.setX(bullet->pos.x()+bullet->speed);
            foreach(enemy*enemy,myenemy)
                if((qAbs(enemy->pos.x()-bullet->pos.x())<50&&enemy->pos.y()==bullet->pos.y())||bullet->pos.x()>1200){
                    if(bullet->type=="knight")
                        enemy->health-=twr[i]->attack;
                    else if(bullet->type=="wizard")
                         enemy->health-=twr[i]->attack*(int(10-enemy->MagicalArmor*10))/10;
                    else if(bullet->type=="archer")
                         enemy->health-=twr[i]->attack*(int(10-enemy->PhysicalArmor*10))/10;
                    else{
                         enemy->health-=twr[i]->attack*(int(10-enemy->PhysicalArmor*10))/10;
                         enemy->pos.setX(enemy->pos.x()+twr[i]->distance);
                    }
                    twr[i]->mybullet.removeOne(bullet);
                    delete bullet;
                }
            }
}
void gamescence::healthcheck(){
    foreach(enemy*enemy,myenemy)
        if(enemy->health<=0){
            myenemy.removeOne(enemy);
            money+=enemy->fund;
            your_money->setText(QString("%1$").arg(money));
            delete enemy;
            amount--;enemy_amount->setText(QString("%1").arg(amount));
            if(amount==40){
                difficult=3;
                signbutton->setText("Warning!");
                QTimer::singleShot(2000,signbutton,[=](){
                    signbutton->setText("Big wave!");
            });
                QTimer::singleShot(3000,signbutton,[=](){
                    signbutton->setText(" ");
            });
        }
         if(amount==0){
             winstate=1;
             update();
         }
        }
    for(int i=0;i<16;i++){
        if(twr[i]->health<=0)
            twr[i]->remove();
}
}
