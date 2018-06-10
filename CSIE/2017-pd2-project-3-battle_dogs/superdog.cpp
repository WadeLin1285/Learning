#include "superdog.h"

Superdog::Superdog(BattleScene *battlescene,int group,int position)
    : Minion(battlescene,group,18,300,800,17,position,150,4)
    // scene group classifcation minioncost healthpoint attackpoint position attackrange walkingspeed
{
    if (group == 1) setPosition(0);
    else setPosition(MAXPOSITION);
}
