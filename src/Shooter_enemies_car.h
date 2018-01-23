#pragma once

#include <SFML/Graphics.hpp>
#include "Unit.h"

extern sf::Clock game_timer, moving_timer;

class Shooter_enemies_car : public Unit {
private:
	float moving_timer;
public:
	Shooter_enemies_car(sf::Texture &TEXTURE, float X, float Y, float SPEED,
		int DIRECTION, float HEALTH, float TIME_BETWEEN_ATTACK, float DAMAGE)
		:Unit(TEXTURE, X, Y, SPEED, DIRECTION, HEALTH, TIME_BETWEEN_ATTACK, 
			DAMAGE) {

		moving_timer = attack_frequency_time;
	}

	int update(float time);

	friend void shooter_enemies_car_garbage_collector
	(std::list<Shooter_enemies_car*> &ENEMIES);
};

void shooter_enemies_car_generate(float &GENERATE_PROBABILITY,
	char &ENEMY_NUMBER, std::list<Shooter_enemies_car*> &ENEMIES,
	float GAME_TIME, sf::Clock &TIMER, sf::Texture &ENEMY_COPSJUPS_T,
	sf::Texture &ENEMY_HAMMER_T, sf::Texture &ENEMY_LAPDCAR_T);