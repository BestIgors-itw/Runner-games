#pragma once

#include <SFML/Graphics.hpp>
#include <list>
#include <sstream>
#include <ctime>
#include "Background.h"
#include "Direction.h"
#include "Effect.h"
#include "Shooter_enemies_car.h"
#include "Entity.h"
#include "Interface.h"
#include "Player.h"

extern sf::Clock game_timer, Compensating_for_performance_losses_timer, background_timer, enemy_timer;

int Shooter(sf::RenderWindow &WINDOW);

inline bool initializing(sf::Texture &aim_t,
	sf::Texture &background_rocksand1_t, sf::Texture &background_rocksand2_t,
	sf::Texture &background_rockgray1_t, sf::Texture &enemy_copsjups_t,
	sf::Texture &enemy_hammer_t, sf::Texture &enemy_lapdcar_t, sf::Texture &effects_explosion1_t,
	sf::Texture &effects_explosion2_t, sf::Texture &effects_shooting_t,
	sf::Texture &interface_plate_t);

inline void generate(std::list<Background*> &BACKGROUND_OBJECTS,
	std::list<Shooter_enemies_car*> &ENEMIES,
	float &BACKGROUND_OBJECT_GENERATE_PROBABILITY,
	float &ENEMY_GENERATE_PROBABILITY, char &ENEMY_NUMBER,
	sf::Texture &BACKGROUND_ROCKGRAY1_T, sf::Texture &BACKGROUND_ROCKSAND1_T,
	sf::Texture &BACKGROUND_ROCKSAND2_T, sf::Texture &ENEMY_COPSJUPS_T,
	sf::Texture &ENEMY_HAMMER_T, sf::Texture &ENEMY_LAPDCAR_T);

inline void objects_interact(Player &PLAYER,
	std::list<Shooter_enemies_car*> &ENEMIES, std::list<Effect*> &EFFECTS,
	char &ENEMY_NUMBER, sf::Texture &effects_shooting_t,
	sf::Texture &effects_explosion1_t, sf::Texture &effects_explosion2_t);

inline void garbage_collector(std::list<Background*> &BACKGROUND_OBJECTS,
	std::list<Shooter_enemies_car*> &ENEMIES, std::list<Effect*> &EFFECTS);

inline void update(sf::RenderWindow &WINDOW,
	std::list<Background*> &BACKGROUND_OBJECTS, std::list<Shooter_enemies_car*> &HEDGES,
	std::list<Effect*> &EFFECTS, Player &PLAYER);

inline void draw(sf::RenderWindow &WINDOW, sf::Sprite &BACKGROUND,
	std::list<Background*> &BACKGROUND_OBJECTS, std::list<Shooter_enemies_car*> &ENEMIES,
	std::list<Effect*> &EFFECTS, Player &PLAYER);