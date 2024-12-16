/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostano <abostano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:52:47 by abostano          #+#    #+#             */
/*   Updated: 2024/12/16 15:25:35 by abostano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &wpn) : _name(name), _wpn(wpn)
{
	
}

HumanA::~HumanA(void)
{
	
}

void HumanA::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_wpn.getType() << std::endl;
}

void HumanA::setWeapon(Weapon wpn)
{
	this->_wpn = wpn;
}