#ifndef UNIT_H
# define UNIT_H
# include "Point.hpp"

class Unit : public Point {

private:
    float _speed;                   // speed is in map_unit/second
    int _hp;
    char _display_char;
    int _dir_x;
    int _dir_y;
    int _base_cooldown;
    int _damage;
    int _cooldown;

protected:
    void setSpeed(float const y);
    void setHp(int const y);
    void setChar(char c);
    void setBaseCooldown(int c);
    void setCooldown(int c);
    void setDamage(int d);

public:

    Unit(int x = -1, int y = -1, unsigned speed = 1.0);
    ~Unit();
    Unit(Unit const & g);
    Unit const & operator=(Unit const & g);
    bool getState();
    float getSpeed() const;
    int getHp() const;
    int getDamage() const;
    int getCooldown() const;
    unsigned getBaseCooldown() const;
    char getChar() const;
    void moveTo(Point const & p);
    void moveTo(int x, int y);
    void takeDamage(int d);
    void updatePos(int time);
    void shoot(Unit *enemies, int count);
};

#endif