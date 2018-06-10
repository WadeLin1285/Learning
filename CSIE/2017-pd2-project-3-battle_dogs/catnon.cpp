#include "catnon.h"

Catnon::Catnon(BattleScene *battlescene,int group,int position)
    : Minion(battlescene,group,10,300,200,17,position,200,1)
    // scene group classifcation minioncost healthpoint attackpoint position attackrange walkingspeed
{
    if (group == 1) setPosition(0);
    else setPosition(MAXPOSITION);
}
