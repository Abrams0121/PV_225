//ForwardList
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

template<typename T>class ForwardList;
template<typename T>class Iterator;

template<typename T> class Element
{
    T Data;		//�������� ��������
    Element<T>* pNext;	//����� ���������� ��������
    static int count;
public:
    Element(T Data, Element<T>* pNext = nullptr);
    ~Element();
  
    friend class ForwardList<T>;
    friend class Iterator<T>;
};



template<typename T>class Iterator
{
    Element<T>* Temp;
public:
    Iterator(Element<T>* Temp = nullptr);
   
    ~Iterator();
    

    Iterator<T>& operator++();
    

    bool operator==(const Iterator<T>& other)const;
    
    bool operator!=(const Iterator<T>& other)const;
    
    T& operator*();
    

};

template <typename T>class ForwardList	//Forward - �����������, ����������������
{
    Element<T>* Head;	//������ ������ - �������� ��������� �� ������� ������� ������
    int size;
public:
    Iterator<T> begin();
    
    Iterator<T> end();
    
    ForwardList();
    
    ForwardList(const std::initializer_list<T>& il);
    
    ~ForwardList();
    

    //					Adding elements:
    void push_front(T Data);
    
    void push_back(T Data);
    
    void insert(int Index, T Data);
    

    //					Erasing Elements
    void pop_front();
   

    void pop_back();
    

    //					Methods:
    void print()const;
   
};

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

//#define BASE_CHECK
//#define RANGE_BASED_FOR_ARRAY
//#define HOME_WORK_1

void main()
{
    setlocale(LC_ALL, "");
#ifdef BASE_CHECK
    int n;
    cout << "������� ������ ������: "; cin >> n;
    ForwardList list;
    for (int i = 0; i < n; i++)
    {
        list.push_front(rand() % 100);
        //list.push_back(rand() % 100);
    }
    list.print();
    //list.push_back(123);

    int value;
    int index;
    cout << "������� ������ ������������ ��������: "; cin >> index;
    cout << "������� �������� ������������ ��������: "; cin >> value;
    list.insert(index, value);
    list.print();

    ForwardList list2;
    list2.push_back(3);
    list2.push_back(5);
    list2.push_back(8);
    list2.print();
#endif // BASE_CHECK

#ifdef RANGE_BASED_FOR_ARRAY
    int arr[] = { 3,5,8,13,21 };
    /*for (int i = 0; i < sizeof(arr)/sizeof(int); i++)
    {
        cout << arr[i] << tab;
    }
    cout << endl;*/

    //Range-based for
    //https://legacy.cplusplus.com/doc/tutorial/control/#:~:text=equal%20to%2050.-,Range%2Dbased%20for%20loop,-The%20for%2Dloop
    for (int i : arr)
    {
        cout << i << tab;
    }
    cout << endl;
#endif // RANGE_BASED_FOR_ARRAY

#ifdef HOME_WORK_1
    ForwardList list = { 3, 5, 8, 13, 21 };
    //list.print();
    for (int i : list)
    {
        cout << i << tab;
    }
    cout << endl;

    ForwardList list2 = { 34, 55, 89 };
    for (int i : list2)cout << i << tab; cout << endl;

    ForwardList list3 = list + list2;
    for (int i : list3)cout << i << tab; cout << end; 
#endif // HOME_WORK_1

    ForwardList<int> list = { 3, 5, 8, 13, 21 };
    for (int i : list)cout << i << tab; cout << endl;

    ForwardList < std::string > s_list = { "������","�����","�����" };
    for (std::string i : s_list)cout << i << tab; cout << endl;
};