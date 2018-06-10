#ifndef DRAGON_H
#define DRAGON_H

#include"minion.h"

class Dragon : public Minion
{
public:
    Dragon(BattleScene *battlescene,int group, int position);
};

#endif // DRAGON_H
