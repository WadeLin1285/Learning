/*************************************
* Store the minions status and info
* and creat the each minion's data.
* AP: attack point
* HP: health point
* MP: mana point
* CL: class of minion
*     [attack tank support special power]
* RA: race of minion
* SP: speed 
*************************************/
# include <string>

# ifndef MINION_H
# define MINION_H
using namespace std;
class minion{
	public:
		minion(char N);
		char getNo();
		int getAP();
		int getMP(); 
		string getCL();
		int getSP();
	private:
		int No;
		int AP;
		int HP;
		int MP;
		string CL;
		string RA;
		int SP;
};
#endif 
