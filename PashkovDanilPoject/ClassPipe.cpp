#include "ClassPipe.h"
#include "ClassIntilization.h"

int Pipe:: get_ID(){
	return  id;
}

void Pipe::set_ID(int value) {
	id = value;
}



void Pipe::ready_unready_pipe(bool& repair) {
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

int Pipe::MaxID = 0;

 void Pipe :: input_Pipe() {
	system("cls");
	id = ++MaxID;
	cout << "Enter pipe length in meters (10 - 2000): ";
	Validation::input_range(length, 2000., 10.);
	cout << "Enter pipe diametrs in millimeters (630 - 1420): ";
	Validation::input_range(diametr, 1420, 630);
	Pipe::ready_unready_pipe(ready_unready);
	Menu::back_to_menu();
};





