#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Direction.h"

class Bullets : public Entity {
public:
	float dx, dy, damage;
	bool side;
	Bullets(sf::Image &image, float X, float Y, int W, int H, float Speed, float Direction, float Damage, bool Side) :Entity(image, X, Y, W, H) {
		Direction_convert(Direction, dx, dy, Speed);
		damage = Damage;
		side = Side;
	}

	virtual ~Bullets() {}

	int update(float time);
};