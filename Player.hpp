#ifndef PLAYER_H
# define PLAYER_H
# include "Unit.hpp"
# include <iostream>

class Player: public Unit {

protected:
    unsigned _cooldown;
    unsigned _score;

protected:
    void setCooldown(unsigned c);
    void setScore(unsigned s);

public:

    Player();
    ~Player();
    Player(Player const & g);
    Player const & operator=(Player const & g);
    void run(unsigned enemies_count);
};

#endif