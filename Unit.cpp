#include "Unit.hpp"

Unit::Unit() : Point(-1, -1), _display_char('o') {
}

Unit::~Unit() {
}

Unit::Unit(const Unit & f)
{
    *this = f;
}

Unit const & Unit::operator=(Unit const & e) {
    setX(e.getX());
    setY(e.getY());
    return *this;
}
