#include "Unit.hpp"

Unit::Unit(int x, int y) : Point(x, y), _display_char('o') {
}

Unit::~Unit() {
}

Unit::Unit(const Unit & f)
{
    *this = f;
}

Unit const & Unit::operator=(Unit const & e) {
    Point::operator=(e);
    setSpeed(e.getSpeed());
    setChar(e.getChar());
    setHp(e.getHp());
    return *this;
}


float Unit::getSpeed() const
{
    return _speed;
}


int Unit::getHp() const
{
    if (_hp >= 0)
        return _hp;
    return 0;
}


char Unit::getChar() const
{
    return _display_char;
}


void Unit::setSpeed(float const y)
{
    _speed = y;
}


void Unit::setHp(int const y)
{
    _hp = y;
}


void Unit::setChar(char c)
{
    _display_char = c;
}


void Unit::takeDamage(int d)
{
    setHp(getHp() - d);
}


void Unit::updatePos(int t)
{
    (void)t;                                        // update pos using elapsed time (t) and speed
}


void Unit::shoot(Unit const & target)
{
    (void)target;                                   // shoot
}


bool Unit::getState()
{
    if (getHp() > 0)
        return true;
    return false;                                    
}
