#include "Game.hpp"
# include <ncurses.h>
# include <unistd.h>

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
    _t_start(std::clock()),
    _t_last(0)
{
    std::cerr << "Game started with " << _enemies_count << " enemies" << std::endl;
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
        std::cout << "h";
        _enemies[i].setX(20);
        _enemies[i].setY(1 + count);
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
    initscr();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);

    (void)display_enabled;

    Enemy *enemies;
    int enemies_count;
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_YELLOW);

    _initEnemies(2);
    while ((enemies_count = getEnemies(&enemies)))
    {
        long t = std::clock() - _t_last;
        _t_last = std::clock();
        std::cerr << t << std::endl;
        _player.shoot(enemies, enemies_count);
        for (int i = 0; i < enemies_count; i++)
        {
            _enemies[i].updatePos(t);
        }
        _player.updatePos(t);

        if (display_enabled)
            display();
        if (1)
            input();
        msleep(300);
    }
    endwin();
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

void Game::input(void) {
    switch(getch()) {
    case 65:    // key up
        _player.setY(_player.getY() - 1);
        break;
    case 66:    // key down
        _player.setY(_player.getY() + 1);
        break;
    case 67:    // key right
        break;
    case 68:    // key left
        break;
    case ' ':   // key space
        break;
    }
}

void Game::display(void) {
    erase();
    Enemy *enemies;
    int enemies_count = getEnemies(&enemies);
    std::cerr << "[P] X:" << _player.getX() << " Y:" << _player.getY() << std::endl;
    mvaddch(_player.getY(), _player.getX(), 'P');
    for (int i = 0; i < enemies_count; i++)
    {
        std::cerr << "[" << i << "] X:" << enemies[i].getX() << " Y:" << enemies[i].getY() << std::endl;
        mvaddch(enemies[i].getY(), enemies[i].getX(), ' ' | COLOR_PAIR(1));
    }
}

