#include "bigdog.h"

Bigdog::Bigdog(BattleScene *battlescene,int group,int position)
    : Minion(battlescene,group,17,200,3000,1,position,100,1)
    // scene group classifcation minioncost healthpoint attackpoint position attackrange walkingspeed
{
    if (group == 1) setPosition(0);
    else setPosition(MAXPOSITION);
}

