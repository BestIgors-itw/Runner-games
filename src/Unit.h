#pragma once

#include <SFML/Graphics.hpp>
#include "Direction.h"
#include "Movable.h"

extern sf::Clock game_timer;

class Unit : public Movable {
public:
	float attack_frequency_time, time_between_attack;
	int health, damage;
	bool is_shot_available, is_shot;
	Unit(sf::Image &IMAGE, float X, float Y, int W, int H, float SPEED,
		float DIRECTION, int HEALTH, float TIME_BETWEEN_ATTACK, int DAMAGE)
		:Movable(IMAGE, X, Y, W, H, SPEED, DIRECTION), is_shot_available(true),
		is_shot(false) {
		health = HEALTH;

		time_between_attack = TIME_BETWEEN_ATTACK;
		damage = DAMAGE;
		attack_frequency_time = game_timer.getElapsedTime().asSeconds();
	}

	int update(float time);
};