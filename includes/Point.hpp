#ifndef POINT_H
# define POINT_H
# include <iostream>

class Point {

private:
    float _x;
    float _y;

protected:
    virtual void setX(float const x);
    virtual void setY(float const y);


public:

    Point(int x = -1, int y = -1);
    Point(unsigned enemies_count);
    ~Point();
    Point(Point const & g);
    Point const & operator=(Point const & g);
    float getX() const;
    float getY() const;
    void moveTo(Point const & p);
};

#endif