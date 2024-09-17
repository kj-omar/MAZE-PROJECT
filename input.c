#include "globals.h"
#include <math.h>

void checkEnemyHit(void) {
	if (isShooting) {
		for (int i = 0; i < NUM_ENEMIES; i++) {
			if (!enemies[i].isAlive) continue;

			float dx = enemies[i].x - playerX;
			float dy = enemies[i].y - playerY;
			float distance = sqrt(dx * dx + dy * dy);

			float angleToEnemy = atan2(dy, dx);
			float angleDiff = wrapAngle(angleToEnemy - playerAngle);

			if (fabs(angleDiff) < (PI / 18) && distance < 300) {
				enemies[i].isAlive = false;
				isShooting = false;
				break;
			}
		}
	}
}
