#ifndef DOGGY_H
#define DOGGY_H

#include"minion.h"

class Doggy : public Minion
{
public:
    Doggy(BattleScene *battlescene,int group, int position);
};

#endif // DOGGY_H
