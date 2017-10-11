#pragma once

#include <SFML/Graphics.hpp>
#include "Movable.h"


class Background : public Movable {
public:
	Background(sf::Image &IMAGE, float X, float Y, int DIRECTION) 
		:Movable(IMAGE, X, Y, background_speed, DIRECTION) {}

	int update(float);
};

void generate_background_objects(unsigned short int DIRECTION,
	float BACKGROUND_OBJECT_SPAWN_X, float BACKGROUND_OBJECT_SPAWN_Y,
	float BACKGROUND_OBJECT_PROBABILITY, float &GENERATE_PROBABILITY,
	std::list<Background*> &BACKGROUND_OBJECTS, sf::Clock &TIMER,
	sf::Image IMAGE1, sf::Image IMAGE2, sf::Image IMAGE3);

void background_garbage_collector(std::list<Background*> &BACKGROUND_OBJECTS);