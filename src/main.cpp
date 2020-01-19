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
    init_pair(0, COLOR_BLUE , 0);
    init_pair(1, COLOR_WHITE, COLOR_YELLOW);
    init_pair(2, COLOR_WHITE, COLOR_RED);
    init_pair(3, COLOR_RED, COLOR_BLACK);

    std::srand(clock());
    a.run();

    endwin();
}