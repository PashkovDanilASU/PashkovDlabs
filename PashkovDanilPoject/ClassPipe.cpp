#include "ClassPipe.h"
#include "ClassIntilization.h"
#include "ClassMenu.h"

int Pipe:: get_ID() const{
	return  id;
}

void Pipe::set_ID(int value) {
	id = value;
}



void Pipe::ready_unready_pipe(bool& repair) {
	std::cout << "in Rrepair or not in repair? Press on your keyboard 'y' or 'n'. ";
	char flagpipe;
	while (true)
	{
		flagpipe = std::cin.get();
		if (flagpipe == 'y')
		{
			repair = true;
			std::cin.ignore(10000, '\n');
			break;
		}
		else if (flagpipe == 'n')
		{
			repair = false;
			std::cin.ignore(10000, '\n');
			break;
		}
	}

};

int Pipe::MaxID = 0;

 Pipe:: Pipe() {
	system("cls");
	id = ++MaxID;
	while (true) {
		std::cout << "Enter Pipe name, which have length (1-50):";
		std::cin >> std::ws;
		getline(std::cin, name);
		if (size(name) <= 50) {
			break;
		}
	};
	std::cout << "Enter pipe length in meters (10 - 2000): ";
	Validation::input_range(length, 2000., 10.);
	std::cout << "Enter pipe diametrs in millimeters (630 - 1420): ";
	Validation::input_range(diametr, 1420, 630);
	Pipe::ready_unready_pipe(ready_unready);
	Menu::back_to_menu();
};

 std::ostream& operator << (std::ostream& out, const Pipe& pipe) {
	 out << std::endl << "Pipe id: " << pipe.get_ID() << std::endl
		 << "Pipe's name: " << pipe.name << std::endl
		 << "Pipe diameter: " << pipe.diametr << std::endl
		 << "Pipe length: " << pipe.length << std::endl
		 << "Pipe readiness : " << (pipe.ready_unready ? "in repair" : "not in repair") << std::endl << std::endl;
	 return out;
 }

 std::ofstream& operator << (std::ofstream& f_out, const Pipe& pipe) {
	f_out << pipe.get_ID() << std::endl << pipe.name << std::endl << pipe.diametr << std::endl
		<< pipe.length << std::endl;
	f_out << pipe.ready_unready << std::endl;
	return f_out;
}

 std::ifstream& operator >> (std::ifstream& f_in, Pipe& pipe) {
	int x, buf = 0;
	f_in >> x >> std::ws;
	if (buf <= x) {
		buf = x;
		Pipe::MaxID = x;
	}
	pipe.set_ID(x);
	getline(f_in, pipe.name);
	f_in >> pipe.length;
	f_in >> pipe.diametr;
	f_in >> pipe.ready_unready;
	f_in >> std::ws;
	return f_in;
}

Pipe:: Pipe(std::ifstream& in) {
	name = "";
	length = 0;
	diametr = 0;
	ready_unready = false;
}