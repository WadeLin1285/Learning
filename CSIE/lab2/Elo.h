/*********************************
* Program: LAB 2
	   Header file of Elo.cpp
* The class of value K R(A) R(B) 
  and member fuctions
*********************************/
using namespace std;
class Elo{
	public:
		Elo();
		Elo(int rank);
		Elo(int rank,int K);
		int getK();
		void setK(int kValue);
		int getR();
		void setR(int rValue);
		float eScore(Elo A,Elo B);
		int updateRank(Elo A,Elo B,float S);
	private:
		int K;
		int R;
};
//int updateRank(Elo A,Elo B,float S);
