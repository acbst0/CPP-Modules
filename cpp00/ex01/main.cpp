/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostano <abostano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:27:57 by abostano          #+#    #+#             */
/*   Updated: 2024/12/18 18:01:23 by abostano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook pb;
	std::string	input;

	std::cout << std::endl;
	input = "NULL";
	std::cout << YELLOW << "	-----------------------------------	" << DEFAULT << std::endl;
	std::cout << YELLOW << "	- Hello! Welcome to The PhoneBook -" << DEFAULT << std::endl;
	std::cout << YELLOW << "	-----------------------------------" << DEFAULT << std::endl;
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
		{
			if (pb.search(&pb) == 1)
				break;
		}
		else if (input.compare("EXIT") == 0)
			break ;
		else
			std::cout << RED << "Invalid input!" << DEFAULT << std::endl;
	}
	return (0);
}