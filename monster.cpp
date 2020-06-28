#include "monster.h"

//type:0 for normol monster,1 for rifleman, 2 for mauler, 3 for master
monster::monster():health(0),attack(0),speed(0),PhysicalArmor(0.0),MagicalArmor(0.0),type(0),QObject(0)
{
    QPixmap img(":/tower/init.png");
}

void monster::reset(int a)
{
    if(a==0){
        QPixmap img(":/tower/build.png");
        this->img=img;
        this->pos.setX(1200);
        this->pos.setY(70);
        this->x=1200;this->y=70;
    }
}
