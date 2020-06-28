#ifndef TOWER_H
#define TOWER_H
#include <QMainWindow>
#include <QWidget>
#include<QPushButton>
#include<QList>
#include"choosebutton.h"
#include"bullet.h"
class tower : public QPushButton
{
    Q_OBJECT
public:
    tower();
    QPoint pos;
    QPixmap img;
    void show(QPainter*paint);
    void setimg(QPixmap img);
    int health,level,upgradefund,attack,distance=0;
    int destroymethod;//0 for magic attack,1 for physic attack,2 for armor-invalid attack
    QString towertype,bulletpix;
    QList<bullet*>mybullet;
    void CreatBullet();
    void update();
    void update(QString);
    void remove();
signals:
};

#endif // TOWER_H
