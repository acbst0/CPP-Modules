/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostano <abostano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:27:06 by abostano          #+#    #+#             */
/*   Updated: 2024/12/17 13:50:19 by abostano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl hrl;
	std::string input;

	std::cout << LIGHT_BLUE << "This is Harl" << std::endl;
	std::cout << "Harl compleins all the time like a karen :D" << std::endl;
	std::cout << "If you want the see taht in differnt levels use one of them :" << std::endl;
	std::cout << "DEBUG, INFO, WARNING, ERROR" << DEFAULT << std::endl;

	std::cout << "->";
	getline(std::cin, input);
	std::string inputs[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (input == inputs[i])
			break;
		else if (i == 3)
		{
			std::cout << "Sorry! You did not use one of the correct commands" << std::endl;
			return 1;
		}
	}
	hrl.complain(input);
	return 0;
}