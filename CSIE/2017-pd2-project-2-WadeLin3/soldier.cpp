#include "soldier.h"

Soldier::Soldier(BattleScene *battlescene,int group,int position)
    : Minion(battlescene,group,2,60,500,6,position,120,4)
    // scene group classifcation minioncost healthpoint attackpoint position attackrange walkingspeed
{
    if (group == 1) setPosition(0);
    else setPosition(MAXPOSITION);
}
