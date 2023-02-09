// String.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

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
    //              Constructors:
    
    String(int size = 80)
    {
        this->size = size;
        this->str = new char[size] {};
        cout << "DefaultConstructor:\t" << this << endl;
    }

    ~String()
    {
        delete this->str;
        cout << "Destructor:\t" << this << endl;
    }

    String(String&& other)noexcept
    {
        this->size = other.size;
        this->str = other.str;
        other.size = 0;
        other.str = nullptr;
        cout << "Move constructor:\t" << this << endl;
    }

    //          methods:

    void print()
    {
        cout << "Size:\t" << size << endl;
        cout << "Str:\t" << str << endl;
    }


    // operators

    String& operator=(String&& other)
    {
        this->size = other.size;
        this->str = other.str;
        this->size = 0;
        this->str = nullptr;
        cout << "MoveAssigment:\t" << this << endl;
        return *this;
    }


};

int main()
{
    setlocale(LC_ALL, "");
    String str1 = '4';
    str1.print();
    String str4();
    String str2{ 4434 };
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
