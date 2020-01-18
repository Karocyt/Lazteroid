#ifndef UNIT_H
# define UNIT_H
# include "Point.hpp"
# include <iostream>

class Unit : public Point {

private:
    float _speed;
    int _hp;
    char _display_char;

protected:
    void setSpeed(float const y);
    void setHp(int const y);
    void setChar(char c);

public:

    Unit();
    ~Unit();
    Unit(Unit const & g);
    Unit const & operator=(Unit const & g);
    float getSpeed() const;
    int getHp() const; // floor to 0
    char getChar() const;
    void takeDamage(int d);
    void updatePos(int time);
    void shoot(Unit const & target);
    bool getState(); // check if _hp > 0;
};

#endif