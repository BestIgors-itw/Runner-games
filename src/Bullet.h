#pragma once

#include <SFML/Graphics.hpp>
#include "Movable.h"

class Bullet : public Movable {
public:
	float damage;
	bool side;
	Bullet(sf::Image &IMAGE, float X, float Y, float SPEED, float DIRECTION,
		float DAMAGE, bool SIDE) :Movable(IMAGE, X, Y, SPEED, DIRECTION) {
		damage = DAMAGE;
		side = SIDE;
	}

	int update(float);
};