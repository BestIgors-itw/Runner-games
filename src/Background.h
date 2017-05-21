#pragma once
#include "Entity.h"

extern sf::Clock clock1, game_timer, background_timer;

class Background : public Entity {
public:
	Background(sf::Image &image, float X, float Y, int W, int H) :Entity(image, X, Y, W, H) {
		dy = 0.6;
	}

	int update(float time);
};