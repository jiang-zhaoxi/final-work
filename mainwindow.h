#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void  paintEvent(QPaintEvent*);
    QString enenmyintroduce=":/introduction/enemyintr.png",towerintroduce=":/introduction/towerintr.png";
    int state1=0,state2=0;
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
