#pragma once
#include <iostream>


using std::cin;
using std::cout;


namespace Validation {
	bool is_input_valid();
	template <typename T>
	T input_range(T& number, T max, T min);
}

template <typename T>
T Validation::input_range(T& number, T max, T min) {
	do
		cin >> number;
	while (!(Validation::is_input_valid() && (number <= max && number >= min)));
	return number;
}


	