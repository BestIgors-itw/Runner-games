#pragma once

#include <SFML/Graphics.hpp>
#include "Movable.h"


class Background : public Movable {
public:
	Background(sf::Texture &TEXTURE, float X, float Y, int DIRECTION) 
		:Movable(TEXTURE, X, Y, background_speed, DIRECTION) {}

	int update(float);

	friend void background_garbage_collector(std::list<Background*>
		&BACKGROUND_OBJECTS);
};

void background_objects_generate(unsigned short int DIRECTION,
	float BACKGROUND_OBJECT_SPAWN_X, float BACKGROUND_OBJECT_SPAWN_Y,
	float BACKGROUND_OBJECT_PROBABILITY, float &GENERATE_PROBABILITY,
	std::list<Background*> &BACKGROUND_OBJECTS, sf::Clock &TIMER,
	sf::Texture &BACKGROUND_ROCKSAND1_T, sf::Texture &BACKGROUND_ROCKSAND2_T,
	sf::Texture &BACKGROUND_ROCKGRAY1_T);