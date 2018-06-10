#ifndef MINION_H
#define MINION_H


#include<QString>
#include<QVector>

#include"card.h"
#include"animate.h"
#include"battlescene.h"

class Minion
{

public:
    //friend class battlescene; // need to modified

    Minion();
    Minion(BattleScene *battlescene,int gp,int classifcation ,int minioncost,int healthpoint,
           int attackpoint,int position,int attackrange,int walkingspeed);

    // setting data
    void setHP(int healthpoint);
    void setAP(int attackpoint);
    void setPosition(int position);
    void setRecord(bool re);
    void setState(int st);

    // erase the record
    void recordErase();

    // getting the data
    int getGP()const;
    int getCost()const;
    int getHP()const;
    int getAP()const;
    int getPosition()const;
    int getClass()const;
    int getAttackRange()const;
    int getWalkingSpeed()const;
    bool getRecord()const;
    int getState()const;

    // minion actions
    void injury(int enemyATK); // minion is attacked by enemy
    void attack();
    void walk();
    void dead();

    // card picture and animations
    QPixmap image;
    Animate *minionAnimate;
    BattleScene *scene;

private:
    int group,cls,cost,hp,ap,pos,atkrange,walkspeed;
    int state = 0; // use to store the state of minion : 0->walk; 1->attack
    bool record; // use to record the minion action (T for having modified)
    static int minion_number;


};

#endif // MINION_H
