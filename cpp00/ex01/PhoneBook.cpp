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
	Contact newcnt;

	pb->cnt[pb->_input_times % MAX_CONT] = newcnt;
	pb->_input_times++;
}

void	PhoneBook::search(PhoneBook *pb)
{
	*pb = *pb;
}