# ifndef MINION_H
# define MINION_H
int best_card(int c1,int c2,int c3,int c4,int status);
int check_tank(int c1,int c2,int c3,int c4);
int check_attack(int c1,int c2,int c3,int c4);
int check_healer(int c1,int c2,int c3,int c4);
int find_tank(int c1,int c2,int c3,int c4);
int find_attack(int c1,int c2,int c3,int c4);
int find_healer(int c1,int c2,int c3,int c4);
int check_mana(int bc,int mana);
int position_x(int mini,int sta);
int position_y(int mini,int sta);
# endif
