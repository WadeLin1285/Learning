#include<iostream>
#include<QString>
#include<QVector>

#include"battle.h"
#include"soldier.h"

using namespace std;

int main(){
    Battle *battle;
    battle = new Battle();

    battle->list();

    Minion *newMinion;
    newMinion = new Soldier(1,0);

    battle->addMinion("Soldier");

    battle->list();

    return 0;
}


