#include "ClassMenu.h"

void Menu :: menu_display() {
	std :: cout << "1. Add pipe\n"
		"2. Add CS\n"
		"3. View all objects\n"
		"4. Edit pipe\n"
		"5. Packet redackt pipes \n"
		"6. Delete pipe\n"
		"7. Edit CS \n"
        "8. Packet redackt CSs \n"
        "9. Delite CS \n"
		"10. Save\n"
		"11. Load\n"
		"0. Exit\n";
};

void Menu :: back_to_menu() {
	system("cls");
	menu_display();
}

void Menu::Out_to_File(std::unordered_map<int, Pipe>& pipes, std::unordered_map<int, CS>& compressors, std::string& File_name) {
	std::ofstream out;
	out.open("/Users/prope/Documents/GitHub/PashkovDlabs/PashkovDlabs/PashkovDanilPoject/Debug" + File_name);
	if (!out.is_open()) {
        std:: cout << "File don't find\n ";
	}
	if (!pipes.empty()) {
		out << "Pipe" << std :: endl << pipes.size() << std::endl;
		for (const auto& item : pipes) {
			out << item.second;
		}
	}
	if (!compressors.empty()) {
		out << "CS" << std::endl << compressors.size() << std::endl;
		for (const auto& item : compressors) {
			out << item.second;
		}
	}
    std::cout << "Data is upload to file" << std::endl;
	out.close();
}

void Menu::In_from_file(std::unordered_map<int, Pipe>& pipes, std::unordered_map<int, CS>& compressors, std::string& File_name) {
    std::ifstream in("/Users/prope/Documents/GitHub/PashkovDlabs/PashkovDlabs/PashkovDanilPoject/Debug" + File_name);
    if (!in.is_open()) {
        std:: cout << "File don't find" << std::endl;
        return;
    }
    else if (in.eof()) {
        std:: cout << "File is empty" << std::endl;
        return;
    }
    std::string check;
    in >> check;
    if (check == "Pipe") {
        pipes.clear();
        int count_pipe;
        in >> count_pipe;
        for (int i = 0; i < count_pipe; ++i) {
            Pipe new_pipe(in);
            in >> new_pipe;
            pipes.insert({ new_pipe.get_ID(), new_pipe });
        }
        if (!in.eof()) {
            in >> check;
        }
    }
    if (check == "CS") {
        compressors.clear();
        int count_cs;
        in >> count_cs;
        for (int i = 0; i < count_cs; ++i) {
            CS new_CS(in);
            in >> new_CS;
            compressors.insert({ new_CS.get_ID(), new_CS });
        }
    }
    std:: cout << "You download data from file" << std::endl;
    in.close();
}

