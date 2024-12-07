#include "PhoneBook.hpp"

int main()
{
	PhoneBook pb;
	std::string	input;

	pb.printPB();
	std::cout << std::endl;
	input = "NULL";
	std::cout << "Hello! Welcome to The PhoneBook" << std::endl;
	while (1)
	{
		std::cout << "Plz use one of commands (ADD, SEARCH, EXIT) :" << std::endl;
		if (!(std::getline(std::cin, input)))
			return (1);
		if (input.compare("ADD") == 0)
		{
			if (pb.add(&pb) == 1)
				break ;
		}
		else if (input.compare("SEARCH") == 0)
			pb.search(&pb);
		else if (input.compare("EXIT") == 0)
			break ;
		else
			std::cout << "Invalid input" << std::endl;
	}
	return (1);
}