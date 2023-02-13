// String.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


/// <summary>
/// Обьявление класса - CLASS DECLARATION
/// </summary>
class String;
String operator+(const String& left, const String& right);

class String
{
    int size;
    char* str;
    
public:
    int get_size()const;
    const char* get_str()const;
    char* get_str();
    //              Constructors:
    
    String(int size = 80);
    String(const char* str);

    String(const String& other);
    String(String&& other)noexcept;


    // destructors

    ~String();

    // operators

    String& operator=(const String& other);

    String& operator=(String&& other);


    String& operator+=(const String& other);

    const char& operator[](int i)const;
    char& operator[](int i);


    //          methods:

    void print();

};


/// <summary>
/// CLASS DECLARATION END
/// CLASS DEFINITION
/// </summary>


int String::get_size()const
{
    return size;
}
const char* String::get_str()const
{
    return str;
}
char* String::get_str()
{
    return str;
}
//              Constructors:

String::String(int size) :size(size), str(new char[size] {})
{

    cout << "DefaultConstructor:\t" << this << endl;
}
String::String(const char* str) :String(strlen(str) + 1)
{

    for (int i = 0; i < size; i++)this->str[i] = str[i];
    cout << "1ArgConstructor:\t" << this << endl;
}

String::String(const String& other) : String(other.str)
{
    //Deep copy - побитовое копирование
    /*this->size = other.size;
    this->str = new char[size] {};
    for (int i = 0; i < size; i++)
        this->str[i] = other.str[i];*/
    cout << "CopyConstructor:\t" << endl;
}
String::String(String&& other)noexcept
{
    // shalow copy
    this->size = other.size;
    this->str = other.str;
    other.size = 0;
    other.str = nullptr;
    cout << "Move constructor:\t" << this << endl;
}


// destructors

String::~String()
{
    delete this->str;
    cout << "Destructor:\t" << this << endl;
}

// operators

String& String::operator=(const String& other)
{
    //			l-value = r-value;
    if (this == &other)return *this;
    delete[] this->str;
    this->size = other.size;
    this->str = new char[size] {};
    for (int i = 0; i < size; i++)
        this->str[i] = other.str[i];
    cout << "CopyAssignment:\t" << this << endl;
    return *this;
}

String& String::operator=(String&& other)
{
    this->size = other.size;
    this->str = other.str;
    this->size = 0;
    this->str = nullptr;
    cout << "MoveAssigment:\t" << this << endl;
    return *this;
}


String& String::operator+=(const String& other)
{
    return *this = *this + other;
}

const char& String::operator[](int i)const
{
    return str[i];
}
char& String::operator[](int i)
{
    return str[i];
}


//          methods:

void String::print()
{
    cout << "Size:\t" << size << endl;
    cout << "Str:\t" << str << endl;
}

String operator+(const String& left, const String& right)
{
    String cat(left.get_size() + right.get_size() - 1);
    for (int i = 0; i < left.get_size(); i++)
        cat[i] = left[i];
    //cat.get_str()[i] = left.get_str()[i];
    for (int i = 0; i < right.get_size(); i++)
        cat[i + left.get_size() - 1] = right[i];
    //cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
    return cat;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
    return os << obj.get_str();
}

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
    String str8{ str7 };	//Copy constructor

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