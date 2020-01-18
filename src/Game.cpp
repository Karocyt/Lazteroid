#include "Game.hpp"

Game::~Game() {
    std::cout << "Game ended" << std::endl;
}

Game::Game(const Game & f)
{
    *this = f;
}

Game const & Game::operator=(Game const & e) {
    _player = e._player;
    _enemies = e._enemies;
    _enemies_count = e._enemies_count;
    return *this;
}

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
