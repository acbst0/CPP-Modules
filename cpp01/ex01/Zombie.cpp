/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostano <abostano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:23:07 by abostano          #+#    #+#             */
/*   Updated: 2024/12/09 12:48:43 by abostano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
    this->_name = "NULL";
}

Zombie::~Zombie(void)
{
    std::cout << "Zombie object " << this->_name << " destroyed" << std::endl;
}

void    Zombie::setname(std::string name)
{
    this->_name = name;
    std::cout << "Zombie object " << this->_name << " created" << std::endl;
}

void    Zombie::announce( void )
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
