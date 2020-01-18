#ifndef PLAYER_H
# define PLAYER_H
# include "Unit.hpp"

class Player: public Unit {

protected:
    unsigned _cooldown;
    unsigned _score;
    static int _x_init;

protected:
    void setScore(unsigned s);
    virtual void setX(float const x);
    //virtual void setY(float const y);

public:

    Player();
    ~Player();
    Player(Player const & g);
    Player const & operator=(Player const & g);
    unsigned getScore() const;
};

#endif