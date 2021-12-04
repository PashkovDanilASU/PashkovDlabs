#pragma once

#include <unordered_map>
#include <vector>
#include <fstream>
#include "ClassCS.h"


class CSCollection
{
private:
	std::vector<size_t> vectorIdForFilter;
	void PrintFilterCS();
	void FilterCS();
public:
	int CS_id, change_count_workshps, menu_navigator_1,low_percent,up_percent,new_count_ready;
	std::unordered_map<int, CS> csCollection;
	void AddCS();
	void ChangeCS();
	void PrintCS();
	void DeleteCS();
	void BatchChangeCS();
};