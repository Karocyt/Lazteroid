#include "Game.hpp"

Game::~Game() {
    delete [] _enemies;
    std::cout << "Game ended" << std::endl;
}

Game::Game(const Game & f) : _t_start(f._t_start)
{
    *this = f;
}

Game const & Game::operator=(Game const & e) {
    _player = e._player;
    _enemies = e._enemies;
    _enemies_count = e._enemies_count;
    _t = e._t;
    _t_last = e._t_last;
    return *this;
}

Game::Game(int enemies_count) :
    _enemies_count(enemies_count),
    _t(0),
    _t_start(std::time(nullptr)*1000),
    _t_last(0)
{
    std::cout << "Game started with " << _enemies_count << " enemies" << std::endl;
    _enemies = new Enemy[enemies_count]; 
}

void Game::_initEnemies(int nb) {
    int i = 0;
    for (;i < _enemies_count && !_enemies[i].getState();)
        i++;
    if (i == _enemies_count)
        return;

    for (int count = 0; i < _enemies_count && count < nb; count++)
    {
        _enemies[i].setX(20);
        _enemies[i].setY(1);
        _enemies[i].setDirX(-1);
        _enemies[i].setDirY(0);
    }
}

void msleep(long msec) {
    struct timespec ts;

    if (msec < 0)
        return;
    ts.tv_sec = msec / 1000;
    ts.tv_nsec = (msec % 1000) * 1000000;
    nanosleep(&ts, &ts);
}

void Game::run(bool display_enabled)
{
    (void)display_enabled;

    Enemy *enemies;
    int enemies_count;

    _initEnemies(2);
    while ((enemies_count = getEnemies(&enemies)))
    {
        long t = std::time(nullptr)*1000.0 - _t_last;
        _t_last = std::time(nullptr)*1000;
        std::cout << t << std::endl;
        //if (display_enabled)
        //    update();
        _player.shoot(enemies, enemies_count);
        //_enemies[0].moveTo(5, 5);
        for (int i = 0; i < enemies_count; i++)
            _enemies[i].updatePos(t);
        _player.updatePos(t);

        msleep(200);
    }
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
