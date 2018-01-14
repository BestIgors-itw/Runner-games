#include "Effect.h"

int Effect::update(float time) {
	x += dx * time;
	y += dy * time;
	sprite.setPosition(x, y);
	if (x + w  < 0 || game_timer.getElapsedTime().asSeconds() - timer
	> exist_time) {
		alive = false;
	}
	return 0;
}

void effects_garbage_collector(std::list<Effect*> &EFFECTS) {
	for (std::list<Effect*>::iterator it_effects = EFFECTS.begin(); it_effects
		!= EFFECTS.end(); ) {
		if ((*it_effects)->alive == false) {
			it_effects = EFFECTS.erase(it_effects);
		}
		else {
			++it_effects;
		}
	}
}