#include "Hedges.h"

int Hedges::update(float time) {
	x += dx * time;
	y += dy * time;

	if (y - h / 2 > screen_hight + 300 || y + h / 2 < -300 || x - w / 2 > screen_width + 300 || x + w / 2 < -300) {
		life = false;
	}

	sprite.setPosition(x + w / 2, y + h / 2);

	return 0;
}