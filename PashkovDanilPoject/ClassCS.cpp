#include "ClassCS.h"
#include "ClassMenu.h"
#include "ClassIntilization.h"

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
		cout << "Enter CS name, which have length (1-50):";
		cin >> std::ws;
		getline(cin, name);
		if (size(name) <= 50) {
			break;
		}
	};
	cout << "Enter workshops count (1-15): ";
	Validation::input_range(count, 15, 1);
	cout << "Enter workshops which ready to work, in range (0 to n), where n your CS. ";
	Validation::input_range(count_ready, count, 0);
	cout << "Enter the performance of CS, in range(0 to 100%): ";
	Validation::input_range(performance, 100, 0);
	Menu::back_to_menu();
};

std::ostream& operator << (std::ostream& out, const CS& cs) {
	out << endl << "CS id: " << cs.get_ID() << endl << "CS name: " << cs.name << endl
		<< "CS count workshops: " << cs.count
		<< endl << "CS count ready workshops: " << cs.count_ready
		<< endl << "CS performance: " << cs.performance << endl;
	return out;
}
