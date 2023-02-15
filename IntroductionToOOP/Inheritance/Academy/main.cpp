#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class Human
{
    std::string last_name;
    std::string first_name;
    tm birth_date;

public:
    
    const std::string& get_last_name()const
    {
        return   last_name;
    }

    const std::string& get_first_name()const
    {
            
    }
    tm get_birth_date()const
    {

    }

    unsigned int get_age()const
    {
        time_t t_today = time(NULL);
        
        tm* tm_today = localtime(&t_today);

        unsigned int age = tm_today->tm_year - birth_date.tm_year;
        if (tm_today->tm_mon < birth_date.tm_mon)age--;
        if (tm_today->tm_mon == birth_date.tm_mon && tm_today->tm_mday < birth_date.tm_mday)age--;
        return age;
    }

    void set_last_name(const std::string& last_name)
    {
        this->last_name = last_name;
    }

    void set_first_name(const std::string& first_name)
    {
        this->first_name = first_name;
    }

    void set_birth_date(int year, int month, int day)
    {
        birth_date.tm_year = year - 1900;
        birth_date.tm_mon = month - 1;
        birth_date.tm_mday = day;
    }

    Human(const std::string& last_name, const std::string& first_name,int year,int month,int day)
    {
        set_last_name(last_name);
        set_first_name(first_name);
        set_birth_date(year, month, day);
        cout << "HConstructor\t" << this << endl;
    }
    ~Human()
    {
        cout << "HDestructor\t" << this << endl;
    }
    
    void info()
    {
        cout << first_name << "\t" << last_name << "\t" << get_age() << endl;
    }

private:

};

//#define Time_Check

class Student :  public Human
{
    std::string specialty;
    std::string group;
    double rating;
    double attendance;

public:
    std::string get_specialty()const
    {
        return specialty;
    }

    std::string get_group()const
    {
        return group;
    }

    double get_raiting()const
    {
        return rating;
    }

    double get_attendence()const
    {
        return attendance;
    }



private:

};



void main()
{
    setlocale(LC_ALL, "");
#ifdef Time_Check

    time_t t_today = time(NULL);

    tm* tm_today = localtime(&t_today);
    cout << tm_today->tm_year << "\t";
    cout << tm_today->tm_mon << "\t";
    cout << tm_today->tm_mday << "\t";
    cout << tm_today->tm_mday << "\t";
    cout << asctime(tm_today) << "\t";
#endif // Time_Check

    Human human("Тупенко", "Василий", 1990, 02, 01);
    human.info();

}