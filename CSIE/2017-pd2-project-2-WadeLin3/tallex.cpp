#include "tallex.h"

TallEX::TallEX(BattleScene *battlescene,int group,int position)
    : Minion(battlescene,group,8,250,2000,10,position,120,4)
    // scene group classifcation minioncost healthpoint attackpoint position attackrange walkingspeed
{
    if (group == 1) setPosition(0);
    else setPosition(MAXPOSITION);
}
