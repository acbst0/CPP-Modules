/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostano <abostano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:46:58 by abostano          #+#    #+#             */
/*   Updated: 2024/12/26 15:54:03 by abostano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		
	public:
		Fixed();
		Fixed(int i);
		Fixed(float f);
		~Fixed();
		Fixed& operator = (const Fixed &other);
		float toFloat( void ) const;
		int	toInt( void ) const;
};

#endif