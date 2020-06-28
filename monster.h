#ifndef MONSTER_H
#define MONSTER_H

#include <QObject>
#include<QPixmap>
#include<QPoint>
class monster : public QObject
{
    Q_OBJECT
public:
    monster();
    int health,attack;
    double PhysicalArmor,MagicalArmor,type,speed;
    QPixmap img;
    QPoint pos;
    int x,y;
    void reset(int);

signals:

};

#endif // MONSTER_H
