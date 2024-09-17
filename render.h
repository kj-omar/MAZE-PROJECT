#ifndef RENDER_H
#define RENDER_H

#include <SDL2/SDL.h>

void renderWorld(SDL_Renderer *renderer);
void renderEnemies(SDL_Renderer *renderer);
void renderWeapon(SDL_Renderer *renderer);
void renderEnemyAt(SDL_Renderer *renderer, float dx, float dy, 
                   float distance, int index);
void loadTextures(SDL_Renderer *renderer);
void cleanup(void);

#endif
