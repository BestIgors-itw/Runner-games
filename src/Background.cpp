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

void background_objects_generate(unsigned short int DIRECTION,
	float BACKGROUND_OBJECT_SPAWN_X, float BACKGROUND_OBJECT_SPAWN_Y,
	float BACKGROUND_OBJECT_PROBABILITY, float &GENERATE_PROBABILITY,
	std::list<Background*> &BACKGROUND_OBJECTS, sf::Clock &TIMER,
	sf::Texture &BACKGROUND_ROCKSAND1_T, sf::Texture &BACKGROUND_ROCKSAND2_T,
	sf::Texture &BACKGROUND_ROCKGRAY1_T) {
	if (GENERATE_PROBABILITY < 0) {
		int r = rand() % 3;
		switch (r) {
		case 0:
			BACKGROUND_OBJECTS.push_back(new Background
			(BACKGROUND_ROCKSAND1_T, BACKGROUND_OBJECT_SPAWN_X,
				BACKGROUND_OBJECT_SPAWN_Y,
				DIRECTION));
			break;
		case 1:
			BACKGROUND_OBJECTS.push_back(new Background
			(BACKGROUND_ROCKSAND2_T, BACKGROUND_OBJECT_SPAWN_X,
				BACKGROUND_OBJECT_SPAWN_Y,
				DIRECTION));
			break;
		case 2:
			BACKGROUND_OBJECTS.push_back(new Background
			(BACKGROUND_ROCKGRAY1_T, BACKGROUND_OBJECT_SPAWN_X,
				BACKGROUND_OBJECT_SPAWN_Y,
				DIRECTION));
			break;
		}

		GENERATE_PROBABILITY = BACKGROUND_OBJECT_PROBABILITY;
		TIMER.restart();
	}
}

void background_garbage_collector(std::list<Background*> &BACKGROUND_OBJECTS) {
	for (std::list<Background*>::iterator it_background
		= BACKGROUND_OBJECTS.begin(); it_background
		!= BACKGROUND_OBJECTS.end(); ) {
		if ((*it_background)->alive == false) {
			it_background = BACKGROUND_OBJECTS.erase(it_background);
		}
		else {
			++it_background;
		}
	}
}
