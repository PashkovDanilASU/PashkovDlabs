#pragma once
#include <iostream>
#include <fstream>
#include <string>

/* #ifndef CLASSCS_H
#define CLASSCS_H*/

class CS{
private:
	int id;
public:
	static int MaxID;
	int count, count_ready, performance;
    std :: string name;

	int change_count_workshps;

	CS();
	int get_ID() const;
	void set_ID(int id);
	void Change_count_workshops();
	std :: string Get_name(); 
	explicit CS(std::ifstream& in);
	friend std :: ostream& operator << (std::ostream& out, const CS& cs);
	friend std::ofstream& operator << (std::ofstream& f_out, const CS& cs);
	friend std::ifstream& operator >> (std::ifstream& f_in, CS& cs);
	friend class CSCollection;
	
};

//#endif // !CLASS_CS_H