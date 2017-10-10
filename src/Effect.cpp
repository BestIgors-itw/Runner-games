#include "Effect.h"

int Effect::update(float time) {
	x += dx * time;
	y += dy * time;
	sprite.setPosition(x, y);
	if (x + w  < 0 || game_timer.getElapsedTime().asSeconds() - timer > exist_time) {
		alive = false;
	}
	return 0;
}