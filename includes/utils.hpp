#ifndef UTILS_H
# define UTILS_H
# include <iostream>

# define X_MAX 95
# define Y_MAX 30
# define PROJECTILE_SPEED X_MAX + X_MAX
# define COOLDOWN_MS (PROJECTILE_SPEED / X_MAX)
# define PLAYER_OFFSET 2
# define DAMAGE 60



long getTime();
float min(float a, float b);
float max(float a, float b);

#endif