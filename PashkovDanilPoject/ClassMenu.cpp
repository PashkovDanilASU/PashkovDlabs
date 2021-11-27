#include "ClassMenu.h"

void Menu :: menu_display() {
	std :: cout << "1. Add pipe\n"
		"2. Add CS\n"
		"3. View all objects\n"
		"4. Edit pipes\n"
		"5. Edit CSs\n"
		"6. Save\n"
		"7. Load\n"
		"8. Search pipes\n"
		"9. Search pipes\n"
		"0. Exit\n";
};

void Menu :: back_to_menu() {
	system("cls");
	menu_display();
}