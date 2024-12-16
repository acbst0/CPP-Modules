/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostano <abostano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:53:01 by abostano          #+#    #+#             */
/*   Updated: 2024/12/16 13:39:45 by abostano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string str)
{
	this->setType(str);
}

void Weapon::setType(std::string newtype)
{
	this->_type = newtype;
}

const std::string &Weapon::getType() const
{
	return _type;	
}