/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostano <abostano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:55:47 by abostano          #+#    #+#             */
/*   Updated: 2025/01/05 17:50:15 by abostano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& ref)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
	
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (other != *this)
	{
		
	}
}

float Fixed::toFloat( void ) const
{
	
}

int	Fixed::toInt( void ) const
{
	
}