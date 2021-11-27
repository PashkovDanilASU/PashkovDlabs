#include "ClassMenu.h"
#include <iostream>

void menu_display() {
	std :: cout << "1. Add pipe\n"
		"2. Add CS\n"
		"3. View all objects\n"
		"4. Edit pipe\n"
		"5. Edit CS\n"
		"6. Save\n"
		"7. Load\n"
		"0. Exit\n";
};

void back_to_menu() {
	system("cls");
	menu_display();
}