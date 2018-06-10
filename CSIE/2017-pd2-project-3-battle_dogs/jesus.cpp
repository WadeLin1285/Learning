#include "jesus.h"

Jesus::Jesus(BattleScene *battlescene,int group,int position)
    : Minion(battlescene,group,19,400,800,20,position,180,3)
    // scene group classifcation minioncost healthpoint attackpoint position attackrange walkingspeed
{
    if (group == 1) setPosition(0);
    else setPosition(MAXPOSITION);
}
