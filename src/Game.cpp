#include "Game.hpp"

Game::~Game() {
    delete [] _enemies;
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

Game::Game(int enemies_count) : _enemies_count(enemies_count)
{
    std::cout << "Game started with " << _enemies_count << " enemies" << std::endl;
    _enemies = new Enemy[enemies_count]; 
}

void Game::run(bool display_enabled)
{
    void update();

    (void)display_enabled;

    Enemy *enemies;
    int enemies_count = getEnemies(&enemies);
    _player.shoot(enemies, enemies_count);
    _enemies[0].moveTo(5, 5);
    _enemies[0].updatePos(3000);
}

int Game::getEnemies(Enemy **dst) {
    int start = 0;

    if (!_enemies)
        return 0;
    for (;start < _enemies_count && !_enemies[start].getState();)
        start++;

    if (!_enemies[start].getState())
        return 0;

    *dst = &_enemies[start];

    int end = start;
    for (; end < _enemies_count && _enemies[end].getX() != -1; end++)
    {
    }

    return (end - start);
}
