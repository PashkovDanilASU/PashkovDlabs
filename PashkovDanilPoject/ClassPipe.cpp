#include "ClassPipe.h"
#include "ClassIntilization.h"

int Pipe:: get_ID() const{
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

 Pipe:: Pipe() {
	system("cls");
	id = ++MaxID;
	while (true) {
		cout << "Enter Pipe name, which have length (1-50):";
		cin >> std::ws;
		getline(cin, name);
		if (size(name) <= 50) {
			break;
		}
	};
	cout << "Enter pipe length in meters (10 - 2000): ";
	Validation::input_range(length, 2000., 10.);
	cout << "Enter pipe diametrs in millimeters (630 - 1420): ";
	Validation::input_range(diametr, 1420, 630);
	Pipe::ready_unready_pipe(ready_unready);
	Menu::back_to_menu();
};

 std::ostream& operator << (std::ostream& out, const Pipe& pipe) {
	 out << endl << "Pipe id: " << pipe.get_ID() << endl
		 << "Pipe's name: " << pipe.name << endl
		 << "Pipe diameter: " << pipe.diametr << endl
		 << "Pipe length: " << pipe.length << endl
		 << "Pipe readiness : " << (pipe.ready_unready ? "in repair" : "not in repair") << endl << endl;
	 return out;
 }





