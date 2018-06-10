#ifndef HUGEINT_H
#define HUGEINT_H

# define N 100

# include <string.h>
# include <iostream>

using namespace std;

class HugeInt
{
public:
	HugeInt();
	HugeInt(int y);
	HugeInt(string z);
	
	void printNum();
	
	HugeInt operator = (const HugeInt & h);
	HugeInt operator + (const HugeInt & h);
	HugeInt operator - (const HugeInt & h);
	
	friend ostream &operator << (ostream&,const HugeInt &);
	friend istream &operator >> (istream&,HugeInt &);

	int num[N];
};

#endif // HUGEINT_H
