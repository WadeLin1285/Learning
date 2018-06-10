/************************************************************
* PROJECT NO.1
* Author  : Wade Lin
* Title   : project for AI gamer design
* Modified: 2017/03/25
*************************************************************/
# include "minion.h"
# include <iostream>
# include <string>

using namespace std;
//int getPosition(int oldPosition);
//void choose_card(int a,int b,int c,int d,int e,int f,int g,int h);
void choose_card(char a,char b,char c,char d,char e,char f,char g,char h);
void sumon(int mini,int sta);
void sumon_end();

int main(){
	// sever info. data
	int cd = 180,mana,c1,c2,c3,c4,bc1,bc2,bc,status = 0;
	string map;
	// choose cards
	//choose_card('9','1','3','4','2','5','6','C');
	choose_card('1','2','3','4','5','6','7','8');
	// AI
	while(cd > 0){
		cin >> cd >> mana >> c1 >> c2 >> c3 >> c4;
		//cout << cd << mana << c1 << endl;
		for (int i=0 ; i < 45 ; i++){ 
			getline(cin,map);
			//cout<< map << endl;
		}
		bc1 = best_card(c1,c2,c3,c4);
                bc2 = best_card(c4,c3,c2,c1);
                if (bc1 != bc2 && compare_mana(bc1,bc2)==1) bc = bc2;
                else bc = bc1;
                if (check_mana(bc,mana) == 1){
                        sumon(bc,status);
                        sumon_end();
                }
                else sumon_end();
	}
	return 0;
}
void choose_card(char a,char b,char c,char d,char e,char f,char g,char h){
	cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<" "<<g<<" "<<h<<endl;
}
void sumon(int  mini,int sta){
	int x = position_x(mini,sta);
	int y = position_y(mini,sta);
	char card_No;
	if (mini > 9) {
		switch (mini) {
			case 10: card_No = 'A';
				 break;
			case 11: card_No = 'B';
                                 break;
			case 12: card_No = 'C';
                                 break;
			default: return;
		}
		cout<<1<<" "<<card_No<<" "<<x<<" "<<y<<endl;		
	}
	else cout<<1<<" "<<mini<<" "<<x<<" "<<y<<endl;
}
void sumon_end(){
	cout<<0<<endl;
}
/*int getPosition(int oldPosition){
	if(oldPosition > 3 && oldPosition < 8){
		oldPosition++;
		return oldPosition;
	}
	else{ 
		oldPosition = 4;
		return oldPosition;
	}	
}
int best(int c1,int c2,int c3,int c4){
	int v1[2] = {c1,cv[c1-1]};
	int v2[2] = {c2,cv[c2-1]};
	int v3[2] = {c3,cv[c3-1]};
	int v4[2] = {c4,cv[c4-1]};
	int best[2];
	best[0] = v1[0];
	best[1] = v1[1];
	while(1){
		if (best[1] < v2[1]) {best[0] = v2[0];best[1] = v2[1];}
		else if (best[1] < v3[1]) {best[0] = v3[0];best[1] = v3[1];}
		else if (best[1] < v4[1]) {best[0] = v4[0];best[1] = v4[1];}
		else break;
	}
	if (best[1] == v1[1] && cm[best[0]-1] > cm[v1[0]-1]) {
		best[0] = v1[0];
        	best[1] = v1[1];
	}
	else if (best[1] == v2[1] && cm[best[0]-1] > cm[v2[0]-1]) {
		best[0] = v2[0];
		best[1] = v2[1];
	}
	else if (best[1] == v3[1] && cm[best[0]-1] > cm[v3[0]-1]) {
		best[0] = v3[0];
		best[1] = v3[1];
	}
	else if (best[1] == v4[1] && cm[best[0]-1] > cm[v4[0]-1]) {
		best[0] = v4[0];
		best[1] = v4[1];
	}
	else ;
	return best[0];
}*/
