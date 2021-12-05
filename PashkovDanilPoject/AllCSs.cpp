#include "AllCSs.h"
#include "ClassIntilization.h"
#include "ClassMenu.h"
#include <iomanip>



void CSCollection::AddCS()
{
	CS new_CS;
	csCollection.emplace(new_CS.id, new_CS);

}

void CSCollection::PrintCS()
{
	if (csCollection.empty())
	{
		std :: cout << "\nYou haven't CSs\n\n";
	}
	else
	{
		std :: cout << "\nCS info:"<<std::endl;
		for (auto item : csCollection)
		{
			std :: cout << item.second;
		}
	}
}

void CSCollection::ChangeCS()
{
	size_t changeId;
	bool query;
	system("cls");
	std::cout << "Total CSs added: " << csCollection.size() << std::endl
		<< "Editable ID: ";
	for (const auto& el : csCollection)
		std::cout << el.first << "  ";
	std::cout << std::endl;
	if (csCollection.empty())
	{
		std::cout << "You have not added any CSs, editing is not available!" << std::endl;
		system("pause");
		Menu::back_to_menu();
		return;
	}
	while (true)
	{
		std::cout << "Id of CSs: ";
		changeId = Validation::input_range(CS_id, CS::MaxID, 1);
		if (csCollection.find(changeId) != csCollection.end())
		{
			std::cout << "Number of workshops at the CS: " << csCollection[changeId].count << std::endl;
			std::cout << "The number of workshops in operation at this CS : " << csCollection[changeId].count_ready << std::endl;
			csCollection[changeId].Change_count_workshops();
		}
		query = Validation::is_boolean_value("\n\nContinue editing CSs ? (y / n)\n");
		if (query != true) {
			system("pause");
			Menu::back_to_menu();
			break;
		}
	}
}

void CSCollection::PrintFilterCS()
{
	std::cout << "\nFiltered CSs info : ";
	for (const auto& id : vectorIdForFilter)
	{
		std::cout << csCollection[id];
	}
}

void CSCollection::FilterCS()
{
	system("cls");
	std::cout << "\n\nSelect a menu item for filtering:" << std::endl
		<< "1. Filter by name" << std::endl
		<< "2. Filter by percentage of unused workshops" << std::endl
		<< "3. Apply both filters" << std::endl;
	while (true)
	{
		std::cout << "\nEnter the command : ";
		switch (Validation::input_range(menu_navigator_1,3,1))
		{
		case 1:
		{
			std::string nameCS;
			nameCS = Validation::Get_name();
			for (const auto& el : csCollection)
				if (el.second.name == nameCS)
					vectorIdForFilter.push_back(el.first);
			return;
		}
		case 2:
		{
			size_t lowPercent, upPercent, percent;
			std::cout << "Enter the lower limit of the filter for the percentage of unused workshops at the CS (an integer from 0 to 99) ";
			lowPercent = Validation::input_range(low_percent, 99, 0);
			std::cout << "Enter the upper limit of the filter for the percentage of unused workshops at the CS (an integer from the lower limit to 100) ";
			upPercent = Validation::input_range(up_percent, 100, low_percent);
			for (const auto& el : csCollection)
			{
				percent = static_cast<size_t>(round((static_cast<double>(el.second.count) - el.second.count_ready) / el.second.count * 100));
				if (percent >= lowPercent && percent <= upPercent)
					vectorIdForFilter.push_back(el.first);
			}
			return;
		}
		case 3:
		{
			std::string nameCS;
			size_t lowPercent, upPercent, percent;
			nameCS = Validation::Get_name();
			std::cout <<"Enter the lower limit of the filter for the percentage of unused workshops at the CS(an integer from 0 to 100) ";
			lowPercent = Validation::input_range(low_percent, 99, 0);
			std::cout << "Enter the upper limit of the filter for the percentage of unused workshops at the CS(an integer from the lower limit to 100) ";
			upPercent = Validation::input_range(up_percent, 100, low_percent);
			for (const auto& el : csCollection)
			{
				percent = static_cast<size_t>(round((static_cast<double>(el.second.count) - el.second.count_ready) / el.second.count * 100));
				if (el.second.name == nameCS && percent >= lowPercent && percent <= upPercent)
					vectorIdForFilter.push_back(el.first);
			}
			return;
		}
		default:
		{
			std::cout << "\nThere is no such command in the list above, re - enter\n";
			break;
		}
		}
	}
}

