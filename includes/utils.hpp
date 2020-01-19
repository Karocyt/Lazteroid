#ifndef UTILS_H
# define UTILS_H
# include <iostream>

# define K_UP 65
# define K_DOWN 66
# define K_SPACE ' '

# define X_MAX 95
# define Y_MAX 30
# define PROJECTILE_SPEED X_MAX * 5
# define COOLDOWN_MS (PROJECTILE_SPEED / X_MAX)
# define PLAYER_OFFSET 2
# define PLAYER_LIFE 150
# define ENEMY_LIFE 150
# define DAMAGE 60
# define ENEMY_CROSS_DAMAGE 30 // not working
# define ENEMY_SPEED 10
# define ONSCREEN_COUNT 5



long getTime();
float min(float a, float b);
float max(float a, float b);

#endif