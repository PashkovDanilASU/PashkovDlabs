#pragma once


#include <fstream>
#include <iostream>
#include <string>

class Pipe {
private:
	int id;

public:
	static int MaxID;
	int diametr;
	bool ready_unready;
	double length;
	std :: string name;

	void ready_unready_pipe(bool& repair);
	Pipe();
	int get_ID() const;
	void set_ID(int id);
	explicit Pipe(std::ifstream& in);
	friend std::ostream& operator << (std::ostream& out, const Pipe& pipe);
	friend std::ofstream& operator << (std::ofstream& f_out, const Pipe& pipe);
	friend std::ifstream& operator >> (std::ifstream& f_in, Pipe& pipe);
};
