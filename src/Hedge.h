#pragma once

#include <SFML/Graphics.hpp>
#include "Movable.h"
#include "Player.h"
#include "Effect.h"

class Hedge : public Movable {
private:
	float health;
public:
	Hedge(sf::Texture &TEXTURE, float X, float Y, float DIRECTION, float HEALTH)
		:Movable(TEXTURE, X, Y, background_speed, DIRECTION) {
		health = HEALTH;
	}

	int update(float time);

	float get_health();

	friend void hedges_garbage_collector(std::list<Hedge*>&);

	friend void player_collision_hedges(Player &PLAYER, std::list<Hedge*> &HEDGES,
		std::list<Effect*> &EFFECTS, sf::Texture &EFFECTS_EXPLOSION_T);
};

void generate_hedge(float &HEDGE_GENERATE_PROBABILITY,
	std::list<Hedge*> &HEDGES, float GAME_TIME, sf::Clock &HEDGE_TIMER,
	sf::Texture &HEDGES_DEADCARS1, sf::Texture &HEDGES_DEADCARS2);
