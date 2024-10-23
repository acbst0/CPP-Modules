#include "PhoneBook.hpp"
#include <iostream>

void	printline(std::string str)
{
	if (str.length() > 10)
	{
		std::cout << std::setw(10) << str.substr(0, 9) << ".";
	}
	else
	{
		std::cout << std::setw(10) << str;
	}
	std::cout << "|";
}

void	printCT(Contact *ct)
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
	printline(firstname);
	printline(lastname);
	printline(nickname);
	printline(phonenum);
	std::cout << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
}

void	printPB(PhoneBook *pb)
{
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "|    Number|First Name| Last Name| Nick Name|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	if (pb == NULL)
		return ;
	else
	{
		for (int i = 0; (i < 8 && (pb->cnt + i) != NULL); i++)
		{
			printCT(pb->cnt + i);
		}
	}
}

int main()
{
	PhoneBook pb;
	std::string	input;

	printPB(NULL);
	input = "NULL";
	while (1)
	{
		std::cout << "INPUT :" << std::endl;
		if (!(std::getline(std::cin, input)))
			return (1);
		if (input.compare("ADD") == 0)
			pb.add(&pb);
		else if (input.compare("SEARCH") == 0)
			printPB(&pb);
		else if (input.compare("EXIT") == 0)
			break ;
	}
	return (1);
}