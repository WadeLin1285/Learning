#include "saber.h"

Saber::Saber(BattleScene *battlescene,int group,int position)
    : Minion(battlescene,group,11,60,500,7,position,70,4)
    // scene group classifcation minioncost healthpoint attackpoint position attackrange walkingspeed
{
    if (group == 1) setPosition(0);
    else setPosition(MAXPOSITION);
}
