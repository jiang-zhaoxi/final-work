#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include<QPixmap>
#include<QPoint>
class enemy : public QObject
{
    Q_OBJECT
public:
    enemy(QPoint _pos,int _type);
    int health,attack,type,fund;
    double PhysicalArmor,MagicalArmor,speed;
    QPixmap img;
    QPoint pos;
    void appear(QPainter*paint);
signals:

};

#endif // ENEMY_H
