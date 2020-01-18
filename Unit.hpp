#ifndef UNIT_H
# define UNIT_H
# include "Point.hpp"
# include <iostream>

class Unit : public Point {

private:
    float _speed;
    int _hp;

protected:
    void setSpeed(float const y);
    void setHp(int const y);

public:
    char const display_char;

    Unit();
    Unit(unsigned enemies_count);
    ~Unit();
    Unit(Unit const & g);
    Unit const & operator=(Unit const & g);
    float getSpeed() const;
    int getHp() const; // floor to 0
    void takeDamage(int d);
    void updatePos(int time);
    void shoot(Unit const & target);
    bool getState(); // check if _hp > 0;
};

#endif