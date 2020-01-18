#include "Unit.hpp"

Unit::Unit(int x, int y, unsigned speed) :
    Point(x, y),
    _speed(speed),
    _hp(150),
    _display_char('o'),
    _dir_x(0),
    _dir_y(0),
    _base_cooldown(1000),
    _damage(75),
    _cooldown(_base_cooldown)
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
    setCooldown(e.getCooldown());
    setSpeed(e.getSpeed());
    setChar(e.getChar());
    setHp(e.getHp());
    setDamage(e.getDamage());
    setBaseCooldown(e.getBaseCooldown());
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


void Unit::takeDamage(int d)
{
    setHp(getHp() - d);
}


void Unit::updatePos(double seconds)                         // to change if t is not milliseconds
{
    std::cerr << "Moving to " << (int)(getX() + _dir_x * getSpeed() * seconds)
    << " " << (int)(getY() + _dir_y * getSpeed() * seconds) << std::endl;

    setX(getX() + _dir_x * getSpeed() * seconds);
    setY(getY() + _dir_y * getSpeed() * seconds);                                   // check if moving in the right direction
}


bool Unit::getState()
{
    if (getHp() > 0)
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

void Unit::setCooldown(int c)
{
    _cooldown = c;
}

int Unit::getCooldown() const
{
    return _cooldown;
}

void Unit::setBaseCooldown(int c)
{
    _base_cooldown = c;
}

unsigned Unit::getBaseCooldown() const
{
    return _base_cooldown;
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

int Unit::getDirY() const
{
    return _dir_y;
}
