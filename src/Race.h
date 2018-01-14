#pragma once

#include <SFML/Graphics.hpp>
#include <list>
#include <sstream>
#include <ctime>
#include "Background.h"
#include "Bullet.h"
#include "Direction.h"
#include "Effect.h"
#include "Hedge.h"
#include "Entity.h"
#include "Interface.h"
#include "Player.h"

extern sf::Clock game_timer, Compensating_for_performance_losses_timer, background_timer, hedge_timer;

int Race(sf::RenderWindow &WINDOW);

inline bool initializing(sf::Texture &player_t,
	sf::Texture &background_rocksand1_t, sf::Texture &background_rocksand2_t,
	sf::Texture &background_rockgray1_t, sf::Texture &hedges_deadcars1_t,
	sf::Texture &hedges_deadcars2_t, sf::Texture &effects_explosion2_t,
	sf::Texture &plate_t);

inline void generate(std::list<Background*> &BACKGROUND_OBJECTS,
	std::list<Hedge*> &HEDGES, float &BACKGROUND_OBJECT_GENERATE_PROBABILITY,
	float &HEDGE_GENERATE_PROBABILITY, sf::Texture &BACKGROUND_ROCKGRAY1_I,
	sf::Texture &BACKGROUND_ROCKSAND1_I, sf::Texture &BACKGROUND_ROCKSAND2_I,
	sf::Texture &HEDGES_DEADCARS1_I, sf::Texture &HEDGES_DEADCARS2_I);

inline void garbage_collector(std::list<Background*> &BACKGROUND_OBJECTS,
	std::list<Hedge*> &HEDGES, std::list<Effect*> &EFFECTS);

inline void update(sf::RenderWindow &WINDOW,
	std::list<Background*> &BACKGROUND_OBJECTS, std::list<Hedge*> &HEDGES,
	std::list<Effect*> &EFFECTS, Player &PLAYER);

inline void draw(sf::RenderWindow &WINDOW, sf::Sprite &BACKGROUND,
	std::list<Background*> &BACKGROUND_OBJECTS, std::list<Hedge*> &HEDGES,
	std::list<Effect*> &EFFECTS, Player &PLAYER);