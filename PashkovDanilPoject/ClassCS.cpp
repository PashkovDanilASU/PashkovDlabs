#include "ClassCS.h"
#include "ClassMenu.h"
#include "ClassIntilization.h"
#include <iostream>


int CS::get_ID() const{
	return  id;
}

void CS::set_ID(int value) {
	id = value;
}

int CS::MaxID = 0;

CS :: CS()
{
	id = ++MaxID;
	system("cls");
	while (true) {
		std::cout << "Enter CS name, which have length (1-50):";
		std::cin >> std::ws;
		getline(std::cin, name);
		if (size(name) <= 50) {
			break;
		}
	};
	std::cout << "Enter workshops count (1-15): ";
	Validation::input_range(count, 15, 1);
	std::cout << "Enter workshops which ready to work, in range (0 to n), where n your CS. ";
	Validation::input_range(count_ready, count, 0);
	std::cout << "Enter the performance of CS, in range(0 to 100%): ";
	Validation::input_range(performance, 100, 0);
	Menu::back_to_menu();
};

std::ostream& operator << (std::ostream& out, const CS& cs) {
	out << std::endl << "CS id: " << cs.get_ID() << std::endl << "CS name: " << cs.name << std::endl
		<< "CS count workshops: " << cs.count
		<< std::endl << "CS count ready workshops: " << cs.count_ready
		<< std::endl << "CS performance: " << cs.performance << std::endl;
	return out;
}

CS::CS(std::ifstream& in) {
	name = "";
	count = 0;
	count_ready = 0;
	performance = 0;
}

std::ofstream& operator << (std::ofstream& f_out, const CS& cs) {
	f_out << cs.get_ID() << std::endl << cs.name << std::endl << cs.count
		<< std::endl << cs.count_ready << std::endl
		<< cs.performance << std::endl;
	return f_out;
}

std::ifstream& operator >> (std::ifstream& f_in, CS& cs) {
	int x;
	f_in >> x >> std::ws;
	if (CS::MaxID <= x) {
		CS::MaxID = x;
	}
	cs.set_ID(x);
	getline(f_in, cs.name);
	f_in >> cs.count;
	f_in >> cs.count_ready;
	f_in >> cs.performance;
	f_in >> std::ws;
	return f_in;
}