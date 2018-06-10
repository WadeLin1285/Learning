#ifndef SOLDIER_H
#define SOLDIER_H

#include"minion.h"

class Soldier : public Minion
{
public:
    Soldier(BattleScene *battlescene,int group, int position);
};

#endif // SOLDIER_H
