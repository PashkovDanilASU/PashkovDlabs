// PashkovDanilPoject.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
#include "PashkovDanilPoject.h"
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

struct pipeline
{
    int id = 1 , diametr = 0;
    double length = 0;
    bool ready_unready = false;
};

struct CS
{ 
    int id = 1 , count = 0, count_ready = 0, performance = 0;
    string name;
};

                                        // INPUT VALIDATION
bool is_input_valid()
{
    if (cin.peek() != '\n' || !cin)
    {
        cout << "You entered an invalid number, enter a new number: ";
        cin.clear();
        cin.ignore(10000, '\n');
        return false;
    }
    return true;

};

                                        /**/

                                // PIPE
void length_pipe(double& length)
{
    cout << "Enter pipe length in meters (10 - 20): ";
    while (true)
    {
        cin >> length;
        if (is_input_valid() && (length > 20 || length < 10))
        {
            cout << "You entered an invalid number, enter a new number: ";
        }
        else if (is_input_valid())
        {
            break;
        }
    };
};

void diametr_pipe(int& diametr)
{
    cout << "Enter pipe diametrs in millimeters (630 - 1420): ";
    while (true)
    {
        cin >> diametr;
        if (is_input_valid() && (diametr > 1420 || diametr < 630))
        {
            cout << "You entered an invalid number, enter a new number: ";
        }
        else if (is_input_valid())
        {
            break;
        }
    };  
};

