# include "Point.hpp"

static float areaTriangle(Point const a, Point const b, Point const c)
{
	float d;

	d = (a.getX() * (b.getY() - c.getY())) + (b.getX() * (c.getY() - a.getY())) + (c.getX() * (a.getY() - b.getY()));
	if (d < 0)
		d *= -1.0f;
	return (0.5f * d);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float threeArea = areaTriangle(a, b, point) + areaTriangle(b, c, point) + areaTriangle(c, a, point);
	float BigArea = areaTriangle(a, b, c);

	if (threeArea == BigArea)
		return true;
	return false;
}