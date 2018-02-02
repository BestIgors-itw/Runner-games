#pragma once

#include <SFML/Graphics.hpp>
#include "Movable.h"

extern sf::Clock game_timer;

class Effect : public Movable {
public:
	float timer, exist_time;
	Effect(sf::Texture &TEXTURE, float X, float Y, float SPEED, float DIRECTION,
		float EXIST_TIME) :Movable(TEXTURE, X, Y, SPEED, DIRECTION) {
		timer = game_timer.getElapsedTime().asSeconds();
		exist_time = EXIST_TIME;
	}

	int update(float time);

	friend void effect_garbage_collector(std::list<Effect*> &EFFECTS);
};