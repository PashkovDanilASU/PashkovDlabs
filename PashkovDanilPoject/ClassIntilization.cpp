#include "ClassIntilization.h"

bool Validation::is_input_valid() {
	if (!cin || cin.peek() != '\n')
	{
		cout << "You entered an invalid number, enter a new number: ";
		cin.clear();
		cin.ignore(10000, '\n');
		return false;
	}
	return true;
}
	


