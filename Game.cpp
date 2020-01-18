#include "Game.hpp"

Game::Game(unsigned enemies_count) : _enemies_count(enemies_count)
{
    _enemies = new Enemy[enemies_count]; 
}


void Game::run(unsigned enemies_count)
{
    std::cout << "Game started with " << enemies_count << " enemies" << std::endl;
}
