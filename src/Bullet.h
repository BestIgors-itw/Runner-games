#pragma once

#include <SFML/Graphics.hpp>
#include "Movable.h"

class Bullet : public Movable {
public:
	float damage;
	bool side;
	Bullet(sf::Image &IMAGE, float X, float Y, int W, int H, float SPEED, float DIRECTION, float DAMAGE, bool SIDE)
		:Movable(IMAGE, X, Y, W, H, SPEED, DIRECTION) {
		damage = DAMAGE;
		side = SIDE;
	}

	int update(float time);
};