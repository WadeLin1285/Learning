# include "card.h"
# include "minion.h"
# include <iostream>
using namespace std;
static int tank_count = 0,attack_count = 0;

int best_card(int c1,int c2,int c3,int c4,int status){
// creat card array: No, Class
        int v1[3] = {c1,cc[c1-1],cm[c1-1]};
        int v2[3] = {c2,cc[c2-1],cm[c2-1]};
        int v3[3] = {c3,cc[c3-1],cm[c3-1]};
        int v4[3] = {c4,cc[c4-1],cm[c4-1]};
	// check special card - dancer
	if (v1[1] == 9) return v1[0];
	if (v2[1] == 9) return v2[0];
        if (v3[1] == 9) return v3[0];
        if (v4[1] == 9) return v4[0];
	// check status - 0:normal 1:attack 2:defense_down 3:defense_castle
	if (status == 2){ // defense down route
		
	}
	int a = check_tank(c1,c2,c3,c4);
	int b = check_attack(c1,c2,c3,c4);
	int c = check_healer(c1,c2,c3,c4);
	//cout<<"a="<<a<<";b="<<b<<";c="<<c<<endl;
	//cout<<"tank="<<tank_count<<";attacker="<<attack_count<<endl;
	if (a!=0 && b!=0 && c!=0){
		// compare the number of tank and attack 
		if ((tank_count+attack_count)>=5){
			return find_healer(c1,c2,c3,c4);
		}
		else if (tank_count <= attack_count){
			return find_tank(c1,c2,c3,c4);
		}
		else {
			return find_attack(c1,c2,c3,c4);
		}
	}	
	else if (a!=0 && b==0 && c==0) return find_tank(c1,c2,c3,c4);
        else if (a==0 && b!=0 && c==0) return find_attack(c1,c2,c3,c4);
        else if (a==0 && b==0 && c!=0) return find_healer(c1,c2,c3,c4);
	// no healer
	else if (a!=0 && b!=0 && c==0){
                // compare the number of tank and attack 
                if (tank_count <= attack_count) return find_tank(c1,c2,c3,c4);
                else return find_attack(c1,c2,c3,c4);
        }
	// no attacker
	else if (a!=0 && b==0 && c!=0){
		// compare the number of tank and attack 
                if ((tank_count+attack_count)>= 5) return find_healer(c1,c2,c3,c4);
                else return find_tank(c1,c2,c3,c4);
        }
	// no tank
	else if (a==0 && b!=0 && c!=0){
		// compare the number of tank and attack 
                if ((tank_count+attack_count)>=5) return find_healer(c1,c2,c3,c4);
                else return find_attack(c1,c2,c3,c4);
        }
	else return v1[0];
}
int check_tank(int c1,int c2,int c3,int c4){
	int A = 0; 
	if (cc[c1-1] == 1) A++;
	if (cc[c2-1] == 1) A++;
	if (cc[c3-1] == 1) A++;
	if (cc[c4-1] == 1) A++;
	return A;
}
int check_attack(int c1,int c2,int c3,int c4){
        int B = 0;
        if (cc[c1-1] == 2) B++;
        if (cc[c2-1] == 2) B++;
        if (cc[c3-1] == 2) B++;
        if (cc[c4-1] == 2) B++;
        if (cc[c1-1] == 5) B++;
        if (cc[c2-1] == 5) B++;
        if (cc[c3-1] == 5) B++;
        if (cc[c4-1] == 5) B++;
        return B;
}
int check_healer(int c1,int c2,int c3,int c4){
        int C = 0;
        if (cc[c1-1] == 3) C++;
        if (cc[c2-1] == 3) C++;
        if (cc[c3-1] == 3) C++;
        if (cc[c4-1] == 3) C++;
        return C;
}
int find_tank(int c1,int c2,int c3,int c4){
        if (cc[c1-1] == 1) return c1;
        if (cc[c2-1] == 1) return c2;
        if (cc[c3-1] == 1) return c3;
        if (cc[c4-1] == 1) return c4;
        return 0;
}
int find_attack(int c1,int c2,int c3,int c4){
	if (cc[c1-1] == 5) return c1;
        if (cc[c2-1] == 5) return c2;
        if (cc[c3-1] == 5) return c3;
        if (cc[c4-1] == 5) return c4;
        if (cc[c1-1] == 2) return c1;
        if (cc[c2-1] == 2) return c2;
        if (cc[c3-1] == 2) return c3;
        if (cc[c4-1] == 2) return c4;
        return 0;
}
int find_healer(int c1,int c2,int c3,int c4){
        if (cc[c1-1] == 3) return c1;
        if (cc[c2-1] == 3) return c2;
        if (cc[c3-1] == 3) return c3;
        if (cc[c4-1] == 3) return c4;
        return 0;
}
int check_mana(int bc,int mana){
	if (mana >= cm[bc-1]) {
		if     (cc[bc-1]==1) tank_count++;
		else if(cc[bc-1]==2) attack_count++;
		else if(cc[bc-1]==3) {tank_count=0;attack_count=0;}
		else ;
		return 1;
	}
	else return 0;
}
int position_x(int mini,int sta){
	if (sta == 0){
		if (cc[mini-1]==1) return 5; // tank
		if (cc[mini-1]==2) return 5; // attack
                if (cc[mini-1]==3) return 3; // healer
                if (cc[mini-1]==5) return 7; // sniper
                if (cc[mini-1]==9) return 10; // manar
	}
}
int position_y(int mini,int sta){
        if (sta == 0){
                if (cc[mini-1]==1) return 16; // tank
                if (cc[mini-1]==2) return 13; // attack
                if (cc[mini-1]==3) return 10; // healer
                if (cc[mini-1]==5) return 4; // sniper
                if (cc[mini-1]==9) return 1; // manar
        }
}

