/*************************************
* Store the minions status and info
* and creat the each minion's data.
* No: number of minion
* AP: attack point
* HP: health point
* MP: mana point
* CL: class of minion
*     [attack tank support special power]
* RA: race of minion
* SP: speed 
*************************************/
# include <string>
# include "minion.h"
# define total 12

minion::minion(char N){
	                       //  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,  7 ,  8 ,  9 , 10 , 11 , 12 //
	int attack_point[total]={  50, -50, 150,  10, -10, 100, 100, 200,   0,   0,   0, 100};
	int health_point[total]={1500, 700, 500,3000, 300, 300,2500,1500,1000, 200, 800, 500};
	int mana_point[total]  ={   5,   3,   4,   7,   1,   4,   9,   5,   5,   5,   5,   8};
	int speed[total]       ={   3,   2,   4,   2,   3,   3,   1,   1,   3,   3,   2,   2};
	if (N == '1'){
			No = 1;
			AP = attack_point[No-1];
			HP = health_point[No-1];
			MP = mana_point[No-1];
			CL = "tank";
			RA = "human";
			SP = speed[No-1];
	}
	else if (N == '2'){
                        No = 2;
                        AP = attack_point[No-1];
                        HP = health_point[No-1];
                        MP = mana_point[No-1];
                        CL = "support";
                        RA = "human";
                        SP = speed[No-1];
        }
        else if (N == '3'){
                        No = 3;
                        AP = attack_point[No-1];
                        HP = health_point[No-1];
                        MP = mana_point[No-1];
                        CL = "attack";
                        RA = "human";
                        SP = speed[No-1];
        }
        else if (N == '4'){
                        No = 4;
                        AP = attack_point[No-1];
                        HP = health_point[No-1];
                        MP = mana_point[No-1];
                        CL = "tank";
                        RA = "elf";
                        SP = speed[No-1];
        }
        else if (N == '5'){
                        No = 5;
                        AP = attack_point[No-1];
                        HP = health_point[No-1];
                        MP = mana_point[No-1];
                        CL = "support";
                        RA = "elf";
                        SP = speed[No-1];
        }
        else if (N == '6'){
                        No = 6;
                        AP = attack_point[No-1];
                        HP = health_point[No-1];
                        MP = mana_point[No-1];
                        CL = "attack";
                        RA = "elf";
                        SP = speed[No-1];
        }
        else if (N == '7'){
                        No = 7;
                        AP = attack_point[No-1];
                        HP = health_point[No-1];
                        MP = mana_point[No-1];
                        CL = "defend";
                        RA = "undead";
                        SP = speed[No-1];
        }
        else if (N == '8'){
                        No = 8;
                        AP = attack_point[No-1];
                        HP = health_point[No-1];
                        MP = mana_point[No-1];
                        CL = "sgram";
                        RA = "sgram";
                        SP = speed[No-1];
        }
        else if (N == '9'){
                        No = 9;
                        AP = attack_point[No-1];
                        HP = health_point[No-1];
                        MP = mana_point[No-1];
                        CL = "power";
                        RA = "elf";
                        SP = speed[No-1];
        }
        else if (N == 'A'){
                        No = 10;
                        AP = attack_point[No-1];
                        HP = health_point[No-1];
                        MP = mana_point[No-1];
                        CL = "support";
                        RA = "human";
                        SP = speed[No-1];
        }
        else if (N == 'B'){
                        No = 11;
                        AP = attack_point[No-1];
                        HP = health_point[No-1];
                        MP = mana_point[No-1];
                        CL = "frozon";
                        RA = "undead";
                        SP = speed[No-1];
        }
        else if (N == 'C'){
                        No = 12;
                        AP = attack_point[No-1];
                        HP = health_point[No-1];
                        MP = mana_point[No-1];
                        CL = "sniper";
                        RA = "human";
                        SP = speed[No-1];
	}
}
char minion::getNo(){ 
	switch (No) {
		case 1: return '1';
                case 2: return '2';
                case 3: return '3';
                case 4: return '4';
                case 5: return '5';
                case 6: return '6';
                case 7: return '7';
                case 8: return '8';
                case 9: return '9';
                case 10: return 'A';
                case 11: return 'B';
                case 12: return 'C';
	}
}
int minion::getAP(){ return AP; }
int minion::getMP(){ return MP; }
string minion::getCL(){ return CL; }
int minion::getSP(){ return SP; }
