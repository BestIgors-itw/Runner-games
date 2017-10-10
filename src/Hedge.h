#pragma once

#include <SFML/Graphics.hpp>
#include "Movable.h"
#include "Player.h"
#include "Effect.h"

class Hedge : public Movable {
private:
	float health;
public:
	Hedge(sf::Image &IMAGE, float X, float Y, int W, int H,
		float DIRECTION, float HEALTH)
		:Movable(IMAGE, X, Y, W, H, background_speed, DIRECTION) {
		health = HEALTH;
	}

	int update(float time);

	float get_health();

	friend bool generate_hedge(float &HEDGE_GENERATE_PROBABILITY,
		std::list<Hedge*> &HEDGES, float GAME_TIME, sf::Clock &HEDGE_TIMER,
		sf::Image IMAGE1, sf::Image IMAGE2);

	friend void player_collision_hedges(Player &PLAYER, std::list<Hedge*> &HEDGES,
		std::list<Effect*> &EFFECTS, sf::Image EFFECTS_EXPLOSION_i);
};

