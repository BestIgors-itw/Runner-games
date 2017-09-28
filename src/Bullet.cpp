#include "Bullet.h"

int Bullet::update(float time) {
	x += dx * time;
	y += dy * time;
	sprite.setPosition(x + w / 2, y + h / 2);
	if (x + bullet_width < 0 || x - bullet_width > screen_width || y + bullet_hight < 0 || y - bullet_hight > screen_hight) {
		life = false;
	}
	return 0;
}