#include "level.h"

Level::Level() {

	int bricksPerRow = WINDOWWIDTH / BRICKWIDTH;
	int currentRow = 2;
	remainingBricks = NUMBRICKS;

	for (int i = 0, currentBrick = 0; i < NUMBRICKS * 4; i += 4, currentBrick++) {

		if (currentBrick == bricksPerRow) {
			currentRow++;
			currentBrick = 0;
		}

		Brick brick(currentBrick * (BRICKWIDTH), currentRow * (BRICKHEIGHT));

		for (int j = 0; j < 4; j++) {
			vertices[i + j] = brick.vertices[j];
		}
	}

}

void Level::removeBrick(int position) {
	if (position) {
		for (int i = position; i < (NUMBRICKS * 4); i++) {
			vertices[i] = vertices[i + 4];
		}
	remainingBricks--;
	}
}
