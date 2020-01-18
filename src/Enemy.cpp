#include "Enemy.hpp"

Enemy::Enemy() : Unit(-1, -1, 5) {
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