#include "Unit.hpp"

Unit::Unit(int x, int y, unsigned speed, int start_hp) :
    Point(x, y),
    _speed(speed),
    _hp(start_hp),
    _display_char('o'),
    _dir_x(0),
    _dir_y(0)
{

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
    setDamage(e.getDamage());
    _dir_x = 0;
    _dir_y = 0;
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

void Unit::setDamage(int const y)
{
    _damage = y;
}


int Unit::getDamage() const
{
    return _damage;
}


int Unit::takeDamage(int d)
{
    int old_hp = getHp();
    setHp(getHp() - d);
    return old_hp - getHp();
}


void Unit::updatePos(double seconds)
{
    setX(getX() + _dir_x * getSpeed() * seconds);
    setY(getY() + _dir_y * getSpeed() * seconds);
    // std::cerr << seconds << " Moving to " << getX() << " " << getY() << std::endl;
}


bool Unit::getState() {
    if (getX() <= -2)
        return false;

    if (getHp() > 0 || getX() == -1)
        return true;
    return false;                                    
}

void Unit::moveTo(Point const & target) {
    int x = target.getX();
    int y = target.getY();

    moveTo(x, y);
}

void Unit::moveTo(int x_target, int y_target) {
    int x = x_target - getX();
    int y = y_target - getY();

    if (x > 0)
        _dir_x = 1;
    else if (x < 0)
        _dir_x = -1;
    else
        _dir_x = 0;
    if (y > 0)
        _dir_y = 1;
    else if (y < 0)
        _dir_y = -1;
    else
        _dir_y = 0;
}

void Unit::setDirX(int x)
{
    _dir_x = x;
}

int Unit::getDirX() const
{
    return _dir_x;
}

void Unit::setDirY(int x)
{
    _dir_y = x;
}


void Unit::setY(const float x)
{
    Point::setY(max(min(x, Y_MAX - 1), 0));
}

int Unit::getDirY() const
{
    return _dir_y;
}

void Unit::resetLaser() {

}