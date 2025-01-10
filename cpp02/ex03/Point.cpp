#include "Point.hpp"

Point::Point() : _x(Fixed(0.0f)), _y(Fixed(0.0f))
{
	
}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y))
{

}

Point::Point(const Point& ref) : _x(ref._x), _y(ref._y)
{
	
}

Point& Point::operator=(const Point& ref)
{
	if (this == &ref)
		return *this;
	return *this;
}

Point::~Point()
{
	
}

float Point::getX() const
{
	return (this->_x.toFloat());
}

float Point::getY() const
{
	return (this->_y.toFloat());
}
