#include "dox.h"

Dox::Dox(BattleScene *battlescene,int group,int position)
    : Minion(battlescene,group,4,80,300,7,position,70,6)
    // scene group classifcation minioncost healthpoint attackpoint position attackrange walkingspeed
{
    if (group == 1) setPosition(0);
    else setPosition(MAXPOSITION);
}
