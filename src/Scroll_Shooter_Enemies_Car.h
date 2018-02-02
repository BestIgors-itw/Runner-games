#pragma once

#include <SFML/Graphics.hpp>
#include "Unit.h"

extern sf::Clock game_timer;

class Scroll_Shooter_enemies_car : public Unit {
private:
	float moving_timer;
public:
	Scroll_Shooter_enemies_car(sf::Texture &TEXTURE, float X, float Y, float SPEED,
		float DIRECTION, float HEALTH, float TIME_BETWEEN_ATTACK, int DAMAGE)
		:Unit(TEXTURE, X, Y, SPEED, DIRECTION, HEALTH, TIME_BETWEEN_ATTACK, DAMAGE) {

		moving_timer = attack_frequency_time;

		if (direction == 2) {
			sprite.setScale(1, -1);
		}
	}

	int update(float time);

	friend void scroll_shooter_enemies_car_generate
	(float &ENEMY_GENERATE_PROBABILITY,
		std::list<Scroll_Shooter_enemies_car*> &ENEMIES, float GAME_TIMER,
		sf::Clock &ENEMY_TIMER, sf::Texture &ENEMY_BATTLEMULE_T,
		sf::Texture &ENEMY_IMPALABATTLE_T, sf::Texture &ENEMY_SLAGE_T);

	friend void scroll_shooter_enemies_car_garbage_collector
	(std::list<Scroll_Shooter_enemies_car*> &ENEMIES);
};
