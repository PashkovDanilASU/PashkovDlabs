#pragma once
#include <iostream>
#include <string>
#include <set>

/*#ifndef CLASSINTILIZATION_H
#define CLASSCINTILIZATION_H*/

namespace Validation {
	bool is_input_valid();
	bool is_boolean_value(std :: string str);
	template <typename T>
	T input_range(T& number, T max, T min);
    template <typename T>
    std::set<T> GetMultipleNumericValues(std::string textRequest, std::string textError);

}

template <typename T>
T Validation::input_range(T& number, T max, T min) {
	do
		std:: cin >> number;
	while (!(Validation::is_input_valid() && (number <= max && number >= min)));
	return number;
}

template <typename T>
std::set<T> Validation::GetMultipleNumericValues(std::string textRequest, std::string textError)
{
    std::set<T> resultSet;
    T value;
    bool flag = true;
    while (flag)
    {
        flag = false;
        std::cout << textRequest;
        while (true)
        {
            std::cin >> value;
            if (std::cin.good())
                resultSet.insert(value);
            else
            {
                std::cout << textError;
                resultSet.clear();
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                flag = true;
                break;
            }
            if (std::cin.peek() == '\n')
                break;
        }
    }
    return resultSet;
}

//#endif CLASSINTILIZATION_H