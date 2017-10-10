#pragma once

#include <SFML/Graphics.hpp>
#include "Movable.h"


class Background : public Movable {
public:
	Background(sf::Image &IMAGE, float X, float Y, int DIRECTION) 
		:Movable(IMAGE, X, Y, background_speed, DIRECTION) {}

	int update(float);
};