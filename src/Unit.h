#pragma once

#include <SFML/Graphics.hpp>
#include "Direction.h"
#include "Movable.h"

extern sf::Clock game_timer;

class Unit : public Movable {
protected:
	int health, damage;
	bool shot_available;
	float attack_frequency_time, time_between_attack;
public:
	Unit(sf::Texture &TEXTURE, float X, float Y, float SPEED,
		float DIRECTION, int HEALTH, float TIME_BETWEEN_ATTACK, int DAMAGE)
		:Movable(TEXTURE, X, Y, SPEED, DIRECTION), shot_available(true) {
		health = HEALTH;

		time_between_attack = TIME_BETWEEN_ATTACK;
		damage = DAMAGE;
		attack_frequency_time = game_timer.getElapsedTime().asSeconds();
	}

	int update(float);

	void change_health(float VARIABLE);

	int get_health();

	int return_damage();

	void shoot();

	bool is_shot_available();
};