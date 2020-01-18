#ifndef ENEMY_H
# define ENEMY_H
# include "Unit.hpp"
# include <iostream>

class Enemy : public Unit {

private:
protected:
    
public:

    Enemy();
    ~Enemy();
    Enemy(Enemy const & g);
    Enemy const & operator=(Enemy const & g);
    void run(unsigned enemies_count);
};

#endif