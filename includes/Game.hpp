#ifndef GAME_H
# define GAME_H
# include "Player.hpp"
# include "Enemy.hpp"

class Game {

private:
protected:
    Player _player;
    Enemy *_enemies;
    int _enemies_count;

public:

    Game(int enemies_count = 1000);
    ~Game();
    Game(Game const & g);
    Game const & operator=(Game const & g);

    int getEnemies(Enemy * *dst);
    
    void run(bool display_enabled = true); // will be his own namespace
};

#endif