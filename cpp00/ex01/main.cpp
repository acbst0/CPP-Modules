#include "PhoneBook.hpp"
#include <iostream>

/*void add()
{
	std::string	firstname;
	std::string	lastname;
	std::string	nickname;
	std::string	phonenum;
	std::string	darkness;

	std::cout << "First name of new contact :" << std::endl;
	std::getline(std::cin, firstname);
	std::cout << "Last name of new contact :" << std::endl;
	std::getline(std::cin, lastname);
	std::cout << "Nickname of new contact :" << std::endl;
	std::getline(std::cin, nickname);
	std::cout << "Phone Number of new contact :" << std::endl;
	std::getline(std::cin, phonenum);
	std::cout << "Dark secret of new contact :" << std::endl;
	std::getline(std::cin, darkness);
	//Contact::Contact(firstname, lastname, nickname, phonenum, darkness);
}*/
int main()
{
	PhoneBook pb;
	std::string	input;

	input = "NULL";
	while (1)
	{
		std::cout << "INPUT :" << std::endl;
		if (!(std::getline(std::cin, input)))
			return (1);
		if (input.compare("ADD") == 0)
			pb.add(&pb);
		else if (input.compare("SEARCH") == 0)
			pb.search(&pb);
		else if (input.compare("EXIT") == 0)
			break ;
	}
	return (1);
}