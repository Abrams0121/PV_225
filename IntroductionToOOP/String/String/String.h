//String.h
#pragma once
// String.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


/// <summary>
/// Обьявление класса - CLASS DECLARATION
/// </summary>
class String;
String operator+(const String& left, const String& right);
std::ostream& operator<<(std::ostream& os, const String& obj);

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

