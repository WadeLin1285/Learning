#include "ditch.h"

Ditch::Ditch(BattleScene *battlescene,int group,int position)
    : Minion(battlescene,group,15,120,300,10,position,100,3)
    // scene group classifcation minioncost healthpoint attackpoint position attackrange walkingspeed
{
    if (group == 1) setPosition(0);
    else setPosition(MAXPOSITION);
}
