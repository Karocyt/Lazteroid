#ifndef PLAYER_H
# define PLAYER_H
# include "Unit.hpp"

# include "Projectile.hpp"

class Player: public Unit {

protected:
    int _score;
    static int _x_init;
    Projectile *_laser;

protected:
    void setScore(unsigned s);
    virtual void setX(float const x);

    void setCooldown(int c);

public:

    Player();
    ~Player();
    Player(Player const & g);
    Player const & operator=(Player const & g);
    unsigned getScore() const;
    void shoot(Unit *enemies, int count);
    Projectile * getLaser();
    virtual void setLaser(Projectile * laser);
    void resetLaser();
    int getCooldown();
    void update(double t);
};

#endif