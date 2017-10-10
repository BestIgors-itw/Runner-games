#include "Background.h"

int Background::update(float time) {
	x += dx * time;
	y += dy * time;

	sprite.setPosition(x + w / 2, y + h / 2);

	if (y - h / 2 > screen_height || x + w / 2 < 0) {
		alive = false;
	}

	return 0;
}