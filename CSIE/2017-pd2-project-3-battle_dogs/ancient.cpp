#include "ancient.h"

Ancient::Ancient(BattleScene *battlescene,int group,int position)
    : Minion(battlescene,group,6,100,1000,3,position,120,6)
    // scene group classifcation minioncost healthpoint attackpoint position attackrange walkingspeed
{
    if (group == 1) setPosition(0);
    else setPosition(MAXPOSITION);
}
