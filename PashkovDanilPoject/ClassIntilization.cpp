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

bool Validation::is_boolean_value(std :: string str)
{
   std:: string response;
    while (true)
    {
        std::cout << "\n" + str + " y or n: ";
        getline(std :: cin >> std::ws, response);
        if (response == "y")
        {
            return true;
        }
        else if (response == "n")
        {
            return false;
        }
    }
	return false;
}
	



