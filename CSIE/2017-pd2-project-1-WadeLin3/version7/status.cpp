# include "status.h"
# include <iostream>
using namespace std;

// define the data to store old status
static int main_castle_old = 10;
static int P1_castle_1_old = 10;
static int P1_castle_2_old = 10;
static int P2_castle_1_old = 10;
static int P2_castle_2_old = 10;
static int main_castle_hurt = 0;
static int P1_castle_1_hurt = 0;
static int P1_castle_2_hurt = 0;
static int P2_castle_1_hurt = 0;
static int P2_castle_2_hurt = 0;
//delay time:  (status)    0  1  2  3  4  5  6  7  8
const  int delay_time[9]={ 0, 5, 5, 5, 5, 5, 5, 5, 5}; 

int battle_status(char map[ARRAY_SIZE_2][ARRAY_SIZE_1]){
	// The health status of castles
	// full to zero: A 9 8 7 6 5 4 3 2 1 0
	char main_castle = map[22+11][ 6];
	char P1_castle_1 = map[22+ 5][ 9];  
        char P1_castle_2 = map[22+17][ 9];
        char P2_castle_1 = map[22+ 5][43];
        char P2_castle_2 = map[22+17][43];
	// change char into integer
	int main_castle_HP = ctoi(main_castle);
	int P1_castle_1_HP = ctoi(P1_castle_1);
        int P1_castle_2_HP = ctoi(P1_castle_2);
        int P2_castle_1_HP = ctoi(P2_castle_1);
        int P2_castle_2_HP = ctoi(P2_castle_2);
	/* print out the data
	cout<<"main: "<<main_castle_HP<<endl;
	cout<<"P1_1: "<<P1_castle_1_HP<<endl;
        cout<<"P1_2: "<<P1_castle_2_HP<<endl;
        cout<<"P2_1: "<<P2_castle_1_HP<<endl;
        cout<<"P2_2: "<<P2_castle_2_HP<<endl;
	*/
	// check the health status
	if (main_castle_HP < main_castle_old) main_castle_hurt = 1;
	else main_castle_hurt = 0;
        if (P1_castle_1_HP < P1_castle_1_old) P1_castle_1_hurt = 1;
	else P1_castle_1_hurt = 0;
        if (P1_castle_2_HP < P1_castle_2_old) P1_castle_2_hurt = 1;
	else P1_castle_2_hurt = 0;
        if (P2_castle_1_HP < P2_castle_1_old) P2_castle_1_hurt = 1;
	else P2_castle_1_hurt = 0;
        if (P2_castle_2_HP < P2_castle_2_old) P2_castle_2_hurt = 1;
	else P2_castle_2_hurt = 0;
	// update the storing data
	main_castle_old = main_castle_HP;
	P1_castle_1_old = P1_castle_1_HP;
	P1_castle_2_old = P1_castle_2_HP;
	P2_castle_1_old = P2_castle_1_HP;
	P2_castle_2_old = P2_castle_2_HP;
	// define the battle status
	// defend the main castle
	if      (main_castle_HP <= 5) return 1;
	else if (main_castle_hurt == 1 || (P1_castle_1_hurt == 1 && P1_castle_1_HP < 5)) return 1;
	else if (main_castle_hurt == 1 || (P1_castle_2_hurt == 1 && P1_castle_2_HP < 5)) return 2;
	// offensive
	else if (P1_castle_2_HP >= 5 && P2_castle_1_HP < 3) return 3;
	else if (P1_castle_1_HP >= 5 && P2_castle_2_HP < 3) return 4;
	// normal defense
	else if (P1_castle_1_hurt == 1) return 5;
	else if (P1_castle_2_hurt == 1) return 6;
	// normal attack
	else if (P2_castle_1_hurt == 1 || P2_castle_1_HP < 1) return 7;
	else if (P2_castle_2_hurt == 1 || P2_castle_2_HP < 1) return 8;
	// normal status
	else return 0;
}
static int old_cd = 0;
int analysis_status(int old_sta,char map[ARRAY_SIZE_2][ARRAY_SIZE_1],int cd){
	int new_sta = battle_status(map);
	if (old_sta == 0 && new_sta == 0) return 0;
	if (old_sta == 0){
		old_cd = cd;
		return new_sta;
	}
	else {
		if ((old_cd-cd) <= delay_time[old_sta]) return old_sta;
		else return battle_status(map);
	}
}
int ctoi(char x){
        if (x == 'C') return 12;
        if (x == 'B') return 11;
	if (x == 'A') return 10;
        if (x == '9') return  9;
        if (x == '8') return  8;
        if (x == '7') return  7;
        if (x == '6') return  6;
        if (x == '5') return  5;
        if (x == '4') return  4;
        if (x == '3') return  3;
        if (x == '2') return  2;
        if (x == '1') return  1;
        if (x == '0') return  0;
        if (x == ' ') return -1;
}
