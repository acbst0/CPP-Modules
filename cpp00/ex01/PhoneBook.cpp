#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	_input_times = 0;
}

PhoneBook::~PhoneBook()
{
	
}

void	PhoneBook::add(PhoneBook *pb)
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

	Contact newcnt(firstname, lastname, nickname, phonenum, darkness);
	pb->cnt[pb->_input_times % MAX_CONT] = newcnt;
	pb->_input_times++;
}

void	PhoneBook::search(PhoneBook *pb)
{
	*pb = *pb;
}