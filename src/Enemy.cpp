#include "Enemy.hpp"

Enemy::Enemy() : Unit(-1, -1, ENEMY_SPEED, ENEMY_LIFE) {
    static int current_speed = ENEMY_SPEED;
    setSpeed(current_speed);
    current_speed += 0.5;
    setDirX(-1);
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
    int old_x = getX();
    if ((int)getX() != -1)
    {
        // std::cerr << "X in Enemy: " << getX() << std::endl;
        updatePos(t);
    }
    else
        // std::cerr << " DEAD" << std::endl;
    if (getState() && getX() < 0 && getX() < old_x)
    {
        takeDamage(ENEMY_LIFE);
        return ENEMY_CROSS_DAMAGE;
    }
    return 0;
}