#ifndef ENEMY_H
# define ENEMY_H
# include "Unit.hpp"

class Enemy : public Unit {

private:
protected:
    
public:

    Enemy();
    ~Enemy();
    Enemy(Enemy const & g);
    Enemy const & operator=(Enemy const & g);
};

#endif