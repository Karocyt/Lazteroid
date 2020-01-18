#ifndef GAME_H
# define GAME_H
# include "Player.hpp"
# include "Enemy.hpp"
# include <time.h> // sleep

class Game {

private:

protected:
    Player _player;
    Enemy *_enemies;
    int _enemies_count;
    long _t;
    const long _t_start;
    
    void _initEnemies();

public:

    Game(int enemies_count = 1000);
    ~Game();
    Game(Game const & g);
    Game const & operator=(Game const & g);

    int getEnemies(Enemy * *dst);
    
    void run(bool display_enabled = true); // will be his own namespace
};

#endif