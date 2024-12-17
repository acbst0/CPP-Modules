/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostano <abostano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:40:17 by abostano          #+#    #+#             */
/*   Updated: 2024/12/17 15:28:43 by abostano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << LIGHT_BLUE << "Harl came to the burger shop" << DEFAULT << std::endl;
}

Harl::~Harl()
{
	std::cout << LIGHT_BLUE << "Harl came out of the burger shop" << DEFAULT << std::endl;
}

void	Harl::debug(void)
{
	std::cout << MAGENTA << "[ DEBUG ]" << DEFAULT << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << GRAY << "[ INFO ]" << DEFAULT << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << YELLOW << "[ WARNING ]" << DEFAULT << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << RED << "[ ERROR ]" << DEFAULT << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::harlFilter(std::string input)
{
	void (Harl::*ptr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string inputs[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i = 0;
	
	for(; i < 4; i++)
		if (input == inputs[i])
			break;
	switch (i)
	{
	case (0):
		(this->*ptr[0])();
		__attribute__ ((fallthrough));
	case (1):
		(this->*ptr[1])();
		__attribute__ ((fallthrough));
	case (2):
		(this->*ptr[2])();
		__attribute__ ((fallthrough));
	case (3):
		(this->*ptr[3])();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}