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

void bullet_garbage_collector(std::list<Bullet*> &BULLETS) {
	for (std::list<Bullet*>::iterator it_bullets = BULLETS.begin(); it_bullets != BULLETS.end();) {
		if ((*it_bullets)->is_alive() == false) {
			it_bullets = BULLETS.erase(it_bullets);
		}
		else ++it_bullets;
	}
}
