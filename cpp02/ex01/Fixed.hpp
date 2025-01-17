/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostano <abostano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:46:58 by abostano          #+#    #+#             */
/*   Updated: 2025/01/05 17:10:30 by abostano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int _value;
		static const int _bits;
	public:
		Fixed();
		Fixed(const int i);
		Fixed(const float f);
		Fixed(const Fixed& ref);
		~Fixed();
		Fixed& operator = (const Fixed &other);
		float toFloat( void ) const;
		int	toInt( void ) const;
};

std::ostream& operator << (std::ostream &out, Fixed const &value);

#endif