#include "minion.h"
#include<iostream>

Minion::Minion()
{
    //
}

Minion::Minion(BattleScene *battlescene,int gp,int classifcation,int minioncost,int healthpoint,int attackpoint,
               int position,int attackrange,int walkingspeed):
    scene(battlescene),
    group(gp),
    cls(classifcation),
    cost(minioncost),
    hp(healthpoint),
    ap(attackpoint),
    pos(position),
    atkrange(attackrange),
    walkspeed(walkingspeed)
{
    // set card animation
    minionAnimate = new Animate(cls,scene,group);

    // initialize record value
    record = false;
}

int Minion::minion_number = 0;

void Minion::setHP(int healthpoint)   { hp = healthpoint; }
void Minion::setAP(int attackpoint)   { ap = attackpoint; }
void Minion::setPosition(int position){ pos = position; }
void Minion::setRecord(bool re)       { record = re; }
void Minion::setState(int st)         { state = st; }
void Minion::recordErase()            { record = false; }
int  Minion::getGP() const            { return group; }
int  Minion::getCost() const          { return cost; }
int  Minion::getHP() const            { return hp; }
int  Minion::getAP() const            { return ap; }
int  Minion::getPosition() const      { return pos; }
int  Minion::getClass()const          { return cls; }
int  Minion::getAttackRange() const   { return atkrange; }
int  Minion::getWalkingSpeed() const  { return walkspeed; }
bool Minion::getRecord() const        { return record; }
int  Minion::getState() const         { return state; }

void Minion::injury(int enemyATK) { hp -= enemyATK; }

void Minion::attack()
{
    minionAnimate->attack();
}

void Minion::walk()
{
    minionAnimate->walk();
}

void Minion::dead()
{
    delete minionAnimate;
}
