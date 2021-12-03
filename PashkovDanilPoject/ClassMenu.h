#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "ClassPipe.h"
#include "ClassCS.h"

/*#ifndef CLASSMENU_H
#define CLASSMENU_H */


namespace Menu{
    void menu_display();
	void back_to_menu();
	void Out_to_File(std::unordered_map<int, Pipe>& pipes, std::unordered_map<int, CS>& CSs, std::string& File_name);
	void In_from_file(std::unordered_map<int, Pipe>& pipes, std::unordered_map<int, CS>& CSs, std::string& File_name);
};

//#endif // !CLASSMENU_H