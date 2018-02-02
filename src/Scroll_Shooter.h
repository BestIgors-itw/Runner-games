#pragma once

#include <SFML/Graphics.hpp>
#include <list>
#include <sstream>
#include <ctime>
#include "Background.h"
#include "Bullet.h"
#include "Direction.h"
#include "Effect.h"
#include "Scroll_Shooter_Enemies_Car.h"
#include "Entity.h"
#include "Interface.h"
#include "Player.h"

extern sf::Clock game_timer, Compensating_for_performance_losses_timer, background_timer, enemy_timer;

int Scroll_Shooter(sf::RenderWindow &WINDOW);

inline bool initializing(sf::Texture &PLAYER_T,
	sf::Texture &BACKGROUND_ROCKSAND1_T, sf::Texture &BACKGROUND_ROCKSAND2_T,
	sf::Texture &BACKGROUND_ROCKGRAY1_T, sf::Texture &ENEMY_BATTLEMULE_T,
	sf::Texture &ENEMY_IMPALABATTLE_T, sf::Texture &ENEMY_SLAGE_T,
	sf::Texture &EFFECTS_EXPLOSION1_T, sf::Texture &EFFECTS_EXPLOSION2_T,
	sf::Texture &EFFECTS_SHOOTING_T, sf::Texture &BULLET_T,
	sf::Texture &INTERFACE_PLATE_T);

inline void generate(std::list<Background*> &BACKGROUND_OBJECTS,
	std::list<Scroll_Shooter_enemies_car*> &ENEMIES,
	float &BACKGROUND_OBJECT_GENERATE_PROBABILITY,
	float &ENEMY_GENERATE_PROBABILITY,
	sf::Texture &BACKGROUND_ROCKGRAY1_T, sf::Texture &BACKGROUND_ROCKSAND1_T,
	sf::Texture &BACKGROUND_ROCKSAND2_T, sf::Texture &ENEMY_BATTLEMULE_T,
	sf::Texture &ENEMY_IMPALABATTLE_T, sf::Texture &ENEMY_SLAGE_T);

inline void objects_interact(Player &PLAYER,
	std::list<Scroll_Shooter_enemies_car*> &ENEMIES,
	std::list<Bullet*> &BULLETS, std::list<Effect*> &EFFECTS,
	sf::Texture &EFFECTS_SHOOTING_T, sf::Texture &EFFECTS_EXPLOSION1_T,
	sf::Texture &EFFECTS_EXPLOSION2_T);

inline void garbage_collector(std::list<Background*> &BACKGROUND_OBJECTS,
	std::list<Scroll_Shooter_enemies_car*> &ENEMIES,
	std::list<Bullet*> &BULLETS, std::list<Effect*> &EFFECTS);

inline void update(sf::RenderWindow &WINDOW,
	std::list<Background*> &BACKGROUND_OBJECTS,
	std::list<Scroll_Shooter_enemies_car*> &ENEMIES,
	std::list<Bullet*> &BULLETS, std::list<Effect*> &EFFECTS, Player &PLAYER,
	sf::Texture &EFFECTS_SHOOTING_T, sf::Texture &BULLET_T);

inline void draw(sf::RenderWindow &WINDOW, sf::Sprite &BACKGROUND,
	std::list<Background*> &BACKGROUND_OBJECTS,
	std::list<Scroll_Shooter_enemies_car*> &ENEMIES, std::list<Effect*> &EFFECTS,
	std::list<Bullet*> &BULLETS, Player &PLAYER);