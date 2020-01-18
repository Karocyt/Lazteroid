#include "Game.hpp"

Game::Game(unsigned enemies_count) : _enemies_count(enemies_count)
{
    _enemies = new Enemy[enemies_count]; 
}


void Game::run(bool display_enabled)
{
    void update();
    void display();

    (void)display_enabled;
    std::cout << "Game started with " << _enemies_count << " enemies" << std::endl;
}

