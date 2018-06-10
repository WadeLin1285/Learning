#include "king.h"

King::King(BattleScene *battlescene,int group,int position)
    : Minion(battlescene,group,20,500,1000,25,position,200,2)
    // scene group classifcation minioncost healthpoint attackpoint position attackrange walkingspeed
{
    if (group == 1) setPosition(0);
    else setPosition(MAXPOSITION);
}
