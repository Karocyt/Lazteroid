#include "Player.hpp"

int Player::_x = 1;

Player::Player() : Unit(Player::_x, 1) {
}

Player::~Player() {
}

Player::Player(const Player & f)
{
    *this = f;
}

Player const & Player::operator=(Player const & e) {
    Unit::operator=(e);
    setCooldown(e.getCooldown());
    setScore(e.getScore());
    return *this;
}

unsigned Player::getCooldown() const
{
    return _cooldown;
}


unsigned Player::getScore() const
{
    return _score;
}


void Player::setScore(unsigned s)
{
    _score = s;
}


void Player::setCooldown(unsigned c)
{
    _cooldown = c;
}
