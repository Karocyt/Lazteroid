#ifndef POINT_H
# define POINT_H
# include <iostream>

class Point {

private:
    float _y;
    float _x;

protected:
    void setX(float const x);
    void setY(float const y);


public:

    Point(int x = -1, int y = -1);
    Point(unsigned enemies_count);
    ~Point();
    Point(Point const & g);
    Point const & operator=(Point const & g);
    int getX() const;
    int getY() const;
    void moveTo(Point const & p);
};

#endif