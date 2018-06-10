#include "ninetail.h"

Ninetail::Ninetail(BattleScene *battlescene,int group,int position)
    : Minion(battlescene,group,9,500,500,25,position,500,4)
    // scene group classifcation minioncost healthpoint attackpoint position attackrange walkingspeed
{
    if (group == 1) setPosition(0);
    else setPosition(MAXPOSITION);
}
