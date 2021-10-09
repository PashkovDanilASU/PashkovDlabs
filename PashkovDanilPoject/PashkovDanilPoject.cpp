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

// INPUT VALIDATION
void number_input_validation(bool& check)
{
    if (cin.peek() != '\n' || !cin) 
    {
        cout << "You entered an invalid number, enter a new number: ";
        cin.clear();
        cin.ignore(10000, '\n');
        check = false;
    }
    else 
    {
        check = true;
    }
};
/**/


// PIPE
void length_pipe(double& length)
{
    cout << "Enter pipe length in meters (10 - 20):";
    bool check;
    while (true)
    {
        cin >> length;
        number_input_validation(check);
        if (check && (length > 20 || length < 10))
        {
            cout << "You entered an invalid number, enter a new number: ";
        }
        else if (check)
        {
            break;
        }
    };
};

void diametr_pipe(int& diametr)
{
    cout << "Enter pipe diametrs in millimeters (630 - 1420):";
    bool check;
    while (true)
    {
        cin >> diametr;
        number_input_validation(check);
        if (check && (diametr > 1420 || diametr < 630))
        {
            cout << "You entered an invalid number, enter a new number: ";
        }
        else if (check)
        {
            break;
        }
    };  
};

void ready_unready_pipe(bool& repair)
{
    cout << "in Rrepair or not in repair? Push on your keyboard 'y' or 'n'. ";
    char flagpipe;
    while (true)
    {
        flagpipe= cin.get();
        if (flagpipe == 'y') 
        {
            repair = true;
            cin.clear();
            cin.ignore(10000, '\n');
            break;
        }
        else if (flagpipe == 'n') 
        {
            repair = false;
            cin.clear();
            cin.ignore(10000, '\n');
            break;
        }
    }
    
};
/**/

// CS
void CS_name(string& name)
{
    cout << "Enter CS name:";
    getline(cin, name);
};

void CS_count(int& count)
{
    cout << "Enter CS count (1-15):";
    bool check;
    while (true)
    {
        cin >> count;
        number_input_validation(check);
        if (check && (count > 15 || count < 1))
        {
            cout << "You entered an invalid number, enter a new number: ";
        }
        else if (check)
        {
            break;
        }

    };
 
};

void CS_count_ready(int& count, int& count_ready)
{
    cout << "Enter CS which ready to work, in range (0 to n), where n your CS.";
    bool check;
    while (true)
    {
        cin >> count_ready;
        number_input_validation(check);
        if (check && (count < count_ready || count_ready < 0))
        {
            cout << "You entered an invalid number, enter a new number: ";
        }
        else if (check)
        {
            break;
        }

    };
    
};

void CS_performance(double& performance)
{
    cout << "Enter the performance of CS, in range(0 to 100%).";
    bool check;
    while (true)
    {
        cin >> performance;
        number_input_validation(check);
        if (check && (performance > 100 || performance < 0))
        {
            cout << "You entered an invalid number, enter a new number: ";
        }
        else if (check)
        {
            break;
        }
    };
    
};
/**/

// CONSOLE
void clear_console_space()
{
    system("cls");
};

void menu_display()
{
    cout << "1. Add pipe\n"
        "2. Add CS\n"
        "3. View all objects\n"
        "4. Edit pipe\n"
        "5. Edit CS\n"
        "6. Save\n"
        "7. Load\n"
        "0. Exit\n";
};

void back_to_menu()
{
    clear_console_space();
    menu_display();
}
/**/

int main()
{
    pipeline new_pipe;
    CS new_CS;
    new_pipe.id = 1;
    new_CS.id = 1;
    int menu_navigator;
    menu_display();
    while (true)
    {
        menu_navigator = getchar();
        cin.clear();
        cin.ignore(10000, '\n');
        switch (menu_navigator)
        {
        case '1':
            clear_console_space();
            length_pipe(new_pipe.length);
            diametr_pipe(new_pipe.diametr);
            ready_unready_pipe(new_pipe.ready_unready);
            back_to_menu();
        break;
        case '2':
            clear_console_space();
            CS_name(new_CS.name);
            CS_count(new_CS.count);
            CS_count_ready(new_CS.count, new_CS.count_ready);
            CS_performance(new_CS.performance);
            back_to_menu();
            break;
        case '3':
            clear_console_space();
            cout << "Pipe characteristics." << endl << "Length pipe: " << new_pipe.length << endl << "Diamtre pipe: " << new_pipe.diametr << endl << "Pipe readiness: " << new_pipe.ready_unready << endl
            << endl << "CS characteristics." << endl << "CS name:" << new_CS.name << endl << "CS count:" << new_CS.count << endl << "count of serviceable CS: " << new_CS.count_ready << endl << "CS performance: " << new_CS.performance;
            back_to_menu();
        break;
        case '0': 
            clear_console_space();
            return 0;
            break;
        default:
            break;
        };
    };
};



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

