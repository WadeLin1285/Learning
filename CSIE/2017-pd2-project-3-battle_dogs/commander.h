#ifndef COMMANDER_H
#define COMMANDER_H

#include"minion.h"

class Commander : public Minion
{
public:
    Commander(BattleScene *battlescene,int group, int position);
};

#endif // COMMANDER_H
