#ifndef PLAYER_H
# define PLAYER_H
# include "Unit.hpp"
# include "Projectile.hpp"

class Player: public Unit {

protected:
    unsigned _cooldown;
    unsigned _score;
    static int _x_init;
    Projectile *_laser;

protected:
    void setScore(unsigned s);
    virtual void setX(float const x);
    virtual void setLaser(Projectile * laser);

public:

    Player();
    ~Player();
    Player(Player const & g);
    Player const & operator=(Player const & g);
    unsigned getScore() const;
    void shoot(Unit *enemies, int count);
    Projectile * getLaser() const;
};

#endif