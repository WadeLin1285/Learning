#include "commander.h"

Commander::Commander(BattleScene *battlescene,int group,int position)
    : Minion(battlescene,group,7,200,1200,12,position,170,4)
    // scene group classifcation minioncost healthpoint attackpoint position attackrange walkingspeed
{
    if (group == 1) setPosition(0);
    else setPosition(MAXPOSITION);
}
