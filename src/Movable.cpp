#include "Movable.h"

int Movable::update(float time) {
	x += dx * time;
	y += dy * time;

	sprite.setPosition(x + w / 2, y + h / 2);

	return 0;
}

int Movable::return_direction() {
	return direction;
}
