#ifndef PROJECTILE_H
# define PROJECTILE_H
# include "Unit.hpp"

class Projectile : public Unit {

private:
	int _len;

protected:
    void setLen(int len);

public:

    Projectile();
    ~Projectile();
    Projectile(Projectile const & g);
    Projectile const & operator=(Projectile const & g);
    int getLen() const;
};

#endif