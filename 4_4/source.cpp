// Ex4_07.cpp


#include "Hash_Function_Objects.h"
#include "My_Templates.h"
#include "Person.h"


// Display command prompt
void show_operations()
{
	std::cout << "Operations:\n"
		<< "A: Add a subject.\n"
		<< "D: Delete subjects.\n"
		<< "F: Find subjects.\n"
		<< "L: List all subjects.\n"
		<< "Q: Quit the program.\n\n";
}


int main()
{
	unordered_multimap<Name, Person, SubjectHash> by_Name{ 8, SubjectHash() };

	char choice{};
	Person person;

	while (std::toupper(choice) != 'Q')
	{
		std::cout << "Enter a command: ";
		std::cin >> choice;
		switch (std::toupper(choice))
		{
		case 'A': // Add a record
			std::cout << "Enter a person name ,address and phone:\n";
			std::cin >> person;

			by_Name.emplace(person.name, person);
			break;
		case 'D':// delete records
		{
			std::cout << "Enter a name: "; //	only find by subject name
			auto pr = find_elements(by_Name);
			auto count = std::distance(pr.first, pr.second);
			if (count == 1)
			{
				//if there's just the one ...
				by_Name.erase(pr.first);
			}
			else if (count > 1)
			{
				//There's more than one
				std::cout << "There are " << count << "records for " << pr.first->first << ".Delete all(Y or N)";
				std::cin >> choice;
				if (std::toupper(choice) == 'Y')
				{
					//Erase records from by_Name container 
					by_Name.erase(pr.first, pr.second);
				}
			}
			break;
		}
		case 'F':
			std::cout << "Enter subject name: ";
			list_range(find_elements(by_Name));
			break;

		case 'L':
			list_elements(by_Name);
			break;
		default:
			std::cout << "Invalid command - try again.\n";
		}
	}
	//system("pause");
}