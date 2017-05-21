#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.h"

class Background : public Entity {
public:
	Background(sf::Image &image, float X, float Y, int W, int H) :Entity(image, X, Y, W, H) {
		dy = 0.6;
	}

	int update(float time);
};