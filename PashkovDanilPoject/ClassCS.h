#pragma once
#include <string>
#include <iostream>
#include<string>

class CS{
private:
	int id;
public:
	static int MaxID;
	int count, count_ready, performance;
    std :: string name;
	CS();

	int get_ID() const;
	void set_ID(int id);
	friend std::ostream& operator << (std::ostream& out, const CS& cs);
};