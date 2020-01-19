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
    int _damage;

protected:
    void setHp(int const y);
    void setChar(char c);
    void setDamage(int d);

public:

    Unit(int x = -1, int y = -1, unsigned speed = 1.0, int start_hp = 300);
    ~Unit();
    Unit(Unit const & g);
    Unit const & operator=(Unit const & g);
    bool getState();
    float getSpeed() const;
    int getHp() const;
    int getDamage() const;
    char getChar() const;
    void moveTo(Point const & p);
    void moveTo(int x, int y);
    int takeDamage(int d);
    void updatePos(double time);
    int getDirX() const;
    void setDirX(int dir);
    int getDirY() const;
    void setDirY(int dir);
    void setY(const float dir);
    void setSpeed(float const y);

    virtual void resetLaser();
};

#endif