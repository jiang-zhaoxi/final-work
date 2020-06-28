#include "enemy.h"
#include <QObject>
#include<QPixmap>
#include<QPoint>
#include<QPainter>
enemy::enemy(QPoint _pos,int _type) : QObject(0),type(_type),pos(_pos)
{
    if(type==3)//3 for normal,0 for rifeman, 1 for master, 2 for knight
    {
    health=300;attack=20;img=QPixmap(":/enemy/normal.png");
    PhysicalArmor=0.0;MagicalArmor=0.0;speed=3;fund=200;
    }
    if(type==0)
    {
    health=250;attack=100;img=QPixmap(":/enemy/rifleman.png");
    PhysicalArmor=0.0;MagicalArmor=0.0;speed=5;fund=300;
    }
    if(type==1)
    {
    health=300;attack=60;img=QPixmap(":/enemy/master.png");
    PhysicalArmor=0.5;MagicalArmor=0.6;speed=3;fund=600;
    }
    if(type==2)
    {
    health=500;attack=80;img=QPixmap(":/enemy/knight.png");
    PhysicalArmor=0.8;MagicalArmor=0.0;speed=2;fund=1000;
    }
}
void enemy::appear(QPainter *paint)
{
    paint->drawPixmap(pos,img);
}
