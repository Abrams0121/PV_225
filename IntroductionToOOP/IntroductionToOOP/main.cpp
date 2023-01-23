//IntroductionToOOP
#include<iostream>
using namespace std;

//				����� - ��� ��� ������!!!
//				��������� - ��� ��� ������!!!

class Point	//�������� ��������� ��� �����, �� ������� ����� ��� ������.
{			//������ � ��������� ��� �������� ����������������� (����������) ������ ������.
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	//					Constructors:
	/*Point()
	{
		x = y = 0;
		cout << "DefConstructor" << "\t" << this << endl;
	}*/
	/*Point(double x) {
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor" << this << endl;
	}*/
	Point(double x=0, double y=0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor/t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "Copy constructor" << this << endl;
	}
	~Point()
	{
		cout << "Destructor" << "\t" << this << endl;
	}

	//					Methods:
	double distance(Point other)const
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance*x_distance + y_distance * y_distance);
		return distance;
	}

	void print()const
	{
		cout << "X= " << x << "\t" << "Y= " << y << endl;
	}
};

//#define STRUCT_POINT

void main()
{
	setlocale(LC_ALL, "");
	cout << "Hello OOP" << endl;

#ifdef STRUCT_POINT
	int a;		//���������� ���������� 'a' ���� 'int'
	Point A;	//���������� ���������� 'A' ���� 'Point'
				//���������� ������� 'A' ��������� 'Point'
				//�������� ���������� 'A' ��������� 'Point'
	//������� ����� �������� ������������ ������ ��� ���������.
	//A.x = 2;
	//A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
	//p  - Pointer
	//pA - Pointer to 'A'
	//https://ru.wikipedia.org/wiki/%D0%92%D0%B5%D0%BD%D0%B3%D0%B5%D1%80%D1%81%D0%BA%D0%B0%D1%8F_%D0%BD%D0%BE%D1%82%D0%B0%D1%86%D0%B8%D1%8F  
#endif // STRUCT_POINT

	/*Point A;
	A.set_x(2);
	A.set_y(3);
	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	cout << "���������� �� ����� A �� ����� B: " << A.distance(B) << endl;*/
	Point A;
	cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();

	Point b(2, 3);
	b.print();

	Point C = 4; // Single-arqument constructor
	C.print();

	Point D = C; //Copy constructor;
	// Deep copy - ��������� , ���������� , ������������ �����������
	D.print();

	Point F(D);
	F.print();
}

/*
--------------------------------------------
.  - �������� ������� ������� (Point operator)
-> - �������� ���������� ������� (Arrow operator)
--------------------------------------------
*/

/*
--------------------------------------------
1. ������������ (Encapsulation);
������������ �������:
private:	�������� ����, �������� ������ ������ ������
public:		�������� ����, ��������� �� ������ ����� ���������
protected:	���������� ����, �������� ������ ������ ������ � ��� �������� �������
			(���� ����������� ������� ������������ ������ ��� ������������)
get/set-������ - ������������ ������ ����� � �������� ���������� � ������.
get (�����, ��������) - ��������� �������� (�����) �������� ���������� 
						(��������� ������ �� ������ � ���������� ������ ������)
set (���������, ������, ����������) - ��������� ������ �������� ���������� � ������
						(��������� ������ � ���������� ������ ������ �� ������).

2. ������������ (Inheritance);
3. �����������  (Polymorphism);
--------------------------------------------
*/