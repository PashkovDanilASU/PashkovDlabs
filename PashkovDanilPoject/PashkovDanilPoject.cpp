// PashkovDanilPoject.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "PashkovDanilPoject.h"
#include <fstream>
#include "ClassPipe.h"
#include "ClassCS.h"
#include "ClassMenu.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

struct pipeline{
	int id = 1, diametr = 0;
	double length = 0;
	bool ready_unready = false;
};

struct CS{
	int id = 1, count = 0, count_ready = 0, performance = 0;
	string name;
};

// CONSOLE
void clear_console_space(){
	system("cls");
};

void menu_display(){
	cout << "1. Add pipe\n"
		"2. Add CS\n"
		"3. View all objects\n"
		"4. Edit pipe\n"
		"5. Edit CS\n"
		"6. Save\n"
		"7. Load\n"
		"0. Exit\n";
};

void back_to_menu(){
	clear_console_space();
	menu_display();
}
/**/

// INPUT VALIDATION
bool is_input_valid(){
	if (!cin || cin.peek() != '\n')
	{
		cout << "You entered an invalid number, enter a new number: ";
		cin.clear();
		cin.ignore(10000, '\n');
		return false;
	}
	return true;

};

template <typename T>
void input_range(T& number, T max, T min){
	do
		cin >> number;
	while (!(is_input_valid() && (number <= max && number >= min)));
}

/**/

// PIPE
void ready_unready_pipe(bool& repair){
	cout << "in Rrepair or not in repair? Press on your keyboard 'y' or 'n'. ";
	char flagpipe;
	while (true)
	{
		flagpipe = cin.get();
		if (flagpipe == 'y')
		{
			repair = true;
			cin.ignore(10000, '\n');
			break;
		}
		else if (flagpipe == 'n')
		{
			repair = false;
			cin.ignore(10000, '\n');
			break;
		}
	}

};

void input_pipe_info(pipeline& new_pipe){
	clear_console_space();
	cout << "Enter pipe length in meters (10 - 2000): ";
	input_range(new_pipe.length, 2000., 10.);
	cout << "Enter pipe diametrs in millimeters (630 - 1420): ";
	input_range(new_pipe.diametr, 1420, 630);
	ready_unready_pipe(new_pipe.ready_unready);
	back_to_menu();
};


void pipe_ready_info(bool repair){
	cout << (repair ? "in repair" : "not in repair") << endl;
}

void output_pipe_info(const pipeline& new_pipe){
	if (new_pipe.length != 0){
		cout << "Pipe characteristics." << endl << "Length pipe: " << new_pipe.length << endl
			<< "Diamtre pipe: " << new_pipe.diametr << endl << "Pipe readiness: ";
		pipe_ready_info(new_pipe.ready_unready);
		cout << endl;
	}
};
/**/

// CS
void input_CS_info(CS& new_CS){
	clear_console_space();
	while (true){
		cout << "Enter CS name, which have length (1-50):";
		cin >> std::ws;
		getline(cin, new_CS.name);
		if (size(new_CS.name) <= 50){
			break;
		}
	};
	cout << "Enter CS count (1-15): ";
	input_range(new_CS.count, 15, 1);
	cout << "Enter CS which ready to work, in range (0 to n), where n your CS. ";
	input_range(new_CS.count_ready, new_CS.count, 0);
	cout << "Enter the performance of CS, in range(0 to 100%): ";
	input_range(new_CS.performance, 100, 0);
	back_to_menu();
};

void output_CS_info(const CS& new_CS){
	if (new_CS.count != 0)
		cout << "CS characteristics." << endl << "CS name: " << new_CS.name << endl
		<< "CS count: " << new_CS.count << endl << "Count of serviceable CS: "
		<< new_CS.count_ready << endl << "CS performance: " << new_CS.performance << endl;
	cout << endl;
};
/**/

// CONSOLE
void show_all_objects(const pipeline& new_pipe, const CS& new_CS){
	if (new_pipe.length == 0 && new_CS.count == 0){
		cout << "Your Pipe and CS data are empty. Try again after adding info." << endl;
	}
	if (new_pipe.length != 0){
		output_pipe_info(new_pipe);
	}
	if (new_CS.count != 0){
		output_CS_info(new_CS);
	}
};
/**/

											  //SAVE & READ TO FILE
void output_pipe_to_file(const pipeline& new_pipe, std::ofstream& fsave){
	if (new_pipe.length != 0){
		fsave << new_pipe.id << '\n'
			<< new_pipe.length << '\n'
			<< new_pipe.diametr << '\n'
			<< new_pipe.ready_unready << '\n';
	}
};

void output_CS_to_file(const CS& new_CS, std::ofstream& fsave){
	if (new_CS.count != 0){
		fsave << new_CS.id << '\n'
			<< new_CS.name << '\n'
			<< new_CS.count << '\n'
			<< new_CS.count_ready << '\n'
			<< new_CS.performance;
	}
};

void save_to_file(const CS& new_CS, const pipeline& new_pipe){
	std::ofstream fsave("information.txt");
	if (fsave.is_open()){
		output_pipe_to_file(new_pipe, fsave);
		fsave << " \n";
		output_CS_to_file(new_CS, fsave);
		fsave.close();
	}
	else {
		cout << "Error. File is missing or dont exist.\n";
	}
};

void read_from_file(CS& new_CS, pipeline& new_pipe){
	std::ifstream fread("information.txt");
	if (fread.is_open()){
		if (fread.peek() != -1){
			while (fread.peek() != ' '){
				fread >> new_pipe.id >> new_pipe.length >> new_pipe.diametr >> new_pipe.ready_unready;
				fread.ignore(1000, '\n');
			}
			fread.ignore(1000, '\n');
			while (fread.peek() != -1){
				fread >> new_CS.id;
				fread.ignore(1000, '\n');
				getline(fread, new_CS.name);
				fread >> new_CS.count >> new_CS.count_ready >> new_CS.performance;
			}
			fread.close();
		}
		else{
			cout << "You dont load data to file to read it.\n";
		}
	}
	else{
		cout << "File cant be open or empty.";
	}
};
/**/
int main()
{
	Pipe pipe1;
	pipeline new_pipe;
	CS new_CS;
	int menu_navigator;
	menu_display();
	while (true){
		input_range(menu_navigator, 7, 0);
		switch (menu_navigator){
		case 1:{
			input_pipe_info(new_pipe);
			break;
		}
		case 2:
			input_CS_info(new_CS);
			break;
		case 3:
			show_all_objects(new_pipe, new_CS);
			break;
		case 4:
			if (new_pipe.length != 0){
				cout << "Your pipe in: ";
				pipe_ready_info(new_pipe.ready_unready);
				ready_unready_pipe(new_pipe.ready_unready);
			back_to_menu();
			}
			else{
			back_to_menu();
				cout << endl << "You have not entered a pipe yet, press another button." << endl;
				break;
			}
			break;
		case 5:
			clear_console_space();
			if (new_CS.count != 0){
				cout << "You had count of serviceable CS: " << new_CS.count_ready << endl;
				input_range(new_CS.count_ready, new_CS.count, 0);
				back_to_menu();
			}
			else{
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