#include "shield.h"

Shield::Shield(BattleScene *battlescene,int group,int position)
    : Minion(battlescene,group,14,200,5000,0,position,50,2)
    // scene group classifcation minioncost healthpoint attackpoint position attackrange walkingspeed
{
    if (group == 1) setPosition(0);
    else setPosition(MAXPOSITION);
}

