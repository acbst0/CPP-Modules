/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostano <abostano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:52:53 by abostano          #+#    #+#             */
/*   Updated: 2024/12/16 15:19:47 by abostano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _wpn(NULL)
{
	this->_name = name;
}

HumanB::~HumanB(void)
{
	
}

void HumanB::attack(void)
{
	if (this->_wpn == NULL)
		std::cout << this->_name << " attacks with their hands" << std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_wpn->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &wpn)
{
	this->_wpn = &wpn;
}