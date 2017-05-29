#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Direction.h"


class Background : public Entity {
public:
	Background(sf::Image &image, float X, float Y, int W, int H, int Direction) :Entity(image, X, Y, W, H) {
		Direction_convert(Direction, dx, dy, 0.6);
	}

	virtual ~Background() {}

	int update(float time);
};