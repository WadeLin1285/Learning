#include "robort.h"

Robort::Robort(BattleScene *battlescene,int group,int position)
    : Minion(battlescene,group,13,100,1000,5,position,70,2)
    // scene group classifcation minioncost healthpoint attackpoint position attackrange walkingspeed
{
    if (group == 1) setPosition(0);
    else setPosition(MAXPOSITION);
}
