#include "ai.h"

AI::AI()
{

}

int AI::action(const int time)
{
    if (time % 100 == 0) return 1;
    if (time % 150 == 0) return 2;
    if (time % 250 == 0) return 7;
    if (time % 500 == 0) return 10;

    return 0;
}
