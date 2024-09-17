#include "globals.h"
#include <stdio.h>
#include <math.h>
#include <SDL2/SDL.h>

/* Global variables */
float playerX = 100.0, playerY = 100.0, playerAngle = 0.0;
int SCREEN_WIDTH = 800, SCREEN_HEIGHT = 600;
const int NUM_ENEMIES = 3;
const float FOV = 60.0;
const float PI = 3.14159265359;
bool isShooting = false;

/* Global texture for enemies */
SDL_Texture *enemyTexture;

/* Enemy array definition */
Enemy enemies[3];

/* Function to initialize enemies */
void initializeEnemies(void) {
    enemies[0] = (Enemy){400, 400, true};
    enemies[1] = (Enemy){600, 700, true};
    enemies[2] = (Enemy){900, 300, true};
}

/* Wrap angle to be between -PI and PI */
float wrapAngle(float angle) {
    while (angle < -PI) angle += 2 * PI;
    while (angle > PI) angle -= 2 * PI;
    return angle;
}

int main(void) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("FPS Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (!window) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_Texture *wallTexture = loadTexture(renderer, "textures/wall.bmp");
    if (!wallTexture) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    enemyTexture = loadTexture(renderer, "textures/enemy.bmp");
    if (!enemyTexture) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    initializeEnemies();

    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        SDL_RenderClear(renderer);
        renderEnemies(renderer);
        renderWeapon(renderer, wallTexture, enemyTexture);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(wallTexture);
    SDL_DestroyTexture(enemyTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
