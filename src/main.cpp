#include "Game.hpp"

int main(void) {
    Game a;

    setlocale(LC_ALL, "");
    initscr();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    attron(A_BOLD);
    start_color();
    init_pair(1, COLOR_BLUE , COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_WHITE, -1);

    std::srand(clock());
    a.run();

    endwin();
}