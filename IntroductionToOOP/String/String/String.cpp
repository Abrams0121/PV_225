#include "String.h"
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
