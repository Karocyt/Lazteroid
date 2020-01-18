#include "Projectile.hpp"

Projectile::Projectile() : Unit() {
}

Projectile::~Projectile() {
}

Projectile::Projectile(const Projectile & f)
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