//IntroductionToOOP
#include<iostream>
using namespace std;

//				КЛАСС - ЭТО ТИП ДАННЫХ!!!
//				СТРУКТУРА - ЭТО ТИП ДАННЫХ!!!

class Point	//Создавая структуру или класс, мы создаем новый тип данных.
{			//Классы и структуры еще называют пользовательскими (составными) типами данных.
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

	//					Methods:
	double distance(Point other)
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance*x_distance + y_distance * y_distance);
		return distance;
	}

};

double distance(Point A, Point B) 
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}

//#define STRUCT_POINT
#define DISTANCE_CHECK

void main()
{
	setlocale(LC_ALL, "");
	cout << "Hello OOP" << endl;

#ifdef STRUCT_POINT
	int a;		//Объявление переменной 'a' типа 'int'
	Point A;	//Объявление переменной 'A' типа 'Point'
				//Объявление объекта 'A' структуры 'Point'
				//Создание экземпляра 'A' структуры 'Point'
	//Объекты часто называют экземплярами класса или структуры.
	//A.x = 2;
	//A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
	//p  - Pointer
	//pA - Pointer to 'A'
	//https://ru.wikipedia.org/wiki/%D0%92%D0%B5%D0%BD%D0%B3%D0%B5%D1%80%D1%81%D0%BA%D0%B0%D1%8F_%D0%BD%D0%BE%D1%82%D0%B0%D1%86%D0%B8%D1%8F  
#endif // STRUCT_POINT

#ifndef DISTANCE_CHECK 
	Point A;
	A.set_x(2);
	A.set_y(3);
	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	cout << "Расстояние от точки A до точки B: " << A.distance(B) << endl;
	cout << "Расстояние от точки A до точки B: " << distance(A, B) << endl;

#endif // DISTANCE_CHECK


	
}

/*
--------------------------------------------
.  - Оператор прямого доступа (Point operator)
-> - Оператор косвенного доступа (Arrow operator)
--------------------------------------------
*/

/*
--------------------------------------------
1. Инкапсуляция (Encapsulation);
Модификаторы доступа:
private:	закрытые поля, доступны только внутри класса
public:		открытые поля, доступные из любого места программы
protected:	защищенные поля, доступны внутри нашего класса и его дочерних классов
			(этот модификатор доступа используется только при наследовании)
get/set-методы - обеспечивают доступ извне к закрытым переменным в классе.
get (взять, получить) - позволяют получить (взять) значение переменной 
						(открывают доступ на чтение к переменным членам класса)
set (назначить, задать, установить) - позволяют задать значение переменной в классе
						(открывают доступ к переменным членам класса на запись).

2. Наследование (Inheritance);
3. Полиморфизм  (Polymorphism);
--------------------------------------------
*/