#include<iostream>
using namespace std;

class Element
{
    int Data;       // Значение элемента
    Element* pNext; // Указатель нас след элемент
public:
    Element(int Data, Element* pNext = nullptr) : Data(Data), pNext(pNext)
    {
        cout << "EConstructor:\t" << this << endl;
    }

    ~Element()
    {
        cout << "EDesctructor:\t" << this << endl;
    }
    friend class ForvardList;
};

class ForvardList
{
    Element* Head;
public:
    
    ForvardList()
    {
        Head = nullptr;
        cout << "LConstructor"<<this<<endl;
    }

    ~ForvardList()
    {
        cout << "LDestructor\t" << this << endl;
    }


    void push_Front(int Data)
    {
        Head = new Element(Data,Head);
            
    }
};



void main()
{
    setlocale(LC_ALL, "");
}