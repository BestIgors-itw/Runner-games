#pragma once

#include <SFML/Graphics.hpp>
#include "Movable.h"

class Bullet : public Movable {
public:
	float damage;
	bool side;
	Bullet(sf::Texture &TEXTURE, float X, float Y, float SPEED, float DIRECTION,
		float DAMAGE, bool SIDE) :Movable(TEXTURE, X, Y, SPEED, DIRECTION) {
		damage = DAMAGE;
		side = SIDE;
	}

	int update(float);

	friend void bullet_garbage_collector(std::list<Bullet*> &BULLETS);
};