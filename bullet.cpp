#include "bullet.h"
#include<QPainter>
#include<QTimer>
bullet::bullet(){
    speed=100;pic=QPixmap(":/tower/init.png");type="none";pos=QPoint(0,0);
}
bullet::bullet(QString pxfile,QString _type,QPoint _pos):type(_type),pos(_pos),speed(100){
    pic=QPixmap(pxfile);
}
void bullet::appear(QPainter *paint)
{
    paint->drawPixmap(this->pos,this->pic);
}
void bullet::setpos(QPoint _pos){
    pos=_pos;
}
void bullet::setpic(QString pixfile)
{
    pic=QPixmap(pixfile);
}
void bullet::settype(QString _type){
    type=_type;
}
