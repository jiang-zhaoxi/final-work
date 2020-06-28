#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include<QPixmap>
#include<QPoint>
class bullet : public QObject
{
    Q_OBJECT
public:
    bullet();
    bullet(QString pxfile,QString _type,QPoint);
    int speed;QPixmap pic;QString type;QPoint pos;
    void appear(QPainter*);
    void settype(QString);
    void setpos(QPoint);
    void setpic(QString);
signals:

};

#endif // BULLET_H
