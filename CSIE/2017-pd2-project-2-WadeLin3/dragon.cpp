#include "dragon.h"

Dragon::Dragon(BattleScene *battlescene,int group,int position)
    : Minion(battlescene,group,5,120,4000,1,position,500,2)
    // scene group classifcation minioncost healthpoint attackpoint position attackrange walkingspeed
{
    if (group == 1) setPosition(0);
    else setPosition(MAXPOSITION);
}
