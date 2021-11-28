#pragma once
#include <string>
#include <iostream>
#include<string>

class CSS{
private:
	int id;
public:
	static int MaxID;
	int count, count_ready, performance;
    std :: string name;
	void input_CS();

	int get_ID();
	void set_ID(int id);
};