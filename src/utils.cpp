#include "utils.hpp"

long getTime() {
    return clock() / (double)CLOCKS_PER_SEC;
}

float min(float a, float b) {
    if (a < b)
        return a;
    return b;
}

float max(float a, float b) {
    if (a > b)
        return a;
    return b;
}