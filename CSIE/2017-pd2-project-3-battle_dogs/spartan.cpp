#include "spartan.h"

Spartan::Spartan(BattleScene *battlescene,int group,int position)
    : Minion(battlescene,group,16,200,2000,7,position,120,5)
    // scene group classifcation minioncost healthpoint attackpoint position attackrange walkingspeed
{
    if (group == 1) setPosition(0);
    else setPosition(MAXPOSITION);
}
