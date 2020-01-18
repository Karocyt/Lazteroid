#ifndef GAME_H
# define GAME_H
# include "Player.hpp"
# include "Enemy.hpp"

class Game {

private:
protected:
    Player _player;
    Enemy *_enemies;
    unsigned _enemies_count;

public:

    Game(unsigned enemies_count = 42);
    ~Game();
    Game(Game const & g);
    Game const & operator=(Game const & g);
    
    void run(bool display_enabled = true); // will be his own namespace
};

#endif