void CSCollection::DeleteCS()
{
	if (csCollection.empty())
	{
		std::cout << "\nYou have not added any CS, deletion is not available!\n";
		return;
	}
	system("cls");
	bool query;
	query = Validation::is_boolean_value("\nEnter 'y' if you want to delete one CS at a time, and 'n' if you want to delete batch by filter:\n");
	if (query)
	{
		std::cout << "\n\nTotal CSs: " << csCollection.size() << std::endl
			<< "Id's available for deletion: ";
		for (const auto& el : csCollection)
			std::cout << el.first << "  ";
		std::set<size_t> setIdForDelete = Validation::GetMultipleNumericValues<size_t>(
			"\nEnter the id of the CS, which you would like to delete, separated by a space: ",
			"\nError, you entered an invalid format, please try again.");
		for (const auto id : setIdForDelete)
		{
			if (csCollection.find(id) != csCollection.end())
			{
				csCollection.erase(id);
				std::cout << "Compressor station with id = " + std::to_string(id) + " was deleted.\n";
			}
			else
				std::cout << "Compressor station with id = " + std::to_string(id) + " was not found in the list of all CSs.\n";
		}
	}
	else
	{
		FilterCS();
		if (!vectorIdForFilter.empty())
		{
			std::cout << "\n\nCS obtained after filtration : " << std::endl;
			PrintFilterCS();
			query = Validation::is_boolean_value("\nEnter 'y' if you want to remove all filtered CS, and 'n' if you want to remove some of them:\n");
			if (query)
			{
				for (const auto i : vectorIdForFilter)
					csCollection.erase(i);
				std::cout << "\n\nCS successfully removed!";
			}
			else
			{
				std::set<size_t> setIdForDelete = Validation::GetMultipleNumericValues<size_t>(
					"\nEnter the id of the CS, which you would like to delete, separated by a space: ",
					"\nError, you entered an invalid format, please try again.");
				for (auto id : setIdForDelete)
				{
					auto it = std::find(vectorIdForFilter.begin(), vectorIdForFilter.end(), id);
					if (it != vectorIdForFilter.end())
					{
						csCollection.erase(id);
						std::cout << "Compressor station with id = " + std::to_string(id) + " was deleted.\n";
					}
					else
						std::cout << "Compressor station with id = " + std::to_string(id) + " was not found in the list of all CSs.\n";
				}
			}
			vectorIdForFilter.clear();
		}
		else
			std::cout << "\nNo CS were found for your filter!";
	}
	std::cout << std::endl;
	system("pause");
	Menu::back_to_menu();
}

void CSCollection::BatchChangeCS()
{
	if (csCollection.empty())
	{
		std::cout << "\nYou have not added any CS, batch editing is not available!\n";
		return;
	}
	system("cls");
	bool query;
	query = Validation::is_boolean_value("\nEnter 'y' if you want to edit all CSs, and 'n' if only a specific subset:\n");
	if (!query) // Редактирование части КС
	{
		FilterCS();
		if (!vectorIdForFilter.empty())
		{
			PrintFilterCS();
			query = Validation::is_boolean_value("\nEnter 'y' if you want to edit all filtered CSs, and 'n' if you want to edit only a part : \n");
			if (query) // Редактирование всех отфильтрованных КС
			{
				for (const auto& i : vectorIdForFilter)
				{
					std::cout << "\n\nCompressor station under id " << csCollection[i].id << " has a total number of workshops: " << csCollection[i].count << std::endl
						<< "Number of workshops in operation: " << csCollection[i].count_ready << std::endl;
					std::cout << "Enter the new number of workshops in operation for this CS (it should not exceed the total number of workshops): ";
					csCollection[i].count_ready = Validation::input_range(new_count_ready, csCollection[i].count, 0);
					std::cout << "Compressor station under id = " + std::to_string(i) + " has been edited.\n";
				}
				std::cout << "has been edited.";
			}
			else // Редактирование КС по id среди отфильтрованных
			{
				std::set<size_t> setIdForChange = Validation::GetMultipleNumericValues<size_t>(
					"\nEnter the id of the CS, which you would like to edit, separated by a space: ",
					"\nError, you entered an invalid format, please try again.");
				for (const auto id : setIdForChange)
				{
					auto it = std::find(vectorIdForFilter.begin(), vectorIdForFilter.end(), id);
					if (it != vectorIdForFilter.end())
					{
						std::cout << "\n\nCompressor station under id " << csCollection[id].id << " has a total number of workshops: " << csCollection[id].count << std::endl
							<< "Number of workshops in operation: " << csCollection[id].count_ready << std::endl;
						std::cout << "Enter the new number of workshops in operation for this CS (it should not exceed the total number of workshops): ";
						csCollection[id].count_ready = Validation::input_range(new_count_ready, csCollection[id].count,0);
						std::cout << "\nCompressor station under id " + std::to_string(id) + " has been edited.\n";
					}
					else
						std::cout << "\nCompressor station under id " + std::to_string(id) + " was not found in the list of filtered CSs.\n";
				}
			}
			vectorIdForFilter.clear();
		}
		else
			std::cout << "\nNo stations were found according to your filter.\n";
	}
	else // Редактирование всех КС
	{
		PrintCS();
		for (auto& el : csCollection)
		{
			std::cout << "\n\nCompressor station under id " << el.first << " has a total number of workshops: " << el.second.count << std::endl
				<< "Number of workshops in operation: " << el.second.count_ready << std::endl;
			std::cout << "Enter the new number of workshops in operation for this CS (it should not exceed the total number of workshops): ";
			el.second.count_ready= Validation::input_range(new_count_ready, el.second.count, 0);
		}
		std::cout << "\nCSs edited!";
	}
	vectorIdForFilter.clear();
	system("pause");
	Menu::back_to_menu();
}
