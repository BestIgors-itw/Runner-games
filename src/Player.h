#pragma once

#include <SFML/Graphics.hpp>
#include "Unit.h"

extern sf::Clock game_timer;

class Player : public Unit {
private:
	float score;
public:
	Player(sf::Texture &TEXTURE, float X, float Y, float SPEED,
		int HEALTH, float TIME_BETWEEN_ATTACK, int DAMAGE)
		:Unit(TEXTURE, X, Y, SPEED, STAY, HEALTH, TIME_BETWEEN_ATTACK, DAMAGE),
		score(0.0) {
	}

	void control();

	int update(float);

	void change_score(float VARIABLE);

	float get_score();
};