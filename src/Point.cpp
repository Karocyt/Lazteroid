#include "Point.hpp"

Point::Point(int x, int y) : _x(x), _y(y) {
}

Point::~Point() {
}

Point::Point(const Point & f)
{
    *this = f;
}

Point const & Point::operator=(Point const & e) {
    setX(e.getX());
    setY(e.getY());
    return *this;
}


int Point::getX() const
{
    return _x;
}


int Point::getY() const
{
    return _y;
}


void Point::setX(float const x)
{
    _x = x;
}


void Point::setY(float const y)
{
    _y = y;
}


void Point::moveTo(Point const & p)
{
    (void)p;                                    // move, proto can change
}
