//fraction
#include<iostream>
using namespace std;

using std::cout;

#define delimiter "________________________________________________________________________________________________________________________"
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
	// Constructors
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denumerator = 1;
		cout << "Default constructor:\t" << this << endl;
	}

	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denumerator = 1;
		cout << "1Argconstructor:\t" << this << endl;
	}

	Fraction(int numerator, int denumenator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denumerator(denumenator);
		cout << "Constructor:\t\t" << this << endl;
	}

	Fraction(int integer, int numerator, int denumenator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denumerator(denumenator);
		cout << "Constructor:\t" << this << endl;
	}

	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denumerator = other.denumerator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}

	// methods

	Fraction& to_improper()
	{
		numerator += integer * denumerator;
		integer = 0;
		return *this;
	}

	Fraction& to_proper()
	{
		integer += numerator / denumerator;
		numerator %= denumerator;
		return *this;
	}

	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denumerator);
		return inverted;
	}

	Fraction& reduce()
	{

		if ((numerator % 2 == 0) && (denumerator % 2 == 0))
		{
			numerator /= 2, denumerator /= 2;
		}
		return *this;
	}

	void print()const
	{
		cout << endl;
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denumerator;
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;

		cout << endl;
	}
};

int NOD(int A, int B)
{
	if ((A != 0) && (B != 0))
	{
		if (A > B)
		{
			A %= B;
			NOD(A, B);
		}
		else
		{
			B %= A;
			NOD(A, B);
		}
	} return A;
}

int NOK(int A, int B)
{
	return (A * B) / NOD(A, B);
}

Fraction operator+(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	right.reduce();
	left.reduce();

	return Fraction(
		left.get_nemerator() * right.get_denumerator() + right.get_nemerator() * left.get_denumerator(),
		left.get_denumerator() * right.get_denumerator()

	).to_proper();
}

Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	right.reduce();
	left.reduce();

	int addFactorLeft, addFactorRight, nok = NOK(left.get_denumerator(), right.get_denumerator());
	addFactorLeft = nok / left.get_denumerator();
	addFactorRight = nok / right.get_denumerator();

	return Fraction((left.get_nemerator() * addFactorLeft) - (right.get_nemerator() * addFactorRight), nok
	).to_proper();
}

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	right.reduce();
	left.reduce();

	/*Fraction result
	(
		left.get_nemerator() * right.get_nemerator(),
		left.get_denumerator() * right.get_denumerator()
	);*/
	/*result.set_numerator(left.get_nemerator() * right.get_nemerator());
	result.set_denumerator(left.get_denumerator() * right.get_denumerator());*/
	return Fraction
	(
		left.get_nemerator() * right.get_nemerator(),
		left.get_denumerator() * right.get_denumerator()
	).to_proper();
}

Fraction operator/(Fraction left, Fraction right)
{
	/*left.to_improper();
	right.to_improper();*/


	/*return Fraction
	(
		left.get_nemerator() * right.get_denumerator(),
		right.get_nemerator() * left.get_denumerator()
	).to_proper();*/

	return left * right.inverted();
}

Fraction operator/=(Fraction& left, Fraction right)
{
	return left = left * right.inverted();
}

Fraction operator*=(Fraction& left, Fraction right)
{
	return left = left * right;
}


Fraction operator+=(Fraction& left, Fraction right)
{
	return left = left + right;
}
Fraction operator-=(Fraction& left, Fraction right)
{
	return left = left - right;
}

//#define Constructors_check


int main()
{
#ifdef Constructors_check
	setlocale(LC_ALL, "");
	Fraction A;
	A.print();

	Fraction B = 5;
	B.print();

	Fraction C(2, 3);
	C.print();

	Fraction D(2, 3, 4);
	D.print();

	Fraction E = D;
	E.print();
#endif // Constructors_check

	Fraction A(2, 3, 4);
	A.print();
	cout << delimiter << endl;

	Fraction B(3, 4, 5);
	B.print();
	cout << delimiter << endl;

	/*Fraction C = A * B;
	C.print();
	cout << delimiter << endl;

	Fraction D = A / B;
	D.print();
	cout << delimiter << endl;

	A *= B;
	A.print();
	cout << delimiter << endl;

	B = A;
	B.print();
	cout << delimiter << endl;*/

	/*Fraction D = B + A;
	D.print();
	cout << delimiter << endl;*/

	A *= B;
	A.print();
	A /= B;
	A.print();
}