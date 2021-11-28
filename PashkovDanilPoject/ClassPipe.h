#pragma once

#include <iostream>
#include "ClassIntilization.h"
#include "ClassMenu.h"
#include "string"
#include <fstream>





class Pipe {
private:
	int id;

public:
	static int MaxID;
	int diametr;
	bool ready_unready;
	double length;
	std::string name;

	void ready_unready_pipe(bool& repair);
	Pipe();
	int get_ID() const;
	void set_ID(int id);
	friend std::ostream& operator << (std::ostream& out, const Pipe& pipe);
};
