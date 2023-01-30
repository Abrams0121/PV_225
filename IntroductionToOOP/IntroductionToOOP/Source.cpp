#include<iostream>
using namespace std;

class Fraction
{
    int numenator;
    int denumenator;
    int integer;

public:
    int get_numenator()const
    {
        return numenator;
    }

    int get_denumenator()const
    {
        return denumenator;
    }

    int get_integer()const
    {
        return integer;
    }

    void set_numenator(int numenator)
    {
        this->numenator = numenator;
    }

    void set_denumenator(int denumenator)
    {
        this->denumenator = denumenator;
    }
    void set_integer(int integer)
    {
        this->integer = integer;
    }
};

void main()
{

}