#include "Enemies.h"

int Enemies::update(float time) {
	x += dx * time;
	y += dy * time;

	if (y - h / 2 > screen_hight) {
		life = false;
	}

	sprite.setPosition(x + w / 2, y + h / 2);

	return 0;
}