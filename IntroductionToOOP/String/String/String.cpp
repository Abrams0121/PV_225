// String.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class String;
String operator+(const String& left, const String& right);

class String
{
    int size;
    char* str;
    
public:
    int get_size()const
    {
        return size;
    }
    const char* get_str()const
    {
        return str;
    }
    char* get_str()
    {
        return str;
    }
    //              Constructors:
    
    String(int size = 80):size(size),str(new char[size] {})
    {
        
        cout << "DefaultConstructor:\t" << this << endl;
    }
    String(const char* str) :String(strlen(str) + 1)
    {

        for (int i = 0; i < size; i++)this->str[i] = str[i];
        cout << "1ArgConstructor:\t" << this << endl;        
    }

    String(const String& other): String(other.str)
    {
        //Deep copy - ��������� �����������
        /*this->size = other.size;
        this->str = new char[size] {};
        for (int i = 0; i < size; i++)
            this->str[i] = other.str[i];*/
        cout << "CopyConstructor:\t" << endl;
    }
    String(String&& other)noexcept
    {
            // shalow copy
            this->size = other.size;
            this->str = other.str;
            other.size = 0;
            other.str = nullptr;
            cout << "Move constructor:\t" << this << endl;
    }


    // destructors

    ~String()
    {
        delete this->str;
        cout << "Destructor:\t" << this << endl;
    }

    // operators

    String& operator=(const String& other)
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

    String& operator=(String&& other)
    {
        this->size = other.size;
        this->str = other.str;
        this->size = 0;
        this->str = nullptr;
        cout << "MoveAssigment:\t" << this << endl;
        return *this;
    }


    String& operator+=(const String& other)
    {
        return *this = *this + other;
    }

    const char& operator[](int i)const
    {
        return str[i];
    }
    char& operator[](int i)
    {
        return str[i];
    }


    //          methods:

    void print()
    {
        cout << "Size:\t" << size << endl;
        cout << "Str:\t" << str << endl;
    }

};

std::ostream& operator<<(std::ostream& os, const String& obj)
{
    return os << obj.get_str();
}

int main()
{
    setlocale(LC_ALL, "");
    String str1;	//Default constructor
    str1.print();
    String str2 = "Hello";	//Single argument constructor
    str2.print();
    String str3 = str2;	//Copy constructor
    str3.print();
    String str4();	//����� �� ���������� ������� �����������, ������ ��� �� ��������� ������,
    //����� ���������� ������� str4(), ������� �� ��������� ������� ����������,
    //� ���������� �������� ���� String.
//str4.print();	//str4 - ��� �� ������, ��� �������, � ��� ������� ������ ������� �����.
//���� �� ����� ���� ������� ����������� �� ���������, �� ��� ����� ������� ���:
    String str5{};	//����� ����� ������������ �� ���������.
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