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
        std::cout << "\n" + str;
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

std::string Validation::Get_name() {
		std::string name;
		while (true) {
			std::cout << "Enter name, which have length (1-50):";
			std::cin >> std::ws;
			getline(std::cin, name);
			if (size(name) <= 50) {
				return name;
				break;
			}
		};
};
	



