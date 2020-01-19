#include "Projectile.hpp"

Projectile::Projectile(int x, int y, int len, Unit * target, Unit & owner) :
    Unit(x + 1, y),
    _len(len),
    _target(target),
    _owner(owner) {
    setSpeed(PROJECTILE_SPEED);
}

Projectile::~Projectile() {
}

Projectile::Projectile(const Projectile & f) : _owner(f.getOwner())
{
    *this = f;
}

Projectile const & Projectile::operator=(Projectile const & e) {
    Unit::operator=(e);
    setLen(e.getLen());
    return *this;
}

int Projectile::getLen() const {
	return _len;
}

void Projectile::setLen(int len) {
	_len = len;
}

Unit * Projectile::getTarget() {
    return _target;
}

void Projectile::setTarget(Unit * target) {
    _target = target;
}

void Projectile::setOwner(Unit & player) {
    _owner = player;
}

Unit & Projectile::getOwner() const {
    return _owner;
}

void Projectile::deleteThis() {
    _owner.resetLaser();
    delete this;
}

void Projectile::update(double t) {
    updatePos(t);
    if (!getTarget())
    {
        moveTo(X_MAX, getY());
        if (getX() > X_MAX - 1)
            deleteThis();
        return;
    }

    moveTo(getTarget()->getX(), getTarget()->getY());

    if (getX() >= getTarget()->getX())
    {
        getTarget()->takeDamage(DAMAGE);
        deleteThis();
    }
}