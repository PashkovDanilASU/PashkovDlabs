// PashkovDanilPoject.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "PashkovDanilPoject.h"
#include <fstream>
#include "ClassCS.h"
#include "ClassPipe.h"
#include "ClassMenu.h"
#include "ClassIntilization.h"

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

/**/

// INPUT VALIDATION
/**/



// PIPE
void ready_unready_pipe(bool& repair) {
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
	ver :: input_range(new_pipe.length, 2000., 10.);
	cout << "Enter pipe diametrs in millimeters (630 - 1420): ";
	ver :: input_range(new_pipe.diametr, 1420, 630);
	ready_unready_pipe(new_pipe.ready_unready);
	Menu:: back_to_menu();
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
	ver :: input_range(new_CS.count, 15, 1);
	cout << "Enter CS which ready to work, in range (0 to n), where n your CS. ";
	ver :: input_range(new_CS.count_ready, new_CS.count, 0);
	cout << "Enter the performance of CS, in range(0 to 100%): ";
	ver :: input_range(new_CS.performance, 100, 0);
	Menu:: back_to_menu();
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
	pipeline new_pipe;
	CS new_CS;
	int menu_navigator;
	Menu :: menu_display();
	while (true){
		ver :: input_range(menu_navigator, 7, 0);
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
				Menu:: back_to_menu();
			}
			else{
				Menu::back_to_menu();
				cout << endl << "You have not entered a pipe yet, press another button." << endl;
				break;
			}
			break;
		case 5:
			clear_console_space();
			if (new_CS.count != 0){
				cout << "You had count of serviceable CS: " << new_CS.count_ready << endl;
				ver :: input_range(new_CS.count_ready, new_CS.count, 0);
				Menu:: back_to_menu();
			}
			else{
				Menu:: back_to_menu();
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