#ifndef PROJECTILE_H
# define PROJECTILE_H
# include "Unit.hpp"

class Projectile : public Unit {

private:
	int _len;
    Unit * _target;
    Unit & _owner;

protected:
    void setLen(int len);

    void setOwner(Unit & owner);

public:

    Projectile(int x, int y, int len, Unit * target, Unit & owner);
    virtual ~Projectile();
    Projectile(Projectile const & g);
    Projectile const & operator=(Projectile const & g);
    int getLen() const;
    Unit * getTarget();
    void setTarget(Unit * target);
    void deleteThis();
    Unit & getOwner() const;
    int update(double t);
};

#endif