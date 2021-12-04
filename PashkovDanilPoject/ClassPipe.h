#pragma once


#include <fstream>
#include <iostream>
#include <string>

/* #ifndef CLASSPIPE_H
#define CLASSPIPE_H */

class Pipe {
private:
	int id;
public:
	static int MaxID;
	int diametr;
	bool ready_unready;
	double length;

	void ready_unready_pipe(bool& repair);
	Pipe();
	int get_ID() const;
	void set_ID(int id);
	void switch_repair();
	explicit Pipe(std::ifstream& in);
	friend std::ostream& operator << (std::ostream& out, const Pipe& pipe);
	friend std::ofstream& operator << (std::ofstream& f_out, const Pipe& pipe);
	friend std::ifstream& operator >> (std::ifstream& f_in, Pipe& pipe);
	friend class PipeCollection;
};

//#endif // !CLASSPIPE_H