void ready_unready_pipe(bool& repair)
{
    cout << "in Rrepair or not in repair? Press on your keyboard 'y' or 'n'. ";
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

void pipe_ready_info(bool& reapir)
{
    if (reapir)
    {
        cout << "in repair" << endl;
    }
    else
    {
        cout << "not in reapir" << endl;
    }
};

void input_pipe_info(pipeline& new_pipe)
{
    length_pipe(new_pipe.length);
    diametr_pipe(new_pipe.diametr);
    ready_unready_pipe(new_pipe.ready_unready);
};

void output_pipe_info(pipeline& new_pipe)
{
    if (new_pipe.length != 0)
    {
        cout << "Pipe characteristics." << endl << "Length pipe: " << new_pipe.length << endl
            << "Diamtre pipe: " << new_pipe.diametr << endl << "Pipe readiness: ";
        pipe_ready_info(new_pipe.ready_unready);
        cout << endl;
    }
};
                                    /**/

                            // CS
void CS_name(string& name_CS)
{
    while (true)
    {
        cout << "Enter CS name, which have length (1-50):";
        cin >> std::ws;
        getline(cin, name_CS);
        if (size(name_CS) <= 50)
        {
            break;
        }
    };
};

void CS_count(int& count)
{
    cout << "Enter CS count (1-15): ";
    while (true)
    {
        cin >> count;
        if (is_input_valid() && (count > 15 || count < 1))
        {
            cout << "You entered an invalid number, enter a new number: ";
        }
        else if (is_input_valid())
        {
            break;
        }

    };
 
};

void CS_count_ready(int& count, int& count_ready)
{
    cout << "Enter CS which ready to work, in range (0 to n), where n your CS. ";
    while (true)
    {
        cin >> count_ready;
        if (is_input_valid() && (count < count_ready || count_ready < 0))
        {
            cout << "You entered an invalid number, enter a new number: ";
        }
        else if (is_input_valid())
        {
            break;
        }

    };
    
};

void CS_performance(int& performance)
{
    cout << "Enter the performance of CS, in range(0 to 100%): ";
    while (true)
    {
        cin >> performance;
        if (is_input_valid() && (performance > 100 || performance < 0))
        {
            cout << "You entered an invalid number, enter a new number: ";
        }
        else if (is_input_valid())
        {
            break;
        }
    };
    
};

void input_CS_info(CS& new_CS)
{
    CS_name(new_CS.name);
    CS_count(new_CS.count);
    CS_count_ready(new_CS.count, new_CS.count_ready);
    CS_performance(new_CS.performance);
};

void output_CS_info(const CS& new_CS)
{
    if (new_CS.count != 0)
        cout << "CS characteristics." << endl << "CS name: " << new_CS.name << endl 
        << "CS count: " << new_CS.count << endl << "Count of serviceable CS: " 
        << new_CS.count_ready << endl << "CS performance: " << new_CS.performance << endl;
    cout << endl;
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

void show_all_objects(pipeline& new_pipe, const CS& new_CS)
{
    if (new_pipe.length == 0 && new_CS.count == 0)
    {
        cout << "Your Pipe and CS data are empty. Try again after adding info." << endl;
    }
    if (new_pipe.length != 0)
    {
        output_pipe_info(new_pipe);
    }
    if (new_CS.count != 0)
    {
        output_CS_info(new_CS);
    }
};

void back_to_menu()
{
    clear_console_space();
    menu_display();
}
                            /**/

                                                                          //SAVE & READ TO FILE
void output_pipe_to_file(const pipeline& new_pipe, std::ofstream& fsave)
{
    if (new_pipe.length != 0)
    {
        fsave << new_pipe.id << '\n'
            << new_pipe.length << '\n'
            << new_pipe.diametr << '\n'
            << new_pipe.ready_unready << '\n';
    }
};

void output_CS_to_file(const CS& new_CS, std::ofstream& fsave)
{
    if (new_CS.count != 0)
    {
        fsave << new_CS.id << '\n'
            << new_CS.name << '\n'
            << new_CS.count << '\n'
            << new_CS.count_ready << '\n'
            << new_CS.performance;
    }
};

void save_to_file(const CS& new_CS, const pipeline& new_pipe)
{
    std::ofstream fsave("information.txt");
    if (fsave.is_open())
    {
        output_pipe_to_file(new_pipe, fsave);
        fsave << " \n";
        output_CS_to_file(new_CS, fsave);
        fsave.close();
    }
    else {
        cout << "Error. File is missing or dont exist.\n";
    }
};

void read_from_file(CS& new_CS, pipeline& new_pipe)
{
    std::ifstream fread("information.txt");
    if (fread.is_open())
    {
        if (fread.peek() != -1)
        {
            while (fread.peek() != ' ')
            {
                fread >> new_pipe.id >> new_pipe.length >> new_pipe.diametr >> new_pipe.ready_unready;
                fread.ignore(1000, '\n');
            }
            fread.ignore(1000, '\n');
            while (fread.peek() != -1)
            {
                fread >> new_CS.id;
                fread.ignore(1000, '\n');
                getline(fread, new_CS.name);
                fread >> new_CS.count >> new_CS.count_ready >> new_CS.performance;
            }
            fread.close();
        }
        else
        {
            cout << "You dont load data to file to read it.\n";
        }
    }
    else
    {
        cout << "File cant be open or empty.";
    }
};
                                                                             /**/
int main()
{
    pipeline new_pipe;
    CS new_CS;
    int menu_navigator;
    menu_display();
    while (true)
    {
        cin >> menu_navigator;
        if (!is_input_valid())
        {
            menu_navigator = -1;
        }
            else if (menu_navigator > 7 || menu_navigator < 0)
            {
                menu_navigator = -1;
                cout << "You entered an invalid number, enter a new number: ";
            }
        cin.ignore(1000, '\n');
        switch (menu_navigator)
        {
        case 1:
            clear_console_space();
            input_pipe_info(new_pipe);
            back_to_menu();
        break;
        case 2:
            clear_console_space();
            input_CS_info(new_CS);
            back_to_menu();
            break;
        case 3:
            show_all_objects(new_pipe, new_CS);
            break;
        case 4:
            clear_console_space();
            if (new_pipe.length != 0)
            {
                cout << "Your pipe in: ";
                pipe_ready_info(new_pipe.ready_unready);
                ready_unready_pipe(new_pipe.ready_unready);
                back_to_menu();
            }
            else
            {
                back_to_menu();
                cout << endl << "You have not entered a pipe yet, press another button." << endl;
                break;
            }
            break;
        case 5:
            clear_console_space();
            if (new_CS.count != 0)
            {
                cout << "You had count of serviceable CS: " << new_CS.count_ready << endl;
                CS_count_ready(new_CS.count, new_CS.count_ready);
                back_to_menu();
            }
            else
            {
                back_to_menu();
                cout << endl << "You have not entered a CS yet, press another button" << endl;
                break;
            }
            break;
        case 6:
            save_to_file(new_CS, new_pipe);
            break;
        case 7:
            read_from_file(new_CS, new_pipe);
            break;
        case 0: 
            clear_console_space();
            return 0;
            break;
        default:
            break;
        };
    };
};