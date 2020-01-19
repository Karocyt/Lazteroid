#include "Game.hpp"

Game::~Game() {
    delete [] _enemies;
    std::cout << "Game ended: " << _player.getScore() << "pts" << std::endl;
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
    _t_start(clock()),
    _t_last(0)
{
    std::cerr << "Game started with " << _enemies_count << " enemies" << std::endl;
    _enemies = new Enemy[enemies_count];
}

void Game::_initEnemies(int nb) {
    int i = 0;
    for (;i < _enemies_count && (!_enemies[i].getHp() || _enemies[i].getY() != -1);)
        i++;
    if (i == _enemies_count)
        return;

    for (int count = 0; i < _enemies_count && count < nb; i++)
    {
        if (_enemies[i].getHp())
        {
            _enemies[i].setX(X_MAX);
            _enemies[i].setY((i * 13 + std::rand())  % Y_MAX);
            _enemies[i].setDirX(-1);
            _enemies[i].setDirY(0);
            std::cerr << "Enemy " << i + 1 << std::endl;
            count++;
        }
    }
}

void Game::init() {
    initscr();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_YELLOW);
    _initEnemies(ENEMY_COUNT);
}

void Game::run(bool display_enabled)
{
    this->init();
    (void)display_enabled;

    Enemy *enemies;
    int enemies_count;
    int alive = 0;

    while ((enemies_count = getEnemies(&enemies)) && _player.getState())
    {
        double t = (clock() - _t_last) / (double)CLOCKS_PER_SEC;
        _t_last = clock();
        std::cerr << t << std::endl;
        if (!_player.getLaser())
            _player.shoot(enemies, enemies_count);
        alive = 0;
        for (int i = 0; i < enemies_count; i++)
        {
            std::cerr << "Updating enemy " << i + 1 << ": ";
            _player.takeDamage(enemies[i].update(t));
            if (enemies[i].getState())
                alive++;
        }
        _player.update(t);

        input();
        if (display_enabled)
            display(enemies, enemies_count);
        if (alive < ENEMY_COUNT)
            _initEnemies(1);
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

    *dst = _enemies + start;

    int end = start;
    for (; end < _enemies_count - 1 && _enemies[end].getX() != -1;)
    {
        end++;
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

void Game::display(Enemy * enemies, int enemies_count) {
    erase();
    mvaddch(_player.getY(), _player.getX(), 'P');
    for (int i = 0; i < enemies_count; i++)
        if (enemies[i].getState())
        {
            std::cerr << "Enemy " << i + 1 << "/" << enemies_count << "[" << enemies[i].getHp() << "] X:" << enemies[i].getX() << " Y:" << enemies[i].getY() << std::endl;
            mvaddch(enemies[i].getY(), enemies[i].getX(), ' ' | COLOR_PAIR(1));
        }

    Projectile * laser;
    if ((laser = _player.getLaser()))
        mvaddch(laser->getY(), laser->getX(), '-');
}

