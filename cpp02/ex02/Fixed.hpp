#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath> 

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
		Fixed& operator=(const Fixed& ref);
		bool operator==(const Fixed& ref);
		bool operator!=(const Fixed& ref);
		bool operator<=(const Fixed& ref);
		bool operator>=(const Fixed& ref);
		bool operator<(const Fixed& ref);
		bool operator>(const Fixed& ref);
		float operator+(const Fixed& ref);
		float operator-(const Fixed& ref);
		float operator*(const Fixed& ref);
		float operator/(const Fixed& ref);
		Fixed operator++(int);
		Fixed operator++();
		Fixed operator--(int);
		Fixed operator--();
		static const Fixed& min(const Fixed& first, const Fixed& second);
		static Fixed& min(Fixed& first, Fixed& second);
		static const Fixed& max(const Fixed& first, const Fixed& second);
		static Fixed& max(Fixed& first, Fixed& second);
		float toFloat( void ) const;
		int	toInt( void ) const;
};

std::ostream& operator << (std::ostream &out, Fixed const &value);

#endif