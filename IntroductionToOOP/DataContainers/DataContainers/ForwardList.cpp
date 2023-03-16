//ForwardList
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

#include "ForwardList.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////                                   CLASS DEFENITION                                ///////////////////////


template<typename T>int Element<T>::count = 0;	//�������������� ���������� ����������, ����������� � ������ 'Element'

//////////////////////////////////////Element////////////////////////////////////////////


template<typename T>Element<T>::Element(T Data, Element<T>* pNext) :Data(Data), pNext(pNext)
{
    count++;
    cout << "EConstructor:\t" << this << endl;
}

template<typename T>Element<T>::~Element()
{
    count--;
    cout << "EDestructor:\t" << this << endl;
}

//////////////////////////////////////Iterator////////////////////////////////////////////

template<typename T>
Iterator<T>::Iterator(Element<T>* Temp) :Temp(Temp)
{
    cout << "ItConstructor:\t" << this << endl;
}
template<typename T>
Iterator<T>::~Iterator()
{
    cout << "ItDestructor:\t" << this << endl;
}

template<typename T>Iterator<T>& Iterator<T>::operator++()
{
    Temp = Temp->pNext;
    return *this;
}

template<typename T>

bool Iterator<T>::operator==(const Iterator<T>& other)const
{
    return this->Temp == other.Temp;
}

template<typename T>

bool Iterator<T>::operator!=(const Iterator<T>& other)const
{
    return this->Temp != other.Temp;
}

template<typename T>

T& Iterator<T>::operator*()
{
    return Temp->Data;
}

//////////////////////////////////////ForvardList////////////////////////////////////////////
template<typename T>Iterator<T> ForwardList<T>::begin()
{
    return Head;
}
template<typename T>Iterator<T> ForwardList<T>::end()
{
    return nullptr;
}
template<typename T>ForwardList<T>::ForwardList()
{
    Head = nullptr;	//���� ������ ����, �� ��� ������ ��������� �� 0
    size = 0;
    cout << "LConstructor:\t" << this << endl;
}
template<typename T>ForwardList<T>::ForwardList(const std::initializer_list<T>& il) :ForwardList()
{
    //il - initializer_list
    //initializer_list - ��� ���������.
    //��������� - ��� ������, ������� ���������� �������� ������ �������� � ������.
    //��� � � ������ ������� ����������, � initilizer_list ���� ������ begin() � end()
    //begin() - ���������� �������� �� ������ ����������.
    //end()   - ���������� �������� �� ����� ����������.
    cout << typeid(il.begin()).name() << endl;
    for (T const* it = il.begin(); it != il.end(); it++)
    {
        push_back(*it);
    }
}
template<typename T>ForwardList<T>::~ForwardList()
{
    while (Head)pop_front();
    cout << "LDestructor:\t" << this << endl;
}

//					Adding elements:
template<typename T>void ForwardList<T>::push_front(T Data)
{
    /*
    //1) ������� ����� �������:
    Element* New = new Element(Data);
    //2) ����� ������� ������ ��������� �� ������ ������:
    New->pNext = Head;
    //3) ������ ������ "���������" �� ����� �������:
    Head = New;
    */

    Head = new Element<T>(Data, Head);

    size++;
}
template<typename T>void ForwardList<T>::push_back(T Data)
{
    if (Head == nullptr)return push_front(Data);
    //1) ������� ����� �������:
    //Element* New = new Element(Data);
    //2) ������� �� ����� ������:
    Element<T>* Temp = Head;
    while (Temp->pNext)
        Temp = Temp->pNext;
    //3) ��������� ������� � ����� ������:
    Temp->pNext = new Element<T>(Data);
    size++;
}
template<typename T>void ForwardList<T>::insert(int Index, T Data)
{
    if (Index == 0)return push_front(Data);
    if (Index > size)return;

    //1) ������� ����� �������:
    //Element* New = new Element(Data);

    //2) ������� �� ������� ��������
    Element<T>* Temp = Head;
    for (int i = 0; i < Index - 1; i++)Temp = Temp->pNext;

    //3) ��������� ����� ������� � ������:
    //New->pNext = Temp->pNext;
    //Temp->pNext = New;
    Temp->pNext = new Element<T>(Data, Temp->pNext);

    size++;
}

//					Erasing Elements
template<typename T>void ForwardList<T>::pop_front()
{
    Element<T>* Erased = Head;	//1) ���������� ����� ���������� ��������
    Head = Head->pNext;		//2) ��������� ������� �� �������
    delete Erased;			//3) ������� ������� �� ������

    size--;
}

template<typename T>void ForwardList<T>::pop_back()
{
    Element<T>* Temp = Head;
    while (Temp->pNext->pNext)
    {
        Temp = Temp->pNext;
    }
    delete Temp->pNext;
    Temp->pNext = nullptr;
    size--;
}

//					Methods:
template<typename T>void ForwardList<T>::print()const
{
    /*Element* Temp = Head;	//Temp - ��� ��������
    //�������� - ��� ���������, ��� ������ �������� ����� �������� ������
    //� ��������� ��������� ������
    while (Temp)
    {
        cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
        Temp = Temp->pNext;	//������� �� ��������� �������
    }*/
    for (Element<T>* Temp = Head; Temp; Temp = Temp->pNext)
        cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;

    cout << "���������� ��������� ������:" << size << endl;
    cout << "����� ���������� ���������: " << Element::count << endl;
}


/////////////////                                   CLASS DEFENITION END                            ///////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////