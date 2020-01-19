#include "Player.hpp"

int Player::_x_init = PLAYER_OFFSET;

Player::Player() : Unit(_x_init, Y_MAX / 2, 0, PLAYER_LIFE), _score(0), _laser(NULL) {
}

Player::~Player() {
    delete getLaser();
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

Projectile * Player::getLaser() {
	return _laser;
}


void Player::setLaser(Projectile * laser) {
	_laser = laser;
}

void Player::shoot(Unit *enemies, int count)
{
    int best_x = X_MAX;
    Unit * target = NULL;
    for (int i = 0; i < count; i++)
    {
        if (enemies[i].getState() && enemies[i].getY() == getY() && enemies[i].getX() < best_x && enemies[i].getX() > getX())
        {
            best_x = enemies[i].getX();
            target = &enemies[i];
        }
    }
    if (!target)
        _laser = new Projectile(getX(), getY(), X_MAX - getX(), NULL, *this);
    else
        _laser = new Projectile(getX(), getY(), target->getX() - getX(), target, *this);
}

void Player::resetLaser() {
    _laser = NULL;
}

int Player::getCooldown() {
    return max(_cooldown, 0);
}

void Player::setCooldown(int c) {
    _cooldown = c;
}


void Player::update(double t) {
    updatePos(t);
    if (getLaser())
        setScore(getScore() + getLaser()->update(t));
}