// PashkovDanilPoject.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "PashkovDanilPoject.h"
#include <iostream>
#include <unordered_map>
#include "ClassCS.h"
#include "ClassPipe.h"
#include "ClassMenu.h"
#include "ClassIntilization.h"
#include "AllPipes.h"

using namespace std;

int main() {
	PipeCollection new_PipeCollection;
	std::unordered_map<int, CS> CSs;
	std::unordered_map<int, Pipe> pipes = new_PipeCollection.pipeCollection;
	int menu_navigator;
	Menu :: menu_display();
	while (true){
		std::cin >> std::ws;
		Validation:: input_range(menu_navigator, 9, 0);
		switch (menu_navigator){
		case 1:{
			new_PipeCollection.AddPipe();		
			break;
		}
		case 2: {
			CS new_CS;
			CSs.insert({ new_CS.get_ID(), new_CS });
			break;
		}
		case 3: 
			new_PipeCollection.PrintPipe();
			/*if (pipes.empty() && CSs.empty()) {
				cout << "Your Pipe and CS data are empty. Try again after adding info." << endl;
				break;
			}
			if (!pipes.empty()) {
				cout << "Pipe info:" << endl;
				for (auto item : pipes) {
					cout << item.second;
				}

			}
			if (!CSs.empty()) {
				cout << "CS info:" << endl;
				for (auto item : CSs) {
					cout << item.second;
				}
			}*/
			break;
		case 4:
			new_PipeCollection.ChangePipe();
			break;
		case 5:
			break;
		case 6:
			new_PipeCollection.BatchChangePipe();
			break;
		case 7:
			new_PipeCollection.DeletePipe();
			break;
		case 8:{
			if (CSs.empty() && pipes.empty()) {
				cout << "You push wrong point in menu because you don't have pipe or CS\n\n";
				break;
			}
			string file_name;
			cout << "Enter the file name:";
			cin.ignore(10000, '\n');
			getline(cin, file_name);
			Menu :: Out_to_File(pipes, CSs, file_name);
			break;
		}	  
		case 9: {
			string file_name;
			cout << "Enter the file name:";
			cin.ignore(10000, '\n');
			getline(cin, file_name);
			Menu::In_from_file(pipes, CSs, file_name);
			break;
		}
		case 0:
			system("cls");
			return 0;
			break;
		default:
			break;
		};
	};
};