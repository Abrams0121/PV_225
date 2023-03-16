#include <iostream>
#include <windows.h>

using namespace std;

enum Color
{
    blue = 0x00ff0000,
    console_blue = 0x99,
    console_green = 0xAA,
    console_red = 0xCC,
    console_default = 0x07

};

namespace Geometry
{


    class Shape
    {

        
        


    public:
        Shape(Color color) :color(color) {}
        virtual ~Shape() {}

        virtual double get_area()const = 0;
        virtual double get_perimeter()const = 0;
        virtual void draw()const = 0;
    
    protected:
        Color color;
        const int MIN_START_POSITION_X = 50;
        const int MIN_START_POSITION_Y = 50;

        const int MAX_START_POSITION_X = 300;
        const int MAX_START_POSITION_Y = 300;
        

    };

    class Rectangle : Shape
    {
        const int MIN_LENGHT = 50;
        const int MIN_WIDHT = 50;

        const int MAX_LENGHT = 50;
        const int MAX_WIDTH = 50;

        double A_D_Side, B_C_Side;

        int rect_start_pos_x, rect_start_pos_y;
        

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

            HPEN hpen = CreatePen(PS_SOLID, 1,color);
            HBRUSH hbrush = CreateSolidBrush(blue);

            SelectObject(hDC, hpen);
            SetDCPenColor(hDC, RGB(0, 0, 255));

            

            MoveToEx(hDC, 50, 50, &op);
            
            ::Rectangle(hDC, 0, 0, 0, 0);


            DeleteObject(hpen);
            DeleteObject(hbrush);

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
            if (A_D_Side < MIN_WIDHT)this->A_D_Side = MIN_WIDHT;
            if (A_D_Side > MAX_WIDTH)this->A_D_Side = MAX_WIDTH;
            
            this->A_D_Side = A_D_Side;
        }

        void set_B_C_Side(double B_C_Side)
        {
            if (B_C_Side < MIN_LENGHT)B_C_Side = MIN_LENGHT;
            if (B_C_Side > MAX_LENGHT)B_C_Side = MAX_LENGHT;

            this->B_C_Side = B_C_Side;
        }

        void set_rect_start_pos_x(int rect_start_pos_x)
        {
            if (rect_start_pos_x < MIN_START_POSITION_X)rect_start_pos_x = MIN_START_POSITION_X;
            if (rect_start_pos_x > MAX_START_POSITION_X)rect_start_pos_x = MAX_START_POSITION_X;
            this->rect_start_pos_x = rect_start_pos_x;
        }
        void set_rect_start_posx_y(int rect_start_pos_y)
        {
            if (rect_start_pos_y < MIN_START_POSITION_Y)rect_start_pos_y = MIN_START_POSITION_Y;
            if (rect_start_pos_y > MAX_START_POSITION_Y)rect_start_pos_y = MAX_START_POSITION_Y;
            this->rect_start_pos_y = rect_start_pos_y;
        }

        Rectangle(int start_pos_x,int start_pos_y,double A_D_Side, double B_C_Side) : Shape(console_blue)
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


    class Rect
    {

   

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
    
    Geometry::Rectangle rect1(0,0,6.32, 4.43);

    rect1.draw();
}