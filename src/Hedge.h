#pragma once

#include <SFML/Graphics.hpp>
#include "Movable.h"

class Hedge : public Movable {
private:
	float health;
public:
	Hedge(sf::Image &IMAGE, float X, float Y, int W, int H,
		float DIRECTION, float HEALTH)
		:Movable(IMAGE, X, Y, W, H, background_speed, DIRECTION) {
		health = HEALTH;
	}

	float return_health();

	friend bool generate_hedge(float &HEDGE_GENERATE_PROBABILITY,
		std::list<Hedge*> &HEDGES, float GAME_TIME, sf::Clock &HEDGE_TIMER,
		sf::Image IMAGE1, sf::Image IMAGE2);

	int update(float time);
};

