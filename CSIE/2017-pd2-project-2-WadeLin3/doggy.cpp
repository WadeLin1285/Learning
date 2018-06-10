#include "doggy.h"

Doggy::Doggy(BattleScene *battlescene,int group,int position)
    : Minion(battlescene,group,1,30,500,5,position,50,3)
    // scene group classifcation minioncost healthpoint attackpoint position attackrange walkingspeed
{
    if (group == 1) setPosition(0);
    else setPosition(MAXPOSITION);
}
