#include <stdbool.h>
#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>
void handleInput(SDL_Event *event, bool *running);
void checkEnemyHit(void);

#endif
