#include "ClassCS.h"
#include "ClassMenu.h"
#include "ClassIntilization.h"

int CSS::get_ID() {
	return  id;
}

void CSS::set_ID(int value) {
	id = value;
}

void CSS::input_CS()
{
	system("cls");
	while (true) {
		cout << "Enter CS name, which have length (1-50):";
		cin >> std::ws;
		getline(cin, name);
		if (size(name) <= 50) {
			break;
		}
	};
	cout << "Enter CS count (1-15): ";
	Validation::input_range(count, 15, 1);
	cout << "Enter CS which ready to work, in range (0 to n), where n your CS. ";
	Validation::input_range(count_ready, count, 0);
	cout << "Enter the performance of CS, in range(0 to 100%): ";
	Validation::input_range(performance, 100, 0);
	Menu::back_to_menu();
};
