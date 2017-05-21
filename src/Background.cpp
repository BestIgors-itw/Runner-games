#include "Background.h"

int Background::update(float time) {
	y += dy * time;
	sprite.setPosition(x, y);
	if (y > screen_hight) {
		life = false;
	}
	return 0;
}