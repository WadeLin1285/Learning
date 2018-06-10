/************************************************************
* PROJECT NO.1
* Author  : Wade Lin
* Title   : project for AI gamer design
* Modified: 2017/03/25
*************************************************************/
# include "minion.h"
# include "status.h"
# include "position.h"
# include <iostream>
# include <string>

using namespace std;
void choose_card(char a,char b,char c,char d,char e,char f,char g,char h);
void sumon(int card,int sta);
void sumon_end();
int  check_reverse(int c1,int c2,int c3,int c4,int sta2);
int  reverse_minion(int c1,int c2,int c3,int c4,int sta3);

static int count = 0,reverse = 0,reverse_count = 0;
static int dx,dy;

int main(){
	// sever info. data
	int cd = 180,mana,c1,c2,c3,c4;
	char C1,C2,C3,C4;
	// best card and battle status
	int bc,status = 0;
	char map[ARRAY_SIZE_2][ARRAY_SIZE_1];
	// choose cards
	//choose_card('1','2','3','4','5','6','7','8');
	//choose_card('9','1','5','3','2','4','6','C');
	choose_card('9','1','5','3','2','4','6','8');
	// AI
	while(cd > 0){
		cin >> cd >> mana >> C1 >> C2 >> C3 >> C4;
		dx = cd % 3 - 1;
		/*
		cout <<"C1 : "<<C1<<endl;
		cout <<"C2 : "<<C2<<endl;
		cout <<"C3 : "<<C3<<endl;
		cout <<"C4 : "<<C4<<endl;
		*/
		c1 = ctoi(C1);
                c2 = ctoi(C2);
                c3 = ctoi(C3);
                c4 = ctoi(C4);
		/*  
		cout <<"c1 : "<<c1<<endl;
                cout <<"c2 : "<<c2<<endl;
                cout <<"c3 : "<<c3<<endl;
                cout <<"c4 : "<<c4<<endl;
		*/
        	// scan the map
		for (int i=0;i<ARRAY_SIZE_2;i++){ 
			cin.getline(map[i],ARRAY_SIZE_1);
		}
		//cout << "count: "<<count<<endl;
		//cout << "reverse: "<<reverse<<endl;
		//cout << "r_count: "<<reverse_count<<endl;
		// analysis the battle status
		status = analysis_status(status,map,cd);
		//reverse = check_reverse(c1,c2,c3,c4,status);
		// use status and in-hand card to choose the best card
		// REVERSE
		/*
		if (reverse_count > 2) {
                	count = 0;
                        reverse_count = 0;
                        reverse = 0;
                }
		if (reverse == 1) {
			if (reverse_count == 0) bc = 4;
			else if (reverse_count == 1) bc = find_card(c1,c2,c3,c4,2);
			else if (reverse_count == 2) bc = find_card(c1,c2,c3,c4,2);
			else bc = best_card(c1,c2,c3,c4,status);
			// check mana
			if (check_mana(bc,mana) == 1){
                                //cout<<"mana in enough,best card: "<<bc<<endl;
                                sumon(bc,status);
                                sumon_end();
                                reverse_count++;
                        }
			else sumon_end();
		}
		*/
		bc = best_card(c1,c2,c3,c4,status);
		// check mana
		if (check_mana(bc,mana) == 1){
			//cout<<"mana in enough,best card: "<<bc<<endl;
			sumon(bc,status);
			sumon_end();
			count++;
                }
                else sumon_end();
	}
	return 0;
}
void choose_card(char a,char b,char c,char d,char e,char f,char g,char h){
	cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<" "<<g<<" "<<h<<endl;
}
void sumon(int card,int sta){
	int x = position('x',card,sta);
	int y = position('y',card,sta);
	static int start = 0;
	if (sta != 1 && sta != 2 && sta != 5 && sta != 6 && count % 15 >= 10) {
		if (card == 1 || card == 4) {x = 20 - x;start = 1;}
		else if (start == 1) x = 20 - x;
		else count--;
	}
	x = x + dx;
	//if ((sta == 0 || sta == 3 || sta == 4 || sta == 7 || sta == 8)&& card == 4 && count == 0) { x = 20 - x ; count = 1; }
	//if ((sta == 0 || sta == 3 || sta == 4 || sta == 7 || sta == 8)&& card == 6 && count == 1) { x = 20 - x ; count = 0; }
	char out_card;
	if (card > 9) {
		//cout << "card>9" << endl;
		switch (card) {
			case 10: out_card = 'A';
				 cout<<1<<" "<<'A'<<" "<<x<<" "<<y<<endl;
				 break;
			case 11: out_card = 'B';
				 cout<<1<<" "<<'B'<<" "<<x<<" "<<y<<endl;
				 break;
			case 12: out_card = 'C';
				 cout<<1<<" "<<'C'<<" "<<x<<" "<<y<<endl;
				 break;
		}
		//cout<<1<<" "<<out_card<<" "<<x<<" "<<y<<endl;
	}
	else cout<<1<<" "<<card<<" "<<x<<" "<<y<<endl;
}
void sumon_end(){
	cout<<0<<endl;
}
int check_reverse(int c1,int c2,int c3,int c4,int sta2){
	/*if (reverse_count > 3) {
		count = 0;
                reverse_count = 0;
		return 0;
        }
	else {*/
		if (reverse == 0){
			if ((sta2 == 0) && (count > 5) && (find_minion(c1,c2,c3,c4,4) != 0) && (find_card(c1,c2,c3,c4,2) != 0))
				return 1;
			else return 0;
		}
		else return 1;
	//}
}
int reverse_minion(int c1,int c2,int c3,int c4,int sta3){
	if (reverse_count == 0) {
		if (find_minion(c1,c2,c3,c4,4)) return 4;
		else return find_card(c1,c2,c3,c4,1);
	}
	else if (reverse_count != 0 && check_attack != 0) return find_card(c1,c2,c3,c4,2);
	else return best_card(c1,c2,c3,c4,sta3);
}
