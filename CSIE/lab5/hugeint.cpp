# include "hugeint.h"
# include <sstream>
# include <iostream>
# include <stdlib.h>

using namespace std;

HugeInt::HugeInt()
{
	// initialize the num
	for (int i = 0; i < N ; ++i) num[i] = 0;
}

HugeInt::HugeInt(int y)
{
	// initialize the num
        for (int i = 0; i < N ; ++i) num[i] = 0;
	// inset int into int array
	for (int i = 0; i < N ; ++i)
	{
		if (y == 0) break;
		num[i] = y % 10;
		y = y / 10;
	}
}

HugeInt::HugeInt(string z)
{
	// initialize the num
        for (int i = 0; i < N ; ++i) num[i] = 0;
	// insert string into int array
	for (int i = 0,j = z.length()-1; i < N ; ++i,--j)
	{
		num[i] = z[j]-'0';
		if (j == 0) break;
	}
}

void HugeInt::printNum()
{
	for (int i = N-1,j = 0; i > -1 ; --i)
	{	
		if (j == 0 && num[i] == 0)
		{ 
			continue;
		}
		else j++;
		cout << num[i];
	}
	cout << endl;
}	

HugeInt HugeInt::operator = (const HugeInt & h)
{
	for (int i = 0; i < N ; ++i) num[i] = h.num[i];
}

HugeInt HugeInt::operator + (const HugeInt & h)
{
	HugeInt result;
	// addition
	for (int i = 0,carry = 0; i < N ; ++i)
	{
		result.num[i] = (num[i] + h.num[i] + carry) % 10;
		carry = (num[i] + h.num[i] + carry) / 10;
	}
	return result;
}

HugeInt HugeInt::operator - (const HugeInt & h)
{
	HugeInt result;
        // minus
        for (int i = 0,carry = 0; i < N ; ++i)
        {
		if ((num[i] - h.num[i] - carry) >= 0)
		{
			result.num[i] = num[i] - h.num[i] -carry;
			carry = 0;
		}
		else
		{
			result.num[i] = 10 + num[i] - h.num[i] - carry;
			carry = 1;
		}
        }
        return result;
}

ostream &operator << (ostream& out,const HugeInt &number)
{
	for (int i = N-1,j = 0; i > -1 ; --i)
        {
                if (j == 0 && number.num[i] == 0)
                {
                        continue;
                }
                else j++;
                out << number.num[i];
        }
	return out;
}

istream &operator >> (istream& in ,HugeInt &number)
{
	int n;
	in >> n;
	// initialize the num
        for (int i = 0; i < N ; ++i) number.num[i] = 0;
	// inset int into int array
        for (int i = 0; i < N ; ++i)
        {
                if (n == 0) break;
                number.num[i] = n % 10;
                n = n / 10;
        }

}
