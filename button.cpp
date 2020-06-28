#include "button.h"
#include<QPixmap>
button::button(QString pic):QPushButton(0)
{
   QPixmap pix(pic);
    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:Opx;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));
}
