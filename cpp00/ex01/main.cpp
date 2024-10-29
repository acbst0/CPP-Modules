#include "PhoneBook.hpp"
#include <iostream>

void	printline(std::string str)
{
	if (str.length() > 10)
	{
		std::cout << str.substr(0, 9) << ".";
	}
	else
	{
		std::cout << std::setw(10) << str;
	}
	std::cout << "|";
}

void	printCT(Contact *ct, int i)
{
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string phonenum;

	firstname = ct->getFirstName();
	lastname = ct->getLastName();
	nickname = ct->getNickName();
	phonenum = ct->getPhoneNum();

	std::cout << "|";
	printline(std::to_string((i % MAX_CONT) + 1));
	printline(firstname);
	printline(lastname);
	printline(nickname);
	printline(phonenum);
	std::cout << std::endl;
	std::cout << "|----------|----------|----------|----------|----------|" << std::endl;
}

void	printPB(PhoneBook *pb)
{
	std::cout << std::endl;
	std::cout << "|----------|----------|----------|----------|----------|" << std::endl;
	std::cout << "|        ID|First Name| Last Name| Nick Name|    Number|" << std::endl;
	std::cout << "|----------|----------|----------|----------|----------|" << std::endl;
	if (pb == NULL)
		return ;
	else
	{
		for (int i = 0; i < 8 && pb->cnt[i].getEmpty(); i++)
		{
			printCT(&pb->cnt[i], i);
		}
	}
}

int main()
{
	PhoneBook pb;
	std::string	input;

	printPB(NULL);
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
			printPB(&pb);
		else if (input.compare("EXIT") == 0)
			break ;
		else
			std::cout << "Invalid input" << std::endl;
	}
	return (1);
}