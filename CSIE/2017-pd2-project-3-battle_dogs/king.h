#ifndef KING_H
#define KING_H

#include"minion.h"

class King : public Minion
{
public:
    King(BattleScene *battlescene,int group, int position);
};

#endif // KING_H
