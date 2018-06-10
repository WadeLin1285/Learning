/*********************************
* Program: LAB 2
	   Main program
* Calculate the rank for player A
  and B
*********************************/
# include <iostream>
# include "Elo.h"
# include <math.h>
# include <fstream>
# include <cstdlib>
using namespace std;

int main(){
	int RA,RB,K,n=0;
	float a,b;
	
	ifstream inFile("file.in",ios::in);
	if(!inFile){
                cerr<<"Failed Opening file.in..."<<endl;
                exit(1);
        }
	inFile>>K>>RA>>RB;
	
	Elo A(RA,K);
	Elo B(RB,K);
	/*
	cout<<"A - K:"<<A.getK()<<" R:"<<A.getR()<<endl;
        cout<<"B - K:"<<B.getK()<<" R:"<<B.getR()<<endl;
	cout<<"A - E:"<<A.eScore(A,B)<<endl;	
	cout<<"B - E:"<<B.eScore(B,A)<<endl;
	*/
	ofstream outFile("file.out",ios::out);
	if(!outFile){
		cerr<<"Failed Opening file.out..."<<endl;
		exit(1);
	}
	outFile<<A.getR()<<" "<<B.getR()<<endl;
	while(inFile>>a){
		b = fabs(a-1);
	        int newRA = A.updateRank(A,B,a);
        	int newRB = B.updateRank(B,A,b);
		A.setR(newRA);
		B.setR(newRB);
		outFile<<A.getR()<<" "<<B.getR()<<endl;
	}
	
	return 0;
}

