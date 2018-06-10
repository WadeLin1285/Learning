# include "card.h"
# include "minion.h"
# include <iostream>

using namespace std;
static int tank_count = 0,attack_count = 0;
// ratio of tank and attack
static int TNK = 1; 
static int ATK = 5;
static int HEA = TNK + ATK + 5;

int best_card(int c1,int c2,int c3,int c4,int status){
	// check special card
	if (c1 == 9) return c1;
	if (c2 == 9) return c2;
        if (c3 == 9) return c3;
        if (c4 == 9) return c4;
        if (c1 == 5) return c1;
        if (c2 == 5) return c2;
        if (c3 == 5) return c3;
        if (c4 == 5) return c4;
	// count num of class
	int a = check_tank(c1,c2,c3,c4);
	int b = check_attack(c1,c2,c3,c4);
	int c = check_healer(c1,c2,c3,c4);
	// cout<<"a:"<<a<<" b:"<<b<<" c:"<<c<<endl;
	// special status
	switch (status){
		case 0: TNK= 1; ATK = 5; break; // normal status
		case 1: case 2: ATK = 2; break; // defend the main castle
		case 3: case 4: ATK = 7; break; // offensive
		case 5: case 6: ATK = 3; break; // normal defense
		case 7: case 8: ATK = 5; break; // normal attack
	}
	// normal status
	if (a!=0 && b!=0 && c!=0){
		// compare the number of tank and attack 
		if (compare_healer_amount()) return find_card(c1,c2,c3,c4,3);
		else if (compare_attack_tank()){
			if (status == 5 || status == 6 || status == 1 || status == 2){
				if (find_minion(c1,c2,c3,c4,4)) return find_minion(c1,c2,c3,c4,4);
				else return find_card(c1,c2,c3,c4,1);
			} 
			else if (status == 3 || status == 4){
                                if (find_minion(c1,c2,c3,c4,1)) return find_minion(c1,c2,c3,c4,1);
				else return find_card(c1,c2,c3,c4,1);
                        }
			else return find_card(c1,c2,c3,c4,1);
		}
		else return find_card(c1,c2,c3,c4,2);
	}
	// only tank
	else if (a!=0 && b==0 && c==0){ 
		if (status == 5 || status == 6 || status == 1 || status == 2){
                        if (find_minion(c1,c2,c3,c4,4)) return find_minion(c1,c2,c3,c4,4);
			else return find_card(c1,c2,c3,c4,1);
                }
                else if (status == 3 || status == 4){
                        if (find_minion(c1,c2,c3,c4,1)) return find_minion(c1,c2,c3,c4,1);
			else return find_card(c1,c2,c3,c4,1);
                }
                else return find_card(c1,c2,c3,c4,1);
	}
	// only attack
        else if (a==0 && b!=0 && c==0) return find_card(c1,c2,c3,c4,2);
	// only healer
        else if (a==0 && b==0 && c!=0) return find_card(c1,c2,c3,c4,3);
	// no healer
	else if (a!=0 && b!=0 && c==0){
                // compare the number of tank and attack 
                if (compare_attack_tank()){ 
			if (status == 5 || status == 6 || status == 1 || status == 2){
                                if (find_minion(c1,c2,c3,c4,4)) return find_minion(c1,c2,c3,c4,4);
				else return find_card(c1,c2,c3,c4,1);
                        }
                        else if (status == 3 || status == 4){
                                if (find_minion(c1,c2,c3,c4,1)) return find_minion(c1,c2,c3,c4,1);
				else return find_card(c1,c2,c3,c4,1);
                        }
                	else return find_card(c1,c2,c3,c4,1);
		}
                else return find_card(c1,c2,c3,c4,2);
        }
	// no attacker
	else if (a!=0 && b==0 && c!=0){
		// compare the number of tank and attack 
                if (compare_healer_amount()) return find_card(c1,c2,c3,c4,3);
                else {
		if (status == 5 || status == 6 || status == 1 || status == 2){
                        if (find_minion(c1,c2,c3,c4,4)) return find_minion(c1,c2,c3,c4,4);
			else return find_card(c1,c2,c3,c4,1);
                }
                else if (status == 3 || status == 4){
                        if (find_minion(c1,c2,c3,c4,1)) return find_minion(c1,c2,c3,c4,1);
			else return find_card(c1,c2,c3,c4,1);
                } 
                else return find_card(c1,c2,c3,c4,1);
		}
        }
	// no tank
	else if (a==0 && b!=0 && c!=0){
		// compare the number of tank and attack 
                if (compare_healer_amount()) return find_card(c1,c2,c3,c4,3);
                else return find_card(c1,c2,c3,c4,2);
        }
	else {
		//cout<<"no found"<<endl;
		return 0;
	}
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
        if (c1 == 12) B++;
        if (c2 == 12) B++;
        if (c3 == 12) B++;
        if (c4 == 12) B++;
        if (cc[c1-1] == 2) B++;
        if (cc[c2-1] == 2) B++;
        if (cc[c3-1] == 2) B++;
        if (cc[c4-1] == 2) B++;
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
int find_card(int c1,int c2,int c3,int c4, int cls){
	int best = 0;
	if (cls == 2 && find_minion(c1,c2,c3,c4,12) != 0 && attack_count >= 4)
		return 12;
	if (cc[c1-1] == cls) best = c1;
        if (cc[c2-1] == cls) { 
		if (best != 0 && cls != 1 && cm[best-1] <= cm[c2-1]) ;
		else best = c2;
	}
        if (cc[c3-1] == cls) { 
                if (best != 0 && cls != 1 && cm[best-1] <= cm[c3-1]) ;
                else best = c3;
        }
        if (cc[c4-1] == cls) { 
                if (best != 0 && cls != 1 && cm[best-1] <= cm[c4-1]) ;
                else best = c4;
        }
	return best;
}
int find_minion(int c1,int c2,int c3,int c4,int Num){
	if (c1 == Num) return c1;
	else if (c2 == Num) return c2;
	else if (c3 == Num) return c3;
	else if (c4 == Num) return c4;
	else return 0; 
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
int compare_healer_amount(){
	// re 1: healer
	if ((tank_count+attack_count)>= HEA) return 1;
	else return 0;
}
int compare_attack_tank(){
	// re 0: attack  re 1: tank
	if (tank_count == 0) return 1;
	else if (tank_count == 1 && attack_count < ATK) return 0;
	//else if (tank_count == TNK && attack_count < ATK) return 0;
	else return 1;
}
