/************************************************************
* PROJECT NO.1
* Author  : Wade Lin
* Title   : project for AI gamer design
* Modified: 2017/03/25
*************************************************************/
# include "minion.h"
# include "battle.h"
# include <iostream>
# include <string>
using namespace std;
//int getPosition(int oldPosition);
//int best(int c1,int c2,int c3,int c4);
void choose_card(char a,char b,char c,char d,char e,char f,char g,char h);
void sumon(char mini,int sta);
void sumon_end();

int main(){
	
	// sever info and data
	int cd = 180,mana,status = 0;
	char c1,c2,c3,c4,bc;
	string map;
	// choose cards
	choose_card('1','4','6','8','7','5','3','2');
	// AI
	while(cd > 0){
	cin >> c1 >> c2 >> c3 >> c4;
	minion C1(c1);
        minion C2(c2);
        minion C3(c3);
        minion C4(c4);
	
	//cout<<C1.getNo()<<endl;
	//cout<<C2.getNo()<<endl;
	//cout<<C3.getNo()<<endl;
	//cout << choose_best_card(C1,C2,C3,C4) <<endl;	
	bc = choose_best_card(C1,C2,C3,C4);
	cout << bc <<endl;

	/*
		cin >> cd >> mana >> c1 >> c2 >> c3 >> c4;
		for (int i=0 ; i < 45 ; i++){ 
			getline(cin,map);
			//cout<< map << endl;
		}
		minion C1(c1);
		minion C2(c2);
		minion C3(c3);
		minion C4(c4);
		bc = choose_best_card(C1,C2,C3,C4);
		cout << bc <<endl;
		minion BC(bc);
		if (mana >= BC.getMP()){
			sumon(bc,status);
			sumon_end();
		}
		else sumon_end();
	
		if (mana >= C1.getMP()){
			cout<<1<<" "<<C1.getNo()<<" "<<position[0]<<" "<<position[1]<<endl;
			cout<<0<<endl;
		}
	*/
	}
	return 0;
}
void choose_card(char a,char b,char c,char d,char e,char f,char g,char h){
	cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<" "<<g<<" "<<h<<endl;
}
void sumon(char mini,int sta){
	int x = position_x(sta,mini);
	int y = position_y(sta,mini);
	cout<<1<<" "<<mini<<" "<<y<<" "<<x<<endl;
}
void sumon_end(){
	cout<<0<<endl;
}
/*
int getPosition(int oldPosition){
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
