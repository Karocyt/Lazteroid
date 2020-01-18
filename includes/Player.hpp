#ifndef PLAYER_H
# define PLAYER_H
# include "Unit.hpp"

class Player: public Unit {

protected:
    unsigned _cooldown;
    unsigned _score;
    static int _x;

protected:
    void setCooldown(unsigned c);
    void setScore(unsigned s);

public:

    Player();
    ~Player();
    Player(Player const & g);
    Player const & operator=(Player const & g);
    unsigned getCooldown() const;
    unsigned getScore() const;
};

#endif