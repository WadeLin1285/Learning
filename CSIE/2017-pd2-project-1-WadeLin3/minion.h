# ifndef MINION_H
# define MINION_H
int best_card(int c1,int c2,int c3,int c4,int status,int chock);
int check_tank(int c1,int c2,int c3,int c4);
int check_attack(int c1,int c2,int c3,int c4);
int check_healer(int c1,int c2,int c3,int c4);
int find_card(int c1,int c2,int c3,int c4,int cls);
int find_minion(int c1,int c2,int c3,int c4,int Num);
//int find_tank(int c1,int c2,int c3,int c4);
//int find_attack(int c1,int c2,int c3,int c4);
//int find_healer(int c1,int c2,int c3,int c4);
int check_mana(int bc,int mana);
int compare_healer_amount();
int compare_attack_tank();
//int position_x(int mini,int sta);
//int position_y(int mini,int sta);
# endif
