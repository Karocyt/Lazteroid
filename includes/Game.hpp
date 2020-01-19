#ifndef GAME_H
# define GAME_H
# include "Player.hpp"
# include "Enemy.hpp"
# include "locale.h"
# include <ncurses.h>
# include <unistd.h>
# include <cstdlib> // rand

class Game {

protected:
    Player _player;
    Enemy *_enemies;
    int _global_count;
    long _t;
    const long _t_start;
    long _t_last;
    
    void _initEnemies(int nb);

public:

    Game(int enemies_count = 200);
    ~Game();
    Game(Game const & g);
    Game const & operator=(Game const & g);

    int getEnemies(Enemy * *dst);
    
    void run(bool display_enabled = true); // will be his own namespace
    void input(Enemy *enemies, int enemies_count);
    void display(Enemy * enemies, int enemies_count);
};

#endif