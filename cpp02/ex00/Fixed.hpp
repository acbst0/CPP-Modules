/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostano <abostano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:37:30 by abostano          #+#    #+#             */
/*   Updated: 2025/01/13 13:49:25 by abostano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int	fp_nv;
		static const int _bits;
	public:
		Fixed();
		Fixed(const Fixed& other);
		~Fixed();
		Fixed& operator = (const Fixed &other);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif