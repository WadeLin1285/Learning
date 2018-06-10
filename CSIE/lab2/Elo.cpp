/*********************************
* Program: LAB 2
           Elo.cpp
* The class of value K R(A) R(B) 
  and member fuctions
*********************************/
# include "Elo.h"
# include <iostream>
# include <math.h>
Elo::Elo(){
	K = 32;
	R = 0;
}
Elo::Elo(int rank){
	setR(rank);
}
Elo::Elo(int rank,int K){
	setR(rank);
	setK(K);
}
int Elo::getK(){
	return K;
}
void Elo::setK(int kValue){
	K = kValue;
}
int Elo::getR(){
	return R;
}
void Elo::setR(int rValue){
	R = rValue;
}
float Elo::eScore(Elo A,Elo B){
	int rankA = A.getR();
	int rankB = B.getR();
	float E = 1/(1+pow(10,(static_cast<float>(rankB-rankA)/400)));
	//return E;
	if ((int)(E*10000)%10 >= 5) return (float)((int)(E*1000+1))/1000;
	else return (float)((int)(E*1000))/1000;
}
// For new rank calculation

int Elo::updateRank(Elo A,Elo B,float S){
	int oldR = A.getR();
	int K = A.getK();
	float E = A.eScore(A,B);
	float R = (float)oldR + K*(S-E);	
	if ((int)(R*10)%10 >= 5) return R+1;
	else return R;
}
