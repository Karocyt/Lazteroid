#ifndef UTILS_H
# define UTILS_H
# include <iostream>

# define K_UP 65
# define K_DOWN 66
# define K_SPACE ' '

# define X_MAX 125
# define Y_MAX 20
# define PROJECTILE_SPEED X_MAX * 5
# define COOLDOWN_MS (PROJECTILE_SPEED / X_MAX)
# define PLAYER_OFFSET 2
# define PLAYER_LIFE 200
# define ENEMY_LIFE 100
# define DAMAGE 50
# define ENEMY_CROSS_DAMAGE 10 // needs to divide player hp
# define ENEMY_SPEED 10
# define ONSCREEN_COUNT 5

# define BACKGROUND "     *   .                  .              .        .   *          .\n\
  .         .                     .       .           .      .        .\n\
        o                             .                   .\n\
         .              .                  .           .         .              .                  .           .\n\
          0     .\n\
                 .          .                 ,                ,       .                 ,                ,       .         ,\n\
 .          \\          .                         .\n\
      .      \\   ,\n\
   .          o     .                 .                   .             .                 .                   .            .\n\
     .         \\                 ,             .                .               ,             .                .\n\
               #\\##\\#      .                              .        .\n\
             #  #O##\\###                .                           .                           .                        .\n\
   .        #*#  #\\##\\###                       .                                .                     ,\n\
        .   ##*#  #\\##\\##               .                     .\n\
      .      ##*#  #o##\\#         .                             ,       .\n\
          .     *#  #\\#     .                    .             .          ,     .                    .             .          \n\
                      \\          .                         .          .                         .\n\
____^/\\___^--____/\\____O______________/\\/\\---/\\___________---___________________/\\____O_______________/\\/\\---/\\______________\n\
   /\\^   ^  ^    ^                  ^^ ^  '\\ ^          ^       ---/\\^   ^  ^    ^                  ^^ ^  '\\ ^          ^  \n\
         --           -            --  -      -         ---  __               --           -            --  -      -          "

long getTime();
float min(float a, float b);
float max(float a, float b);

#endif