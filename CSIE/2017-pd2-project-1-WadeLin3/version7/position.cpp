# include "position.h"
const int ccc[12]={1,3,2,1,3,2,7,8,9,4,6,9};
/*# define SIZE 5
 define the minion position array
//                                tank attk heal snip mana    status
const int position_x[9][SIZE] = {{   5,   4,   3,   1,  10}, // 0
				 {   7,   5,   5,   4,  11}, // 1
                                 {21-7,21-5,21-5,21-4,  10}, // 2
                                 {   5,   4,   3,   5,  10}, // 3
                                 {21-5,21-4,21-3,21-5,  10}, // 4
                                 {   7,   7,   7,   6,  10}, // 5
                                 {21-7,21-7,21-7,21-6,  11}, // 6
                                 {   5,   4,   3,   5,  10}, // 7
                                 {21-5,21-4,21-3,21-5,  10}};// 8

const int position_y[9][SIZE] = {{  15,  13,  11,  10,   1}, // 0
                                 {   5,   3,   2,   1,   1}, // 1
                                 {   5,   3,   2,   1,   1}, // 2
                                 {  23,  22,  21,  21,   1}, // 3
                                 {  23,  22,  21,  21,   1}, // 4
                                 {   9,   7,   5,   2,   1}, // 5
                                 {   9,   7,   5,   2,   1}, // 6
                                 {  23,  21,  19,  19,   1}, // 7
                                 {  23,  21,  19,  19,   1}};// 8
*/
int position(char dir,int mini,int sta){
	// determine the direction ( x or y )
	if (dir == 'x'){
		if (mini == 12) {
			if (sta == 0 || (sta%2) == 1) return 10;
			else return 11;
		}
		if (ccc[mini-1]==1) return position_x[sta][0]; // tank
                if (ccc[mini-1]==2) return position_x[sta][1]; // attack
                if (ccc[mini-1]==3) return position_x[sta][2]; // healer
                if (ccc[mini-1]==5) return position_x[sta][3]; // sniper
                if (ccc[mini-1]==9) return position_x[sta][4]; // manar
	}
	else if (dir == 'y'){
		if (mini == 12) return 10;
                if (ccc[mini-1]==1) return position_y[sta][0]; // tank
                if (ccc[mini-1]==2) return position_y[sta][1]; // attack
                if (ccc[mini-1]==3) return position_y[sta][2]; // healer
                if (ccc[mini-1]==5) return position_y[sta][3]; // sniper
                if (ccc[mini-1]==9) return position_y[sta][4]; // manar
	}
	else return 10;
}

