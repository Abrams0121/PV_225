// Files.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

#define WRITE_TO_FILE
//#define READ_FROM_FILE


int main()
{
    setlocale(LC_ALL, "");
    const string FILE = "File.txt";
    //1    Создание потока.

    

#ifdef WRITE_TO_FILE

    char filename[_MAX_FNAME] = {};
    cout << "Введите имя файла: ";
    cin.getline(filename, _MAX_FNAME);
    if (strcmp(filename + strlen(filename) - 4, ".txt")) strcat_s(filename, _MAX_FNAME, ".txt");
    

    ofstream fout;
    fout.open(filename, std::ios_base::app);
    fout << "Hello Files" << endl;
    fout.close();
    
    cout << "Hello Files!" << endl;

    char sz_commmand[_MAX_FNAME] = "notepad ";
    strcat_s(sz_commmand, _MAX_FNAME, filename);
    system(sz_commmand);
#endif // WRITE_TO_FILE
#ifdef READ_FROM_FILE



    ifstream fin;
    fin.open(FILE);

    if (fin.is_open()) 
    {
        const int SIZE = 256;
        char sz_buffer[SIZE]{};
        while (!fin.eof())
        {
            //fin >> sz_buffer;
            fin.getline(sz_buffer, SIZE);
            cout << sz_buffer << endl;
        }
        fin.close();
    }
    else
    {
        std::cerr << "Error : File not found" << endl;
    }
#endif // DEBUG

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
