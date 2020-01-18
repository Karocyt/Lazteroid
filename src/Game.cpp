#include "Game.hpp"
# include <unistd.h>
# include <ctime>

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
        _enemies[i].setX(X_MAX);
        _enemies[i].setY(std::rand() % Y_MAX);
        _enemies[i].setDirX(-1);
        _enemies[i].setDirY(0);
    }
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
        double t = (std::clock() - _t_last) / (double)CLOCKS_PER_SEC;
        _t_last = std::clock();
        std::cerr << t << std::endl;
        _player.shoot(enemies, enemies_count);
        for (int i = 0; i < enemies_count; i++)
        {
            _enemies[i].updatePos(t);
        }
        _player.updatePos(t);

        input();
        if (display_enabled)
            display();
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
    Projectile *laser = NULL;
    Enemy *enemies;

    int len = 0;

    erase();
    int enemies_count = getEnemies(&enemies);
    std::cerr << "[P] X:" << _player.getX() << " Y:" << _player.getY() << std::endl;
    mvaddch(_player.getY(), _player.getX(), 'P');
    for (int i = 0; i < enemies_count; i++)
    {
        std::cerr << "[" << i << "] X:" << enemies[i].getX() << " Y:" << enemies[i].getY() << std::endl;
        mvaddch(enemies[i].getY(), enemies[i].getX(), ' ' | COLOR_PAIR(1));
    }
    if ((laser = _player.getLaser()))
    {
        std::cerr << "NIQUE TOI BIEN---------------------" << std::endl;
        len = laser->getLen();
        for (int j = 0; j < len - 1; j++) {
            mvaddch(_player.getY(), _player.getX() + j + 1, '-' | COLOR_PAIR(1));

        }
    }
}

