# ifndef POSITION_H
# define POSITION_H
# define SIZE 5
// define the minion position array
//                                tank attk heal snip mana    status
const int position_x[9][SIZE] = {{   5,   4,   3,   1,  10}, // 0
                                 {   7,   9,   7,   4,  10}, // 1
                                 {21-7,21-9,21-7,21-4,  10}, // 2
                                 {   5,   4,   3,   5,  10}, // 3
                                 {21-5,21-4,21-3,21-5,  10}, // 4
                                 {   7,   9,   7,   6,  10}, // 5
                                 {21-7,21-9,21-7,21-6,  10}, // 6
                                 {   5,   4,   3,   5,  10}, // 7
                                 {21-5,21-4,21-3,21-5,  10}};// 8

const int position_y[9][SIZE] = {{  15,  13,  11,  10,   1}, // 0
                                 {   5,  10,   2,   1,   1}, // 1
                                 {   5,  10,   2,   1,   1}, // 2
                                 {  23,  22,  21,  21,   1}, // 3
                                 {  23,  22,  21,  21,   1}, // 4
                                 {  10,  10,   5,   2,   1}, // 5
                                 {  10,  10,   5,   2,   1}, // 6
                                 {  23,  21,  19,  19,   1}, // 7
                                 {  23,  21,  19,  19,   1}};// 8

int position(char dir,int mini,int sta);
# endif
