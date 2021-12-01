#include "ClassIntilization.h"

bool Validation::is_input_valid() {
	if (!std::cin || std::cin.peek() != '\n')
	{
		std::cout << "You entered an invalid number, enter a new number: ";
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		return false;
	}
	return true;
}
	


