#include <iostream>
using namespace std;
int main()
{
	try{
	throw 3.0;
	} catch (double) {
		cout << "exception caught" << endl;
	}
	cout << "I love C++" << endl;
	return 0;
}
