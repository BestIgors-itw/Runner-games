#include "Bullet.h"

int Bullet::update(float time) {
	x += dx * time;
	y += dy * time;
	sprite.setPosition(x + w / 2, y + h / 2);
	if (x + w < 0 || x - w > screen_width
		|| y + h < 0 || y - h > screen_height) {
		alive = false;
	}
	return 0;
}