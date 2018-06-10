#include "tall.h"

Tall::Tall(BattleScene *battlescene,int group,int position)
    : Minion(battlescene,group,3,60,1500,3,position,50,2)
    // scene group classifcation minioncost healthpoint attackpoint position attackrange walkingspeed
{
    if (group == 1) setPosition(0);
    else setPosition(MAXPOSITION);
}
