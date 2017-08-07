// Ex4_07.cpp
#include <iostream>                              // For standard streams
#include <cctype>                                 // For toupper()
#include <string>                                // For string class
#include <unordered_map>                         // For unordered_map container
#include <vector>									// Students
#include <iterator>
#include <memory>

#include "Hash_Function_Objects.h"
#include "My_Templates.h"


using std::string;
using std::unordered_multimap;
using std::vector;
using Student = string;
using Subject = string;
using Students = vector<Student>;
using Subjects = vector<Subject>;

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
	unordered_multimap<Subject, Student, SubjectHash> by_Subject{ 8, SubjectHash() };

	char choice{};
	Student student{};
	Subject subject{};

	while (std::toupper(choice) != 'Q')
	{
		std::cout << "Enter a command: ";
		std::cin >> choice;
		switch (std::toupper(choice))
		{
		case 'A': // Add a record
			std::cout << "Enter a subject name and student:\n";
			std::cin >> subject >> student;

			by_Subject.emplace(subject, student);
			break;
		case 'D':// delete records
		{
			std::cout << "Enter a name: "; //	only find by subject name
			auto pr = find_elements(by_Subject);
			auto count = std::distance(pr.first, pr.second);
			if (count == 1)
			{
				//if there's just the one ...
				by_Subject.erase(pr.first);
			}
			else if (count > 1)
			{
				//There's more than one
				std::cout << "There are " << count << "records for " << pr.first->first << ".Delete all(Y or N)";
				std::cin >> choice;
				if (std::toupper(choice) == 'Y')
				{
					//Erase records from by_Subject container 
					by_Subject.erase(pr.first, pr.second);
				}
			}
			break;
		}
		case 'F':
			std::cout << "Enter subject name: ";
			list_range(find_elements(by_Subject));
			break;

		case 'L':
			list_elements(by_Subject);
			break;
		default:
			std::cout << "Invalid command - try again.\n";
		}		
		}
	//system("pause");
}