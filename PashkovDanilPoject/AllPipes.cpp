#include "AllPipes.h"
#include "ClassIntilization.h"
#include <iomanip>

void PipeCollection::AddPipe()
{
	Pipe new_pipe;
	pipeCollection.emplace(new_pipe.id, new_pipe);
}

void PipeCollection::ChangePipe()
{
	size_t changeId;
	bool query;
	std::cout << "All added Pipes: " << pipeCollection.size() << std::endl
		<< "Editable ID: ";
	for (const auto& el : pipeCollection)
		std::cout << el.first << "  ";
	std::cout << std::endl;
	if (pipeCollection.empty())
	{
		std::cout << "You have not added any pipes, editing is not available!" << std::endl;
		return;

	}
	while (true)
	{
		changeId = Validation::input_range(pipe_id,Pipe::MaxID,1 );
		if (pipeCollection.find(changeId) != pipeCollection.end())
		{
			std::cout << "Initial state of the pipe: "
				<< (pipeCollection[changeId].ready_unready ? "in reapir" : "not in repair");
			std::cin.ignore(10000, '\n');
			pipeCollection[changeId].switch_repair();		
		}
		else
			std::cout << "No pipes found for the specified id." << std::endl;
		query = Validation::is_boolean_value("\n\nContinue editing pipe? (y / n)\n");
		if (query != true)
			break;
	}
}

void PipeCollection::PrintPipe()
{
	if (pipeCollection.empty())
	{
		std :: cout << "\nYou have no pipes\n";
	}
	else
	{
		std :: cout << "\nPipe info:";
		for (auto item : pipeCollection)
		{
			std ::cout << item.second;
		}
	}
}

void PipeCollection::FilterPipe()
{
	bool query;
	query = Validation::is_boolean_value("Enter the condition of the filter pipe: y - under repair, n - not under repair");
	for (const auto& el : pipeCollection)
		if (el.second.ready_unready == query)
			vectorIdForFilter.push_back(el.first);
}

void PipeCollection::PrintFilterPipe()
{
	std :: cout << "\nFiltered pipes info : ";
	for (const auto& id : vectorIdForFilter)
	{
		std :: cout << pipeCollection[id];
	}
}

void PipeCollection::DeletePipe()
{
	if (pipeCollection.empty())
	{
		std :: cout << "You have not added any pipes, deletion is not available!";
		return;
	}
	bool query;
	query = Validation::is_boolean_value("\nEnter 'y' if you want to remove one pipe at a time, and 'n' if you want to remove batch by filter:\n");
	if (query)  // Удаление по одной трубе
	{
		std::cout << "\n\nTotal Pipes : " << pipeCollection.size() << std::endl
			<< "Id's available for deletion: ";
		for (const auto& el : pipeCollection)
			std::cout << el.first << "  ";
		std::set<size_t> setIdForDelete = Validation::GetMultipleNumericValues<size_t>(
			"\nEnter the id of the pipes that you would like to delete, separated by a space: ",
			"\nError, you entered an invalid format, please try again!");
		for (const auto id : setIdForDelete)
		{
			if (pipeCollection.find(id) != pipeCollection.end())
			{
				pipeCollection.erase(id);
				std :: cout << "Pipe with id = " + std::to_string(id) + "was deleted!\n";
			}
			else
				std :: cout << "Pipe with id = " + std::to_string(id) + " was not found in the list of all pipes!\n";
		}
	}
	else // Пакетное удаление
	{
		FilterPipe();
		if (!vectorIdForFilter.empty())
		{
			std::cout << "\n\nFiltered pipes : " << std::endl;
			PrintFilterPipe();
			query = Validation::is_boolean_value("\n Enter 'y' if you want to remove all filtered pipes and 'n' if some of them : \n");
			if (query) // Удалить все отфильтрованные трубы
			{
				for (const auto& i : vectorIdForFilter)
					pipeCollection.erase(i);
				std :: cout << "\nThe pipes have been removed successfully!";
			}
			else // Удалить часть отфильтрованных труб
			{
				std::set<size_t> setIdForDelete = Validation::GetMultipleNumericValues<size_t>(
					"\nEnter the id of the pipes that you would like to delete, separated by a space : ",
					"\nError, you entered an invalid format, please try again!");
				for (auto id : setIdForDelete)
				{
					auto it = std::find(vectorIdForFilter.begin(), vectorIdForFilter.end(), id);
					if (it != vectorIdForFilter.end())
					{
						pipeCollection.erase(id);
						std :: cout << "Pipe with id = " + std::to_string(id) + " was deleted!\n";
					}
					else
						std :: cout << "Pipe with id = " + std::to_string(id) + " was not found in the filtered pipes list!\n";
				}
			}
			vectorIdForFilter.clear();
		}
		else
			std :: cout << "\nNo pipes were found for your filter!";
	}
	std::cout << std::endl;
	system("pause");
}

void PipeCollection::BatchChangePipe()
{
	if (pipeCollection.empty())
	{
		std :: cout << "\nYou haven't added any pipes, batch editing is not available!";
		return;
	}
	bool query;
	bool repairStatus;
	std::cin >> std::ws;
	query = Validation ::is_boolean_value("\nEnter 'y' if you want to edit all pipes, and 'n' if only a specific subset:\n");
	if (!query) // Пакетное редактирование
	{
		FilterPipe();
		if (!vectorIdForFilter.empty())
		{
			PrintFilterPipe();
			query = Validation::is_boolean_value("\nEnter 'y' if you want to edit all filtered pipes, and 'n' if you want to edit only a part:\n");
			
			if (!query) // Редактировать все отфильтрованные трубы
			{
				std::set<size_t> setIdForChange = Validation::GetMultipleNumericValues<size_t>(
					"\nEnter the id of the pipes that you would like to edit, separated by a space: ",
					"\nError, you entered an invalid format, please try again!");
				std::cin.ignore(10000, '\n');
				repairStatus = Validation::is_boolean_value("\n\nIndicate the new state for the selected pipes, if under repair, then enter 'y', if not under repair, then 'n'. ");
				for (const auto id : setIdForChange)
				{
					auto it = std::find(vectorIdForFilter.begin(), vectorIdForFilter.end(), id);
					if (it != vectorIdForFilter.end())
					{
						pipeCollection[id].ready_unready = repairStatus;
						std:: cout << "Pipe with id = " + std::to_string(id) + " has been edited!\n";
					}
					else
						std:: cout << "Pipe with id = " + std::to_string(id) + " was not found in the filtered pipes list\n";
				}
			}
			else // Отредактировать часть отфильтрованных труб
			{
				std::cin >> std::ws;
				repairStatus = Validation::is_boolean_value("\n\nIndicate the new state for the selected pipes, if under repair, then enter 'y', if not under repair, then 'n': ");
				for (const auto& i : vectorIdForFilter)
					pipeCollection[i].ready_unready = repairStatus;
				std :: cout << "\nPipes edited!";
			}
		}
		else
			std:: cout << "\nNo pipes were found for your filter!";
		vectorIdForFilter.clear();
	}
	else // Редактирование всех труб
	{
		PrintPipe();
		repairStatus = Validation::is_boolean_value("\n\nIndicate the new state for the selected pipes, if under repair, then enter 'y', if not under repair, then 'n'. ");
		for (auto& el : pipeCollection)
			el.second.ready_unready = repairStatus;
		std:: cout << "\nPipes edited.";
	}
	system("pause");
}