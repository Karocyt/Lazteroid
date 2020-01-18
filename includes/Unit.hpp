#ifndef UNIT_H
# define UNIT_H
# include "Point.hpp"

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

    Unit(int x = -1, int y = -1);
    ~Unit();
    Unit(Unit const & g);
    Unit const & operator=(Unit const & g);
    bool getState();
    float getSpeed() const;
    int getHp() const;
    char getChar() const;
    void takeDamage(int d);
    void updatePos(int time);
    void shoot(Unit const & target);
};

#endif