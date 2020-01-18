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
    return *this;
}

Game::Game(int enemies_count) : _enemies_count(enemies_count), _t(0), _t_start(std::time(nullptr)*1000)
{
    std::cout << "Game started with " << _enemies_count << " enemies" << std::endl;
    _enemies = new Enemy[enemies_count]; 
}

void Game::_initEnemies() {
    for (int i = 0; i < _enemies_count && i < 2; i++)
    {
        _enemies[i].setX(20);
        _enemies[i].setY(1 + i);
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

    _initEnemies();
    while (1/*(enemies_count = getEnemies(&enemies))*/)
    {
        enemies_count = getEnemies(&enemies);
        int t = std::time(nullptr)*1000 - _t_start;
        std::cerr << t <<std::endl;
        //if (display_enabled)
        //    update();
        _player.shoot(enemies, enemies_count);
        //_enemies[0].moveTo(5, 5);
        _enemies[0].updatePos(t);
        _enemies[1].updatePos(t);
        display();
        if (1)
            input();
        msleep(10);
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

