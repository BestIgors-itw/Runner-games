#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.h"

#define screen_width 1600
#define screen_hight 900

class Background : public Entity {
public:
	Background(sf::Image &image, float X, float Y, int W, int H) :Entity(image, X, Y, W, H) {
		dy = 0.6;
	}

	virtual ~Background() {}

	int update(float time);
};