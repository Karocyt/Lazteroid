#include "Enemy.hpp"

Enemy::Enemy() : Unit(-1, -1, ENEMY_SPEED) {
}

Enemy::~Enemy() {
}

Enemy::Enemy(const Enemy & f)
{
    *this = f;
}

Enemy const & Enemy::operator=(Enemy const & e) {
    Unit::operator=(e);
    return *this;
}

int Enemy::update(double t) {
    updatePos(t);
    if (getX() < 0)
        return ENEMY_CROSS_DAMAGE;
    return 0;
}