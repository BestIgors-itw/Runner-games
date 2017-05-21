#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.h"

extern sf::Clock clock1, game_timer, background_timer;

class Player : public Entity {
public:
	float score, speed, attack_frequency_timer, time_between_attack;
	int health, damage;
	enum { RIGHT, LEFT, DOWN, UP, UP_LEFT, UP_RIGHT, DOWN_RIGHT, DOWN_LEFT, STAY } direction;
	bool shooting_available, is_shot;
	Player(sf::Image &image, float X, float Y, int W, int H, float Speed,
		int Health, float Time_between_attack, int Damage) :
		Entity(image, X, Y, W, H),
		score(0.0), direction(STAY), shooting_available(true), is_shot(false) {
		health = Health;
		speed = Speed;

		time_between_attack = Time_between_attack;
		damage = Damage;
		attack_frequency_timer = game_timer.getElapsedTime().asSeconds();
	}

	void control();

	int update(float time);

};