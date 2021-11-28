#pragma once

#include <iostream>
#include "ClassIntilization.h"
#include "ClassMenu.h"

class Pipe {
private:
	int id;

public:
	static int MaxID;
	int diametr;
	bool ready_unready;
	double length;

	void ready_unready_pipe(bool& repair);
	void input_Pipe();
	int get_ID();
	void set_ID(int id);
};
