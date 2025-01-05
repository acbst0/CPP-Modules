/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostano <abostano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:37:30 by abostano          #+#    #+#             */
/*   Updated: 2025/01/05 17:51:46 by abostano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int	fp_nv;
		static const int _bits;//Bunda bir sıkıntı var
	public:
		Fixed();
		Fixed(const Fixed& other);
		~Fixed();
		Fixed& operator = (const Fixed &other);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif