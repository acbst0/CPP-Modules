/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostano <abostano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:40:11 by abostano          #+#    #+#             */
/*   Updated: 2024/12/17 15:16:03 by abostano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	std::string	input;
	Harl		hrl;

	if (ac != 2)
	{
		std::cout << "Invalid count of arguements!" << std::endl;
		return 1;
	}
	input = std::string(av[1]);
	
	hrl.harlFilter(input);
}