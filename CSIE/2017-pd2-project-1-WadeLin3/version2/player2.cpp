/************************************************************
* PLAYER 2
* Author  : Wade Lin
* Title   : testing program for project 1
* Modified: 2017/03/18
*************************************************************/

# include <iostream>
using namespace std;
int getPosition(int oldPosition);

int main(){
	// sever info. data
	int cd = 180,mana = 0,c1,c2,c3,c4;
	int position[2] = {4,28};
	int cm[8] = {5,3,4,7,1,4,9,5}; // card mana consum
	// card attack point
	int ca[8] = {50,50,150,10,10,100,100,200};
	// card health point
	int ch[8] = {1500,700,500,3000,300,300,2500,150};
	// read server output info.
	cout <<1<<" "<<2<<" "<<3<<" "<<4<<" "<<5<<" "<<6<<" "<<7<<" "<<8<<endl;
	/* AI
	while(cd > 0){
		cin >> cd >> mana >> c1 >> c2 >> c3 >> c4;
		//cout << cd << mana << c1 << endl;
		position[0] = getPosition(position[0]);
		while(mana >= 0){
			if(mana >= cm[c1-1]){
				cout << 1<<" " << c1<<" " << 4<<" "<< 28 <<endl;
				cout << 0 << endl;
			}
			else{
				cout << 0 << endl;
				break;
			}
		}
	}*/
	//cout << 0 << endl;
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
