#include "Background.h"

int Background::update(float time) {
	x += dx * time;
	y += dy * time;

	sprite.setPosition(x, y);

	if (y > screen_hight || x + w / 2 < 0) {
		life = false;
	}

	return 0;
}