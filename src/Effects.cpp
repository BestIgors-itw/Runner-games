#include "Effects.h"

int Effects::update(float time) {
	x += dx * time;
	y += dy * time;
	sprite.setPosition(x, y);
	if (x + w < 0 || game_timer.getElapsedTime().asSeconds() - timer > exist_time) {
		life = false;
	}
	return 0;
}