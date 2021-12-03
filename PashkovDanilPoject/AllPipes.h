#pragma once
#include <unordered_map>
#include <vector>
#include <fstream>
#include "ClassPipe.h"

class PipeCollection
{
private:
	int pipe_id;
	std::vector<size_t> vectorIdForFilter;
	void PrintFilterPipe();
	void FilterPipe();
public:
	std::unordered_map<int, Pipe> pipeCollection;
	void AddPipe();
	void ChangePipe();
	void PrintPipe();
	//void PrintTablePipes();
	//void SaveToFile(std::ofstream&);
	//void DownloadFromFile(std::ifstream&);
	void DeletePipe();
	void BatchChangePipe();
};
