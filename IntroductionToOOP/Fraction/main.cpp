//Fraction
#include<iostream>
using namespace std;

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);
int find_digit(double a, int digit);
int find_digit(double a);

class Fraction
{
	int integer;		//цела€ часть
	int numerator;		//числитель
	int denominator;	//знаменатель
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}
	//					Constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1ArgConstructor:\t" << this << endl;
	}

	Fraction(double integer_fraction)
	{
		int integer = integer_fraction;
		integer_fraction -= integer;
		int digit = find_digit(integer_fraction);
		this->integer = integer;
		this->numerator = (integer_fraction*digit);
		this->denominator = digit;
		reduce();
		cout << "1ArgConstructor:\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//				Operators:
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;

	}

	Fraction& operator++()
	{
		 this->integer++;
		 return *this;
	}

	Fraction& operator--()
	{
		this->integer--;
		return *this;
	}

	Fraction& operator++(int)
	{
		Fraction old = *this;
		this->integer++;
		return old;
	}

	Fraction& operator--(int)
	{
		Fraction old = *this;
		this->integer--;
		return old;
	}
	//    Type-cast operators
 	explicit operator int()const
	{
		return Fraction(*this).to_proper().integer;
	}
	explicit operator double()const
	{
		double res;
		Fraction temp(*this);
		temp.to_proper();
		return ((res = ((double)temp.numerator / (double)temp.denominator)) += (double)temp.integer);
		
	}
	//				Methods:
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}
	Fraction& reduce()
	{
		//https://www.webmath.ru/poleznoe/formules_12_7.php
		int more, less, rest = 0;
		if (numerator > denominator)more = numerator, less = denominator;
		else less = numerator, more = denominator;
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more;	//GCD - Greates Common Divisor (Ќаибольший общий делитель)
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}
	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}
};

int find_digit(double a)
{
	
	int digit = 10;
	int ab = a *= (double)digit;
	if (a - ab == 0)
	{
		return digit;
	}
	else
	{
		digit *= 10;
		find_digit(a, digit);
		return digit;
	}
}

int find_digit(double a,int digit)
{
	int ab = a *= (double)digit;
	if (a - ab == 0)
	{
		return digit;
	}
	else
	{
		digit *= 10;
		find_digit(a, digit); 
		return digit;
	}
}

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();

	/*Fraction result;	//Default constructor
	result.set_numerator(left.get_numerator()*right.get_numerator());
	result.set_denominator(left.get_denominator()*right.get_denominator());*/
	/*Fraction result
	(
		left.get_numerator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	);
	return result;*/

	//явно вызываем конструктор и создаем временный безым€нный объект, 
	//который сразу же возвращаетс€ на место вызова:
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}
Fraction operator/(const Fraction& left, const Fraction& right)
{
	/*left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator()*right.get_denominator(),
		right.get_numerator()*left.get_denominator()
	).to_proper();*/
	return left * right.inverted();


}


// Comparison operators

bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.to_proper().get_integer() == right.to_proper().get_integer() && 
		left.get_numerator() * right.get_denominator() ==
		right.get_numerator() * left.get_denominator();
}

bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}

bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return 
		left.get_numerator() * right.get_denominator() >
		right.get_numerator() * left.get_denominator();
}

bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() <
		right.get_numerator() * left.get_denominator();
}

bool operator>=(const Fraction& left, const Fraction& right)
{
	return left > right || left == right;
}

bool operator<=(const Fraction& left, const Fraction& right)
{
	return left < right || left == right;
}

// cout-cin operators

std::ostream& operator<<(std::ostream& out, Fraction& obj)
{

	if (obj.get_integer())out << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())out << "(";
		out << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())out << ")";
	}
	else if (obj.get_integer() == 0)out << 0;
	out << endl;

	return out;
	
}


std::istream& operator>>(std::istream& in, Fraction& obj)
{
	int a, b, c;
	cout << "denumenator: "; cin >> a;
	cout << "numerator: "; cin >> b;
	cout << "integer: "; cin >> c;
	obj.set_denominator(a); obj.set_numerator(b); obj.set_integer(c);
	return in;
	
}



//#define CONSTRUCTORS_CHECK
//#define ARIFMETICAL_OPERATORS_CHECK
//#define COMPARISON_OPERATORS
//#define binary_operators_and_CIN

//#define HOME_WORK_1
#define HOME_WORK_2


void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
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
#endif // CONSTRUCTORS_CHECK

#ifdef ARIFMETICAL_OPERATORS_CHECK
	double a = 2;
	double b = 3;
	double c = a * b;

	Fraction A(2, 3, 4);
	A.print();

	Fraction B(3, 4, 5);
	B.print();

	/*Fraction C = A * B;
	C.print();
	Fraction D = A / B;
	D.print();*/

	A *= B;
	A.print();
	A /= B;
	A.print();
#endif // ARIFMETICAL_OPERATORS_CHECK

#ifdef COMPARISON_OPERATORS
cout << (Fraction(3,1,2) < Fraction(35,11)) << endl;
#endif // COMPARISON_OPERATORS

#ifdef binary_operators_and_CIN
Fraction  A(1, 3, 4);
++A;
A.print();
--A;
A.print();

A++;
A.print();
A--;
A.print();
int a = A;

Fraction B;
cin >> B;
cout << a << endl;
#endif // DEBUG




#ifdef HOME_WORK_1
Fraction B(2, 3, 4);
double b = B;

cout << b << endl;
#endif // HOME_WORK_1

#ifdef HOME_WORK_2
Fraction B = 2.7644444444444444444444455566666666;
cout << B << endl;
#endif // HOME_WORK_2

	
}
