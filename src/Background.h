#pragma once

#include <SFML/Graphics.hpp>
#include "Movable.h"


class Background : public Movable {
public:
	Background(sf::Image &IMAGE, float X, float Y, int DIRECTION) 
		:Movable(IMAGE, X, Y, background_speed, DIRECTION) {}

	int update(float);
};

void generate_background_objects(float &GENERATE_PROBABILITY,
	std::list<Background*> &BACKGROUND_OBJECTS, sf::Clock &TIMER,
	sf::Image IMAGE1, sf::Image IMAGE2, sf::Image IMAGE3);