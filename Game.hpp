#ifndef GAME_H
# define GAME_H
# include "Player.hpp"
# include <iostream>

class Game {

private:
    Player _player;
    Enemy *_enemies;
    unsigned _enemies_count;

public:

    Game(unsigned enemies_count);
    ~Game();
    Game(Game const & g);
    Game const & operator=(Game const & g);
    void run(unsigned enemies_count);
};

#endif