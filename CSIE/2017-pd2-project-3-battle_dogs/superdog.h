#ifndef SUPERDOG_H
#define SUPERDOG_H

#include"minion.h"

class Superdog : public Minion
{
public:
    Superdog(BattleScene *battlescene,int group, int position);
};

#endif // SUPERDOG_H
