#include <iostream>
#include <windows.h>

using namespace std;

enum Color
{
    console_blue = 0x99,
    console_green = 0xAA,
    console_red = 0xCC,
    console_default = 0x07

};

namespace Geimetry
{


    class Shape
    {
        Color color;

    public:
        Shape(Color color) :color(color) {}
        virtual ~Shape() {}

        virtual double get_area()const = 0;
        virtual double get_perimeter()const = 0;
        virtual void draw()const = 0;



    };

    class Rectangle : Shape
    {

        double A_D_Side, B_C_Side;

    public:

        virtual double get_area()const
        {
            return A_D_Side * B_C_Side;
        }

        virtual double get_perimeter()const
        {
            return (A_D_Side * 2) + (B_C_Side * 2);
        }

        virtual void draw()const
        {
            POINT op;
            HWND hWnd = GetConsoleWindow();
            HDC hDC = GetDC(hWnd);
            SelectObject(hDC, GetStockObject(WHITE_PEN));
            SetDCPenColor(hDC, RGB(0, 0, 255));

            int x = this->A_D_Side * 38;
            int y = this->B_C_Side * 38;

            int first_destanation_x = 50 + x, first_destanation_y = 50;
            int second_destanation_x = first_destanation_x, second_destanation_y = first_destanation_y + y;
            int third_destanation_x = first_destanation_x - x, third_destanation_y = second_destanation_y;

            MoveToEx(hDC, 50, 50, &op);
            LineTo(hDC, first_destanation_x, first_destanation_y);
            LineTo(hDC, second_destanation_x, second_destanation_y);
            LineTo(hDC, third_destanation_x, third_destanation_y);
            LineTo(hDC, 50, 50);


            ReleaseDC(hWnd, hDC);
            std::cin.get();
        }

        double get_A_D_Side()const
        {
            return A_D_Side;
        }

        double get_B_C_Side()const
        {
            return B_C_Side;
        }

        void set_A_D_Side(double A_D_Side)
        {
            this->A_D_Side = A_D_Side;
        }

        void set_B_C_Side(double B_C_Side)
        {
            this->B_C_Side = B_C_Side;
        }

        Rectangle(double A_D_Side, double B_C_Side) : Shape(console_blue)
        {
            set_A_D_Side(A_D_Side);
            set_B_C_Side(B_C_Side);
            cout << "RectConstructor" << this << endl;
        }

        ~Rectangle()
        {
            cout << "RectDestructor" << this << endl;
        }

    };
}


void main()
{
    setlocale(LC_ALL, "");

    /*POINT op;
    HWND hWnd = GetConsoleWindow();
    HDC hDC = GetDC(hWnd);
    SelectObject(hDC, GetStockObject(WHITE_PEN));

    MoveToEx(hDC, 50, 50, &op);
    LineTo(hDC, 300, 50);

    ReleaseDC(hWnd, hDC);
    std::cin.get();*/
    
    Geimetry::Rectangle rect1(6.32, 4.43);

    rect1.draw();
}