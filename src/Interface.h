#pragma once

#include "SFML/Graphics.hpp"
#include "Entity.h"

class Interface : public Entity {
public:
	Interface(sf::Image &image, float X, float Y, int W, int H) :Entity(image, X, Y, W, H) {
	}

	int update(float time);
};
