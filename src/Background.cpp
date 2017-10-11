#include "Background.h"

int Background::update(float time) {
	x += dx * time;
	y += dy * time;

	sprite.setPosition(x + w / 2, y + h / 2);

	if (y - h / 2 > screen_height || x + w / 2 < 0) {
		alive = false;
	}

	return 0;
}

void generate_background_objects(float &GENERATE_PROBABILITY,
	std::list<Background*> &BACKGROUND_OBJECTS, sf::Clock &TIMER, sf::Image IMAGE1,
	sf::Image IMAGE2, sf::Image IMAGE3) {
	if (GENERATE_PROBABILITY < 0) {
		int r = rand() % 3;
		switch (r) {
		case 0:
			BACKGROUND_OBJECTS.push_back(new Background
			(IMAGE1, Race_background_object_spawn_x,
				Race_background_object_spawn_y,
				DOWN));
			break;
		case 1:
			BACKGROUND_OBJECTS.push_back(new Background
			(IMAGE2, Race_background_object_spawn_x,
				Race_background_object_spawn_y,
				DOWN));
			break;
		case 2:
			BACKGROUND_OBJECTS.push_back(new Background
			(IMAGE3, Race_background_object_spawn_x,
				Race_background_object_spawn_y,
				DOWN));
			break;
		}

		GENERATE_PROBABILITY = Race_background_object_probability;
		TIMER.restart();
	}
}
