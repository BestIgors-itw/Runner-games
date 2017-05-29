#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Direction.h"

class Bullets : public Entity {
public:
	float dx, dy, damage;
	Bullets(sf::Image &image, float X, float Y, int W, int H, float Speed, float Direction, int Damage) :Entity(image, X, Y, W, H) {
		Direction_convert(Direction, dx, dy, Speed);
		damage = Damage;
	}

	virtual ~Bullets() {}

	int update(float time);
};