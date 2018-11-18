// Ex4_07.cpp
#include <iostream>                              // For standard streams
#include <cctype>                                 // For toupper()
#include <string>                                // For string class
#include <map>									 // For map container
#include <vector>									// Students
#include <iterator>
#include <memory>

#include "My_Templates.h"


using std::string;
using std::multimap;
using std::vector;
using Student = string;
using Subject = string;

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

class Key_compare
{
public:
	bool operator()(const string& p1, const string& p2) const
	{
		return p1 > p2;
	}
};

int main()
{
	multimap<Student, Subject, Key_compare> by_Student;

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
			std::cout << "Enter a student name and subject:\n";
			std::cin >> student >> subject;

			by_Student.emplace(student, subject);
			break;
		case 'D':// delete records
		{
			std::cout << "Enter a name: "; //	only find by subject name
			auto pr = find_elements(by_Student);
			auto count = std::distance(pr.first, pr.second);
			if (count == 1)
			{
				//if there's just the one ...
				by_Student.erase(pr.first);
			}
			else if (count > 1)
			{
				//There's more than one
				std::cout << "There are " << count << "records for " << pr.first->first << ".Delete all(Y or N)";
				std::cin >> choice;
				if (std::toupper(choice) == 'Y')
				{
					//Erase records from by_Subject container 
					by_Student.erase(pr.first, pr.second);
				}
			}
			break;
		}
		case 'F':
			std::cout << "Enter student name: ";
			list_range(find_elements(by_Student));
			break;

		case 'L':
			list_elements(by_Student);
			break;
		default:
			std::cout << "Invalid command - try again.\n";
		}
	}
	//system("pause");
}