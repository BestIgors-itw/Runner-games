#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Enemies.h"

#define screen_width 1600
#define screen_hight 900

class Hedges : public Enemies {
public:
	float speed;
	Hedges(sf::Image &image, float X, float Y, int W, int H,
		float Direction, float Health)
		:Enemies(image, X, Y, W, H, Direction, Health) {
		direction = Direction;
		speed = 0.6;
		Direction_convert(direction, dx, dy, speed);
	}
};


