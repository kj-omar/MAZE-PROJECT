#include "globals.h"
#include <math.h>
#include <SDL2/SDL.h>

void renderEnemies(SDL_Renderer *renderer) {
	for (int i = 0; i < NUM_ENEMIES; i++) {
		if (!enemies[i].isAlive) continue;

		float dx = enemies[i].x - playerX;
		float dy = enemies[i].y - playerY;
		float distance = sqrt(dx * dx + dy * dy);

		int enemyHeight = (int)(SCREEN_HEIGHT / distance);
		int enemyWidth = enemyHeight;

		float angleToEnemy = atan2(dy, dx);
		float angleDiff = wrapAngle(angleToEnemy - playerAngle);

		if (fabs(angleDiff) < (FOV * (PI / 180) / 2)) {
			int enemyScreenX = (int)((SCREEN_WIDTH / 2) + (dx / distance) * (SCREEN_WIDTH / 2));
			int enemyScreenY = (SCREEN_HEIGHT / 2) - enemyHeight / 2;

			SDL_Rect enemyRect = {enemyScreenX, enemyScreenY, enemyWidth, enemyHeight};
			SDL_RenderCopy(renderer, enemyTexture, NULL, &enemyRect);
		}
	}
}

void renderWeapon(SDL_Renderer *renderer, SDL_Texture *weaponTexture, SDL_Texture *weaponFireTexture) {
	int weaponWidth = SCREEN_WIDTH / 2;
	int weaponHeight = SCREEN_HEIGHT / 3;
	SDL_Rect weaponRect = {(SCREEN_WIDTH - weaponWidth) / 2, SCREEN_HEIGHT - weaponHeight, weaponWidth, weaponHeight};

	if (isShooting) {
		SDL_RenderCopy(renderer, weaponFireTexture, NULL, &weaponRect);
	} else {
		SDL_RenderCopy(renderer, weaponTexture, NULL, &weaponRect);
	}
}
