/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostano <abostano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:28:00 by abostano          #+#    #+#             */
/*   Updated: 2024/12/17 12:28:01 by abostano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <string>
#include <sstream>
#include <cstdlib>

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

// bool PhoneBook::isNumber(std::string str)
// {
// 	for (int i = 0; str.c_str[i]; i++)
// 	{
// 		if (!std::isdigit(str.c_str[i]))
// 		return (false);
// 	}
// 	return (true);
// }

int	PhoneBook::add(PhoneBook *pb)
{
	std::string	firstname;
	std::string	lastname;
	std::string	nickname;
	std::string	phonenum;
	std::string	darkness;
	// bool flag = 1;


	std::cout << "First name of new contact :" << std::endl;
	std::getline(std::cin, firstname);
	std::cout << "Last name of new contact :" << std::endl;
	std::getline(std::cin, lastname);
	std::cout << "Nickname of new contact :" << std::endl;
	std::getline(std::cin, nickname);
	// while (flag == 1)
	// {
	// 	std::cout << "Phone Number of new contact :" << std::endl;
	// 	std::getline(std::cin, phonenum);
	// 	if (pb->isNumber(phonenum) == false)
	// 		std::cout << "There is a problem about Phone Number" << std::endl;
	// 	else
	// 		flag = 0;
	// }
	std::cout << "Phone Number of new contact :" << std::endl;
	std::getline(std::cin, phonenum);
	std::cout << "Dark secret of new contact :" << std::endl;
	std::getline(std::cin, darkness);

	Contact newcnt(firstname, lastname, nickname, phonenum, darkness);
	pb->cnt[pb->_input_times % MAX_CONT] = newcnt;
	pb->_input_times++;
	return (0);
}

void	PhoneBook::search(PhoneBook *pb)
{
	std::string input;
	int i;

	pb->printPB();
	std::cout << "Chose one of them for details :" << std::endl;
	if (!(std::getline(std::cin, input)))
		return ;
	i = atoi(input.c_str());
	if (i <=1 || i >=8 || !(_input_times <= MAX_CONT && i <= _input_times))
	{
		std::cout << "Invalid ID !" << std::endl;
		return ;
	}
	std::cout << "First Name : " << pb->cnt[i - 1].getFirstName() << std::endl;
	std::cout << "Last Name : " << pb->cnt[i - 1].getLastName() << std::endl;
	std::cout << "Nick Name : " << pb->cnt[i - 1].getNickName() << std::endl;
	std::cout << "Phonenumber : " << pb->cnt[i - 1].getPhoneNum() << std::endl;
	std::cout << "Dark Secret : " << pb->cnt[i - 1].getDarkness() << std::endl;
}

std::string to_string(int value)
{
	std::stringstream ss;
	ss << value;
	return ss.str();
}

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

void	PhoneBook::printCT(Contact *ct, int i)
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
	printline(to_string((i % MAX_CONT) + 1));
	printline(firstname);
	printline(lastname);
	printline(nickname);
	printline(phonenum);
	std::cout << std::endl;
	std::cout << "|----------|----------|----------|----------|----------|" << std::endl;
}

void	PhoneBook::printPB()
{
	std::cout << std::endl;
	std::cout << "|----------|----------|----------|----------|----------|" << std::endl;
	std::cout << "|        ID|First Name| Last Name| Nick Name|    Number|" << std::endl;
	std::cout << "|----------|----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < 8 && this->cnt[i].getEmpty(); i++)
		printCT(&this->cnt[i], i);
}
