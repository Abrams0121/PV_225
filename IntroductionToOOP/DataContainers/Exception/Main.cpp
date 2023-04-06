#include <iostream>

using namespace std;
//#define exceptionbasic

void main()
{
    setlocale(LC_ALL, "");

#ifdef exceptionbasic

    try
    {
        throw 1;

        throw std::exception("STD exception thrown");
    }
    catch (int e)
    {
        std::cerr << "Err# " << e << std::endl;
    }
    catch (const std::exception e)
    {
        std::cerr << "Err# " << e.what() << std::endl;
    }
    catch (...)
    {

    }
#endif // DEBUG

    
    
}

