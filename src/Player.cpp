#include "Player.hpp"

int Player::_x_init = 2;

Player::Player() : Unit(_x_init, Y_MAX / 2), _cooldown(0), _score(0) {
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

void Player::shoot(Unit *enemies, int count)
{
    int best_x = X_MAX;
    Unit * target = NULL;
    //if (getCooldown() <= 0)
    //{
        setCooldown(getBaseCooldown());
        for (int i = 0; i < count; i++)
        {
            if (enemies[i].getState() && enemies[i].getY() == getY() && enemies[i].getX() < best_x && enemies[i].getX() > getX())
                best_x = enemies[i].getX();
                target = &enemies[i];
        }
        if (!target)
            _laser = new Projectile(X_MAX - getX());
        else
            _laser = new Projectile(target->getX() - getX());
    //}
}