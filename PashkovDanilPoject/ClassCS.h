#pragma once
#include <iostream>
#include <fstream>
#include <string>


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
	explicit CS(std::ifstream& in);
	friend std :: ostream& operator << (std::ostream& out, const CS& cs);
	friend std::ofstream& operator << (std::ofstream& f_out, const CS& cs);
	friend std::ifstream& operator >> (std::ifstream& f_in, CS& cs);
	
};