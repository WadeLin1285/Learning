#ifndef SHIELD_H
#define SHIELD_H

#include"minion.h"

class Shield : public Minion
{
public:
    Shield(BattleScene *battlescene,int group, int position);
};

#endif // SHIELD_H
