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
    _global_count = e._global_count;
    _t = e._t;
    _t_last = e._t_last;
    return *this;
}

Game::Game(int enemies_count) :
    _global_count(enemies_count),
    _t(0),
    _t_start(clock()),
    _t_last(0)
{
    // std::cerr << "Game started with " << _global_count << " enemies" << std::endl;
    _enemies = new Enemy[enemies_count];
}

void Game::_initEnemies(int nb) {
    int i = 0;
    while (i < _global_count && (!_enemies[i].getHp() || _enemies[i].getY() != -1))
        i++;
    if (i == _global_count)
        return;

    for (int count = 0; i < _global_count && count < nb; i++)
    {
        if (_enemies[i].getHp())
        {
            _enemies[i].setX(X_MAX);
            _enemies[i].setY((i * 13 + std::rand())  % Y_MAX);
            _enemies[i].setDirX(-1);
            _enemies[i].setDirY(0);
            // std::cerr << "Enemy " << i + 1 << std::endl;
            count++;
        }
    }
}

void Game::run(bool display_enabled)
{
    _initEnemies(ONSCREEN_COUNT);

    Enemy *enemies;
    int enemies_count;
    int alive = 0;

    while ((enemies_count = getEnemies(&enemies)) && _player.getState())
    {
        double t = (clock() - _t_last) / (double)CLOCKS_PER_SEC;
        _t_last = clock();
        alive = 0;
        for (int i = 0; i < enemies_count; i++)
        {
            // std::cerr << "Updating enemy " << i + 1 << " pos: " << _enemies[i].getY() << " " << _enemies[i].getX() << std::endl;
            _player.takeDamage(enemies[i].update(t));
            if (enemies[i].getState())
                alive++;
            if (enemies[i].getState() && (int)_player.getY() == (int)enemies[i].getY() && (int)enemies[i].getX() <= 1) // COLLISION
               _player.takeDamage(_player.getHp());
        }
        _player.update(t);

        input(enemies, enemies_count);
        if (display_enabled)
            display(enemies, enemies_count);
        if (alive < ONSCREEN_COUNT)
            _initEnemies(1);
    }
}

int Game::getEnemies(Enemy **dst) {
    int start = 0;

    if (!_enemies)
        return 0;
    while (start < _global_count && !_enemies[start].getState())
        start++;
    if (!_enemies[start].getState())
        return 0;

    *dst = _enemies + start;

    int end = start;
    while (end < _global_count - 1 && _enemies[end].getX() != -1)
        end++;
    return (end - start);
}

void Game::input(Enemy *enemies, int enemies_count) {
    switch(getch()) {
    case K_UP:
        _player.setY(_player.getY() - 1);
        break;
    case K_DOWN:
        _player.setY(_player.getY() + 1);
        break;
    case K_SPACE:
        if (!_player.getLaser())
        _player.shoot(enemies, enemies_count);
        break;
    }
}

void Game::display(Enemy * enemies, int enemies_count) {
    Projectile * laser;

    erase();
    std::string score = "Score: " + std::to_string(_player.getScore());
    std::string life = "Life: " + std::to_string(_player.getHp());
    mvaddstr(Y_MAX + 1, 0, score.c_str());
    mvaddstr(Y_MAX + 1, X_MAX / 2, life.c_str());
    //for (int heart = _player.getHp(); heart < 50; heart -= 50)
    //    mvaddstr(Y_MAX + heart / 50, X_MAX / 2, "❤️");

    for (int line1 = 0; line1 < Y_MAX + 4; line1++) {
        if (line1 == Y_MAX)
            mvaddch(line1, X_MAX, ACS_RTEE);
        else if (line1 == Y_MAX + 3)
            mvaddch(line1, X_MAX, ACS_LRCORNER);
        else
            mvaddch(line1, X_MAX, ACS_VLINE);
    }
    
    for (int line2 = 0; line2 < X_MAX; line2++) {
        mvaddch(Y_MAX, line2, ACS_HLINE);
        mvaddch(Y_MAX + 3, line2, ACS_HLINE);
    }

    mvaddch(_player.getY(), _player.getX(), '>' | COLOR_PAIR(0));

    for (int i = 0; i < enemies_count; i++) {
        if (enemies[i].getState()) {
            // std::cerr << "Enemy " << i + 1 << "/" << enemies_count << "[" << enemies[i].getHp() << "] X:" << enemies[i].getX() << " Y:" << enemies[i].getY() << std::endl;
            if (enemies[i].getHp() <= 50)
                mvaddch(enemies[i].getY(), enemies[i].getX(), 'O' | COLOR_PAIR(2));
            else
                mvaddch(enemies[i].getY(), enemies[i].getX(), 'O' | COLOR_PAIR(1));
        }
    }

    if ((laser = _player.getLaser()))
        mvaddch(laser->getY(), laser->getX(), '=' | COLOR_PAIR(3));
}
