#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QFile>
#include <QTextStream>

#include "battlescene.h"
#include "battle.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();
    void setCard(int card_1,int card_2,int card_3,int card_4,int card_5,int card_6,int card_7);
    void displayCard();
    void reset();
    void playerName(QString name);

signals:
    void quit();

private:
    Ui::GameWindow *ui;
    Battle *battle; // the main object of game
    BattleScene *scene;
    QString playername;
    static int disk[7];
    static int money[20];
    static int battleTime,fireTime;
    static int position_y,position_x_min,position_x_max;

    void initTower();
    void checkMoney();
    void setNoticeVisible(bool visible);
    void setNoticeEnable(bool able);
    void setButtonEnable(bool able);
    QString selectPath(int num);

private slots:
    void updating();
    void countDown(int cd);
    void addMinion_1(bool press);
    void addMinion_2(bool press);
    void addMinion_3(bool press);
    void addMinion_4(bool press);
    void addMinion_5(bool press);
    void addMinion_6(bool press);
    void addMinion_7(bool press);
    void closeSlot(bool press);
    void pauseSlot(bool press);
    void LeftButtonAction();
    void RightButtonAction();
    void displayNewMinion(int pos,int order);
    void result(int battleResult);
    void playerTowerMode(int mode);
    void AITowermode(int mode);
    void fire(bool press);
    void fireEnd();
};

#endif // GAMEWINDOW_H
