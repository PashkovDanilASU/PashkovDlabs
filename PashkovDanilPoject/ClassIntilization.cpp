#include "ClassIntilization.h"


bool is_input_valid() {
	if (!cin || cin.peek() != '\n')
	{
		cout << "You entered an invalid number, enter a new number: ";
		cin.clear();
		cin.ignore(10000, '\n');
		return false;
	}
	return true;

};

template <typename T>
void input_range(T& number, T max, T min) {
	do
		cin >> number;
	while (!(is_input_valid() && (number <= max && number >= min)));
}