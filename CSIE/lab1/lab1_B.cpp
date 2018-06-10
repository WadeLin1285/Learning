/****************************************** 
   Thesis: HW1-B
   Author: Wade Lin
   Update: 2017/03/12
******************************************/
#include <iostream>
using namespace std;

int main(){
	int n;
	cout << "Enter an interger: ";
	cin >> n;
	print:cout << n << " ";
	if (n == 1){ 
		cout << endl;
		return 0;
	}
	else if (n%2 == 1) n = 3*n+1;
	else n = n/2;
	goto print;
	return 0;
}

