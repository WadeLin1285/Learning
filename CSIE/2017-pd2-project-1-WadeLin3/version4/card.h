# ifndef CARD_H
# define CARD_H
# define TOTAL_CARD 12
/************************** card informations ************************************
* cm : card mana consum   ca : card attack point
* ch : card health point  cc : card class
* Class Definition:
*       Unvaliable = 0   
*       Normal:    Tank  = 1   Attacker= 2  Healer  = 3  
*       Special:   Buffer= 4   Sniper  = 5  Forzener= 6  
*                  Power = 7   Sgram= 8     Manar = 9
**********************************************************************************/
//      DATA ID    :   01   02   03   04   05   06   07   08   09   10   11   12
int cm[TOTAL_CARD] = {   5,   3,   4,   7,   1,   4,   9,   5,   5,   5,   5,   8};
int ca[TOTAL_CARD] = {  50,  50, 150,  10,  10, 100, 100, 200,   0,   0,   0, 100};
int ch[TOTAL_CARD] = {1500, 700, 500,3000, 300, 300,2500, 150,1000, 200, 800, 500};
int cc[TOTAL_CARD] = {   1,   3,   2,   1,   3,   2,   7,   8,   9,   4,   6,   9};
# endif
