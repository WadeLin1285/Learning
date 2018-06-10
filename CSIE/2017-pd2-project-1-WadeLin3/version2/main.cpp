/************************************************************
* PROJECT NO.1
* Author  : Wade Lin
* Title   : project for AI gamer design
* Modified: 2017/03/25
*************************************************************/

# include <iostream>
# include <string>
using namespace std;
int getPosition(int oldPosition);
int best(int c1,int c2,int c3,int c4);

/********* card informations **************/
// card mana consum
int cm[9] = {5,3,4,7,1,4,9,5,5};
// card attack point
int ca[9] = {50,50,150,10,10,100,100,200,0};
// card health point
int ch[9] = {1500,700,500,3000,300,300,2500,150,1000};
// card valve point(5=special ; 4=tank ; 3=attacker ; 2=healer ; 1=suck)
int cv[9] = {4,2,3,4,2,3,1,1,5};

int main(){
	// sever info. data
	int cd = 180,mana,c1,c2,c3,c4,bc,position[2]={4,17},open;
	string map;
	// choose cards
	cout <<1<<" "<<3<<" "<<8<<" "<<6<<" "<<2<<" "<<5<<" "<<7<<" "<<4<<endl;
	// AI
	while(cd > 0){
		cin >> cd >> mana >> c1 >> c2 >> c3 >> c4;
		//cout << cd << mana << c1 << endl;
		for (int i=0 ; i < 45 ; i++){ 
			getline(cin,map);
			//cout<< map << endl;
		}
		if (open = 0){
			if (mana > 10) {
				cout << 1 << " " << 1 <<" "<< position[0]<<" "<< position[1]<<endl;
				position[0] = getPosition(position[0]);
				cout << 1 << " " << 8 <<" "<< position[0]<<" "<< position[1]<<endl;
				open = 1;
				cout << 0 << endl;
			}
			else cout << 0 << endl;
		}
		else {
			bc = best(c1,c2,c3,c4);
			if (mana >= cm[bc-1]){
				position[0] = getPosition(position[0]);
				cout << 1 << " " << bc <<" "<< (20-position[0])<<" "<< position[1]<<endl;
				cout << 0 << endl;
			}
			else cout << 0 << endl;
		}
	}
	return 0;
}

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
}
