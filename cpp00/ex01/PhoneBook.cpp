#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	_input_times = 0;
	for (int i = 0; i < MAX_CONT; i++)
	{
		cnt[i].makeEmpty();
	}
}

PhoneBook::~PhoneBook()
{
	
}

int	PhoneBook::add(PhoneBook *pb)
{
	std::string	firstname;
	std::string	lastname;
	std::string	nickname;
	std::string	phonenum;
	std::string	darkness;


	std::cout << "First name of new contact :" << std::endl;
	std::getline(std::cin, firstname);
	if (firstname.compare("EXIT") == 0)
		return (1);
	std::cout << "Last name of new contact :" << std::endl;
	std::getline(std::cin, lastname);
	if (lastname.compare("EXIT") == 0)
		return (1);
	std::cout << "Nickname of new contact :" << std::endl;
	std::getline(std::cin, nickname);
	if (nickname.compare("EXIT") == 0)
		return (1);
	std::cout << "Phone Number of new contact :" << std::endl;
	std::getline(std::cin, phonenum);
	if (phonenum.compare("EXIT") == 0)
		return (1);
	std::cout << "Dark secret of new contact :" << std::endl;
	std::getline(std::cin, darkness);
	if (darkness.compare("EXIT") == 0)
		return (1);

	Contact newcnt(firstname, lastname, nickname, phonenum, darkness);
	pb->cnt[pb->_input_times % MAX_CONT] = newcnt;
	pb->_input_times++;
	return (0);
}

void	PhoneBook::search(PhoneBook *pb)
{
	*pb = *pb;
}