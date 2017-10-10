#include "Direction.h"

void Direction_convert(int DIRECTION, float &DX, float &DY, float SPEED) {
	switch (DIRECTION) {
	case RIGHT:
		DX = SPEED;
		DY = 0;
		break;

	case LEFT:
		DX = -SPEED;
		DY = 0;
		break;

	case DOWN:
		DY = SPEED;
		DX = 0;
		break;

	case UP:
		DY = -SPEED;
		DX = 0;
		break;

	case UP_LEFT:
		DX = -SPEED;
		DY = -SPEED;
		break;

	case UP_RIGHT:
		DX = SPEED;
		DY = -SPEED;
		break;

	case DOWN_RIGHT:
		DX = SPEED;
		DY = SPEED;
		break;

	case DOWN_LEFT:
		DX = -SPEED;
		DY = SPEED;
		break;

	case STAY:
		DX = 0;
		DY = 0;
		break;
	}
}