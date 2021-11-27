#pragma once

#include <iostream>
#include "ClassIntilization.h"
#include "ClassMenu.h"

class Pipe {
private:
	int id = 0;

public:
	int diametr;
	bool ready_unready;
	double length;

	void ready_unready_pipe(bool& repair);
	void input_Pipe();
};
