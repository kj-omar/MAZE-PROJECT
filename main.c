#include <SDL2/SDL.h>
#include <stdbool.h>
#include <math.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define FOV 60
#define PI 3.14159265359

// Player variables
float playerX = 100.0, playerY = 100.0, playerAngle = 0.0;

// Weapon shooting variables
bool isShooting = false;
int shootAnimationTime = 0;

// SDL variables
SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

// Texture variables
SDL_Texture *wallTexture = NULL, *floorTexture = NULL, *ceilingTexture = NULL;
SDL_Texture *weaponTexture = NULL, *weaponFireTexture = NULL, *enemyTexture = NULL;

// Enemy structure
typedef struct {
    float x, y;
    bool isAlive;
} Enemy;

#define NUM_ENEMIES 3
Enemy enemies[NUM_ENEMIES] = {
    {400, 400, true},
    {600, 700, true},
    {900, 300, true}
};

// Function prototypes
SDL_Texture *loadTexture(SDL_Renderer *renderer, const char *file);
void renderWorld(SDL_Renderer *renderer);
void renderWeapon(SDL_Renderer *renderer);
void renderEnemies(SDL_Renderer *renderer);
void checkEnemyHit(void);

SDL_Texture *loadTexture(SDL_Renderer *renderer, const char *file) {
    SDL_Surface *surface = SDL_LoadBMP(file);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

void renderWorld(SDL_Renderer *renderer) {
    // Render the walls, floor, ceiling, etc.
    SDL_RenderCopy(renderer, wallTexture, NULL, NULL); // Placeholder wall render
    // Implement your raycasting for walls here
}

void renderEnemies(SDL_Renderer *renderer) {
    for (int i = 0; i < NUM_ENEMIES; i++) {
        if (enemies[i].isAlive) {
            float dx = enemies[i].x - playerX;
            float dy = enemies[i].y - playerY;
            float distance = sqrt(dx * dx + dy * dy);

            int enemyHeight = (int)(SCREEN_HEIGHT / distance);
            int enemyWidth = enemyHeight;

            int enemyScreenX = (int)((SCREEN_WIDTH / 2) * (1 + atan2(dy, dx) / (FOV * (PI / 180))));
            int enemyScreenY = (SCREEN_HEIGHT / 2) - enemyHeight / 2;

            SDL_Rect enemyRect = { enemyScreenX, enemyScreenY, enemyWidth, enemyHeight };
            SDL_RenderCopy(renderer, enemyTexture, NULL, &enemyRect);
        }
    }
}

void checkEnemyHit(void) {
    if (isShooting) {
        for (int i = 0; i < NUM_ENEMIES; i++) {
            if (enemies[i].isAlive) {
                float dx = enemies[i].x - playerX;
                float dy = enemies[i].y - playerY;
                float angleToEnemy = atan2(dy, dx);

                if (fabs(angleToEnemy - playerAngle) < (PI / 18)) {
                    float distance = sqrt(dx * dx + dy * dy);
                    if (distance < 300) {
                        enemies[i].isAlive = false;
                        isShooting = false;
                        break;
                    }
                }
            }
        }
    }
}

void renderWeapon(SDL_Renderer *renderer) {
    int weaponWidth = SCREEN_WIDTH / 2;
    int weaponHeight = SCREEN_HEIGHT / 3;
    SDL_Rect weaponRect = { (SCREEN_WIDTH - weaponWidth) / 2, SCREEN_HEIGHT - weaponHeight, weaponWidth, weaponHeight };

    if (isShooting && shootAnimationTime < 10) {
        SDL_RenderCopy(renderer, weaponFireTexture, NULL, &weaponRect);
        shootAnimationTime++;
    } else {
        SDL_RenderCopy(renderer, weaponTexture, NULL, &weaponRect);
        isShooting = false;
        shootAnimationTime = 0;
    }
}

int main(int /*argc*/, char * /*argv*/[]) {

    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("FPS Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Load textures
    wallTexture = loadTexture(renderer, "textures/wall.bmp");
    floorTexture = loadTexture(renderer, "textures/floor.bmp");
    ceilingTexture = loadTexture(renderer, "textures/ceiling.bmp");
    weaponTexture = loadTexture(renderer, "textures/weapon.bmp");
    weaponFireTexture = loadTexture(renderer, "textures/weapon_fire.bmp");
    enemyTexture = loadTexture(renderer, "textures/enemy.bmp");

    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }

            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_SPACE) {
                    isShooting = true;
                }
            }
        }

        // Game logic
        checkEnemyHit();

        // Render world
        SDL_RenderClear(renderer);
        renderWorld(renderer);
        renderEnemies(renderer);
        renderWeapon(renderer);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(wallTexture);
    SDL_DestroyTexture(floorTexture);
    SDL_DestroyTexture(ceilingTexture);
    SDL_DestroyTexture(weaponTexture);
    SDL_DestroyTexture(weaponFireTexture);
    SDL_DestroyTexture(enemyTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
