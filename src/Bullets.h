#pragma once
#include "Entity.h"
#include "Direction.h"

extern sf::Clock clock1, game_timer, background_timer;

class Bullets : public Entity {
public:
	float dx, dy, damage;
	Bullets(sf::Image &image, float X, float Y, int W, int H, float Speed, float Direction, int Damage) :Entity(image, X, Y, W, H) {
		Direction_convert(Direction, dx, dy, Speed);
		damage = Damage;
	}

	int update(float time);
};