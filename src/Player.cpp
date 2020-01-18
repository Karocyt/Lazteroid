#include "Player.hpp"

int Player::_x_init = 1;

Player::Player() : Unit(_x_init, 1), _score(0) {
}

Player::~Player() {
}

Player::Player(const Player & f)
{
    *this = f;
}

Player const & Player::operator=(Player const & e) {
    Unit::operator=(e);
    setScore(e.getScore());
    return *this;
}


unsigned Player::getScore() const
{
    return _score;
}


void Player::setScore(unsigned s)
{
    _score = s;
}

void Player::setX(float x) {
    (void)x; // Player x cannot change
}

Projectile * Player::getLaser() const {
	return _laser;
}


void Player::setLaser(Projectile * laser) {
	_laser = laser;
}