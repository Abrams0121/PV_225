#include<iostream>
#include<array>
#include<vector>
#include<deque>
#include<list>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n--------------------------\n"

//https://legacy.cplusplus.com/reference/stl/

template<typename T>void vector_properties(const std::vector<T>& vec)
{
    cout << "Size:\t\t" << vec.size() << endl;
    cout << "Capacity:\t" << vec.capacity() << endl;
    cout << "Max size:\t" << vec.max_size() << endl;
}

//#define STL_ARRAY
//#define STL_VECTOR
//#define STL_DEQUE
#define STL_LIST

void main()
{
    setlocale(LC_ALL, "");
#ifdef STL_ARRAY
    //array - ��� ���������, ������� ������ ������ � ���� ������������ �������.
    const int N = 5;
    std::array<int, N> arr = { 3, 5, 8 };
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr.data()[i] << tab;
    }
    cout << endl;
#endif // STL_ARRAY

#ifdef STL_VECTOR
    //vector - ��� ���������, ������� ������ ������ � ���� ������������� �������.
    //vector ��������� ��������� �������� ������ � �����, � ������� �������� ������ � �����,
    //��� �� ������ ������� � �������� �� �������.
    std::vector<int> vec = { 0, 55, 1, 1, 2, 3, 5, 8, 13, 21, 34 };
    vec.resize(22);
    for (int i = 0; i < vec.capacity(); i++)
    {
        cout << vec[i] << tab;
        //cout << vec.at(i) << tab;
    }
    cout << endl;
    vec.resize(8);
    try
    {
        for (int i = 0; i < vec.capacity(); i++)
        {
            //cout << vec[i] << tab;
            cout << vec.at(i) << tab;
        }
        cout << endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << endl;
    }
    vector_properties(vec);
    cout << delimiter << endl;
    std::vector<int> vec2(100);
    vector_properties(vec2);
    cout << delimiter << endl;
    vec2.push_back(123);
    vector_properties(vec2);
    //cout << delimiter << endl;
    //vec2.shrink_to_fit();	//������� ��� ����������������� ������, �.�., ��������� capacity �� ������������ ������� (size)
    //vector_properties(vec2);
    cout << delimiter << endl;
    for (int i = 0; i < 90; i++)vec2.pop_back();
    vector_properties(vec2);
    cout << delimiter << endl;
    vec2.reserve(255);
    vec2.resize(8);
    vector_properties(vec2);

#endif // STL_VECTOR

#ifdef STL_DEQUE
    std::deque<int> deque = { 3,5,8,13,21 };

    for (int i = 0; i < deque.size(); i++)
    {
        cout << deque[i] << tab;
    }

    cout << endl;
    deque.push_front(2);
    deque.push_back(34);
    for (int i : deque) cout << deque[i];
#endif // STL_DEQUE

    std::list<int> list = { 1,2,65,4,73,74,374, };
    for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
    {
        cout << *it << endl;
    }
}