#ifndef GLOBALS_H
#define GLOBALS_H

#include <stdbool.h>
#include <SDL2/SDL.h>

/* Player variables */
extern float playerX, playerY, playerAngle;

/* Screen and game constants */
extern int SCREEN_WIDTH, SCREEN_HEIGHT;
extern const int NUM_ENEMIES;
extern const float FOV;
extern const float PI;

/* Weapon shooting state */
extern bool isShooting;

/* Enemy structure */
typedef struct {
    float x, y;
    bool isAlive;
} Enemy;

/* Enemy array */
extern Enemy enemies[];

/* Global texture for enemies */
extern SDL_Texture *enemyTexture;

/* Function prototypes */
float wrapAngle(float angle);
SDL_Texture *loadTexture(SDL_Renderer *renderer, const char *file);
void renderEnemies(SDL_Renderer *renderer);
void renderWeapon(SDL_Renderer *renderer, SDL_Texture *weaponTexture, SDL_Texture *weaponFireTexture);

#endif
