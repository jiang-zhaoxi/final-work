#include "tower.h"
#include"gamescence.h"
#include<QPainter>
tower::tower():pos(0,0),health(0),level(0),upgradefund(100),attack(0),destroymethod(0),towertype("none"){
    QPixmap img(":/tower/init.png");
    this->setFixedSize(131,165);
    this->setStyleSheet("QPushButton{border:Opx;}");
    this->setIcon(img);
    this->setIconSize(QSize(img.width(),img.height()));
}
void tower::setimg(QPixmap img)
{
    this->img=img;
}
void tower::show(QPainter *paint)
{
    paint->drawPixmap(pos.x(),pos.y(),img.width(),img.height(),img);
}
void tower::update(QString p)
{
    towertype=p;
    if(p=="knight"){
        level++;health+=100;upgradefund+=100;attack+=30;destroymethod=2;
        QPixmap newimg(":/tower/knight1.png");this->setimg(newimg);bulletpix=":/bullet/bullet1.png";
    }if(p=="wizard"){
        level++;health+=60;upgradefund+=200;attack+=30;destroymethod=0;
        QPixmap newimg(":/tower/wizard1.png");this->setimg(newimg);bulletpix=":/bullet/bullet2.png";
    }
    if(p=="archer"){
            level++;health+=50;upgradefund+=100;attack+=30;destroymethod=1;
            QPixmap newimg(":/tower/archer1.png");this->setimg(newimg);bulletpix=":/bullet/bullet3.png";
        }
    if(p=="cannon"){
            level++;health+=60;upgradefund+=300;attack+=20;destroymethod=1;distance=20;
            QPixmap newimg(":/tower/cannon1.png");this->setimg(newimg);bulletpix=":/bullet/bullet4.png";
        }
}
void tower::update()
{
    if(level==1){
    if(towertype=="knight"){
        level++;health+=100;upgradefund+=300;attack+=50;destroymethod=2;
        QPixmap newimg(":/tower/knight2.png");this->setimg(newimg);
    }if(towertype=="wizard"){
        level++;health+=90;upgradefund+=400;attack+=80;destroymethod=0;
        QPixmap newimg(":/tower/wizard2.png");this->setimg(newimg);
    }
    if(towertype=="archer"){
            level++;health+=60;upgradefund+=300;attack+=70;destroymethod=1;
            QPixmap newimg(":/tower/archer2.png");this->setimg(newimg);
        }
    if(towertype=="cannon"){
            level++;health+=90;upgradefund+=400;attack+=60;destroymethod=1;distance=50;
            QPixmap newimg(":/tower/cannon2.png");this->setimg(newimg);
        }
    }
    else if(level==2){
        if(towertype=="knight"){
            level++;health+=300;upgradefund+=99999;attack+=70;destroymethod=2;
            QPixmap newimg(":/tower/knight3.png");this->setimg(newimg);
        }if(towertype=="wizard"){
            level++;health+=100;upgradefund+=99999;attack+=140;destroymethod=0;
            QPixmap newimg(":/tower/wizard3.png");this->setimg(newimg);
        }
        if(towertype=="archer"){
                level++;health+=100;upgradefund+=99999;attack+=100;destroymethod=1;
                QPixmap newimg(":/tower/archer3.png");this->setimg(newimg);
            }
        if(towertype=="cannon"){
                level++;health+=100;upgradefund+=99999;attack+=100;destroymethod=1;distance=90;
                QPixmap newimg(":/tower/cannon3.png");this->setimg(newimg);
            }
    }
}
void tower::remove()
{
    health=0;attack=0;level=0;upgradefund=100;destroymethod=0;
    QString init("none");towertype=init;
    bulletpix=":/tower/init.png";
    QPixmap img(":/tower/init.png");
    this->setimg(img);
}
void tower::CreatBullet(){
    bullet*newbullet=new bullet(this->bulletpix,this->towertype,this->pos);
    mybullet.push_back(newbullet);
}
