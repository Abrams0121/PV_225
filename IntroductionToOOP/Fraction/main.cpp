//fraction
#include<iostream>
using namespace std;


class Fraction
{

	int integer;
	int numerator;
	int denumerator;

public:

	int get_integer()const
	{
		return integer;
	}

	int get_nemerator()const
	{
		return numerator;
	}

	int get_denumerator()const
	{
		return denumerator;
	}

	void set_integer(int integer)
	{
		this->integer = integer;
	}

	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}

	void set_denumerator(int denumerator)
	{
		if (denumerator == 0)denumerator = 1;
		this->denumerator = denumerator;
	}
	
};




void main()
{
	setlocale(LC_ALL, "");

}