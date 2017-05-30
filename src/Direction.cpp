#include "Direction.h"

void Direction_convert(int Direction, float &dx, float &dy, float speed) {
	switch (Direction) {
	case RIGHT:
		dx = speed;
		dy = 0;
		break;

	case LEFT:
		dx = -speed;
		dy = 0;
		break;

	case DOWN:
		dy = speed;
		dx = 0;
		break;

	case UP:
		dy = -speed;
		dx = 0;
		break;

	case UP_LEFT:
		dx = -speed;
		dy = -speed;
		break;

	case UP_RIGHT:
		dx = speed;
		dy = -speed;
		break;

	case DOWN_RIGHT:
		dx = speed;
		dy = speed;
		break;

	case DOWN_LEFT:
		dx = -speed;
		dy = speed;
		break;

	case STAY:
		dx = 0;
		dy = 0;
		break;
	}
}