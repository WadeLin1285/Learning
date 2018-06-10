#include "nija.h"

Nija::Nija(BattleScene *battlescene,int group,int position)
    : Minion(battlescene,group,12,80,200,12,position,120,6)
    // scene group classifcation minioncost healthpoint attackpoint position attackrange walkingspeed
{
    if (group == 1) setPosition(0);
    else setPosition(MAXPOSITION);
}
