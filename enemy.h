#include <stdbool.h>
#ifndef ENEMY_H
#define ENEMY_H

#define NUM_ENEMIES 3
typedef struct {
    float x, y;
    bool isAlive;
} Enemy;

extern Enemy enemies[NUM_ENEMIES];

#endif
