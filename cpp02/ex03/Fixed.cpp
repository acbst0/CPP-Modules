#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed()
{
	this->_value = 0;
}

Fixed::Fixed(const int i)
{
	this->_value = i << this->_bits;
}

Fixed::Fixed(const float f)
{
	this->_value = roundf(f * (1 << this->_bits));
}

Fixed::Fixed(const Fixed& ref)
{
	*this = ref;
}

Fixed::~Fixed()
{

}

float Fixed::toFloat(void) const
{
	return ((float) this->_value / (1 << this->_bits));
}

int	Fixed::toInt(void) const
{
	return (this->_value >> this->_bits);
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (&other != this)
		this->_value = other._value;
	return (*this);
}

bool Fixed::operator==(const Fixed& ref)
{
	if (this->_value == ref._value)
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed& ref)
{
	if (this->_value != ref._value)
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed& ref)
{
	if (this->_value <= ref._value)
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed& ref)
{
	if (this->_value >= ref._value)
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed& ref)
{
	if (this->_value < ref._value)
		return (true);
	return (false);
}

bool Fixed::operator>(const Fixed& ref)
{
	if (this->_value > ref._value)
		return (true);
	return (false);
}

float Fixed::operator+(const Fixed& ref)
{
	return (this->toFloat() + ref.toFloat());
}

float Fixed::operator-(const Fixed& ref)
{
	return (this->toFloat() - ref.toFloat());
}

float Fixed::operator*(const Fixed& ref)
{
	return (this->toFloat() * ref.toFloat());
}

float Fixed::operator/(const Fixed& ref)
{
	return (this->toFloat() * ref.toFloat());
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	++this->_value;
	return (tmp);
}

Fixed Fixed::operator++()
{
	this->_value++;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	--this->_value;
	return (tmp);
}

Fixed Fixed::operator--()
{
	this->_value--;
	return (*this);
}

const Fixed& Fixed::min(const Fixed& first, const Fixed& second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}

Fixed& Fixed::min(Fixed& first, Fixed& second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}

const Fixed& Fixed::max(const Fixed& first, const Fixed& second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
}

Fixed& Fixed::max(Fixed& first, Fixed& second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
}

std::ostream& operator << (std::ostream &out, Fixed const &value)
{
	out << value.toFloat();
	return (out);
}
