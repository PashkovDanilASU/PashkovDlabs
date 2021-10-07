// PashkovDanilPoject.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
#include "PashkovDanilPoject.h"

using namespace std;

struct pipeline
{
    int id;
    double length;
    int diametr;
    bool ready_unready;
};

struct CS
{ 
    int id;
    string name;
    int count;
    int count_ready;
    double performance;
};

//PIPE
void length_pipe(double& length)
{
    cout << "Enter pipe length in meters:";
    cin >> length;
};

void diametr_pipe(int& diametr)
{
    cout << "Enter pipe diametrs in millimeters:";
    cin >> diametr;
};

void ready_unready_pipe(bool& repair)
{
    cout << "in Repair or not in repair? Push on your keyboard 'y' or 'n'. ";
    char flagpipe;
    while (true)
    {
        flagpipe= cin.get();
        if (flagpipe == 'y') 
        {
            repair = true;
            break;
        }
        else if (flagpipe == 'n') 
        {
            repair = false;
            break;
        }
    }
    
};
//PIPE

//CS
void CS_name(string& name)
{
    cout << "Enter CS name:";
    getline(cin, name);
};

void CS_count(int& count)
{
    cout << "Enter CS count:";
    cin >> count;
};

void CS_count_ready(int& count_ready)
{
    cout << "Enter CS which ready to work, in range (0 to n), where n your CS.";
    cin >> count_ready;
};

void CS_performance(double& performance)
{
    cout << "Enter the performance of CS, in range(0 to 100%).";
    cin >> performance;
};
//CS

//CONSOLE
void clear_console_space()
{
    cout << string(30, '\n');
};

void menu_display()
{
    cout << "1. Add pipe\n"
        "2. Add CS\n"
        "3. View all objects\n"
        "4. Edit pipe\n"
        "5. Edit CS\n"
        "6. Edit pipe\n"
        "7. Save\n"
        "8. Load\n"
        "0. Exit\n";
};
//CONSOLE

int main()
{
    pipeline new_pipe;
    CS new_CS;
    new_pipe.id = 1;
    new_CS.id = 1;

    menu_display();
    CS_name(new_CS.name);
    length_pipe(new_pipe.length);
    diametr_pipe(new_pipe.diametr);
    return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

