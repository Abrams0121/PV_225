#include "String.h"

/// <summary>
/// CLASS DEFINITION END
/// </summary>


int main()
{
    setlocale(LC_ALL, "");
    String str1;	//Default constructor
    str1.print();
    String str2 = "Hello";	//Single argument constructor
    str2.print();
    String str3 = str2;	//Copy constructor
    str3.print();
    String str4();	//Здесь не вызывается никакой конструктор, потому что НЕ создается объект,
    //Здесь объявлется функция str4(), которая не принимает никаких параметров,
    //и возвращает значение типа String.
//str4.print();	//str4 - это НЕ объект, это функция, а для функции нельзя вызвать метод.
//Если мы хотим явно вызвать конструктор по умолчанию, то это можно сделать так:
    String str5{};	//Явный вызов конструктора по умолчанию.
    str5.print();
    String str6{ 22 };
    str6.print();
    String str7{ "World" };
    str7.print();
    String str8 = str2 + str7;	//Copy constructor
    cout << str8 << endl;
    // Run program: Ctrl + F5 or Debug > Start Without Debugging menu
    // Debug program: F5 or Debug > Start Debugging menu

    // Tips for Getting Started: 
    //   1. Use the Solution Explorer window to add/manage files
    //   2. Use the Team Explorer window to connect to source control
    //   3. Use the Output window to see build output and other messages
    //   4. Use the Error List window to view errors
    //   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
    //   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
}