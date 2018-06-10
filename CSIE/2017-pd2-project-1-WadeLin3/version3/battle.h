/************************************************
* The strategy of battle.
* Choose the best card to sumon.
************************************************/
# include "minion.h"
# include <string>

# ifndef BATTLE_H
# define BATTLE_H
char choose_best_card(minion a,minion b,minion c,minion d);
char find_power(minion a,minion b,minion c,minion d);
char find_tank(minion a,minion b,minion c,minion d);
char find_attack(minion a,minion b,minion c,minion d);
char find_support(minion a,minion b,minion c,minion d);
int position_x(int status,char x);
int position_y(int status,char x);
# endif
