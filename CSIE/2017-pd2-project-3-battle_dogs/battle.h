#ifndef BATTLE_H
#define BATTLE_H

#include<QObject>
#include<QString>
#include<QVector>
#include<QTimer>

#include"ai.h"
#include"battlescene.h"
#include"minion.h"

#include"doggy.h"
#include"soldier.h"
#include"tall.h"
#include"dox.h"
#include"dragon.h"
#include"ancient.h"
#include"commander.h"
#include"tallex.h"
#include"ninetail.h"
#include"catnon.h"
#include"bigdog.h"
#include"ditch.h"
#include"jesus.h"
#include"king.h"
#include"nija.h"
#include"robort.h"
#include"saber.h"
#include"shield.h"
#include"spartan.h"
#include"superdog.h"

#define MAXTOWERHP 2000

class Battle : public QObject
{    
    Q_OBJECT

public:
    friend class Soldier;
    friend class GameWindow;
    friend class AI;

    Battle(BattleScene* battlescene);

    QVector <Minion> minionList[MAXPOSITION]; // store the minin on the battlefield
    BattleScene *scene;

    void printList(); // use to print out the list (for debug usage)
    void addMinion(const int minionNum,int minionGroup,int minionPosition);

    void setTime(int t);
    int  getTime()const;
    int  getMoney()const;
    int  getPlayerTowerMode()const;
    int  getAITowerMode() const;
    void totalAttack();

signals:
    void end(int battleResult);
    void battlingEnd();
    void countDown(int cd);
    void newMinion(int pos,int order);
    void b(); // for test
    void playerTowerModeChange(int mode);
    void AITowerModeChange(int mode);


private:
    static int time;
    static int money,moneyAdd;
    static int P1_HP,AI_HP;
    static int playerTowerMode,AITowerMode;
    QTimer *battleTimer;
    AI *Ai;

    void battleStart();
    void updateMinion();
    void battleReset();
    void pause();
    void resume();
    void reset();

private slots:
    void battling();
};

#endif // BATTLE_H
