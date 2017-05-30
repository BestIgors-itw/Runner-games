#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Direction.h"

extern sf::Clock game_timer;

class Player : public Entity {
public:
	float score, speed, attack_frequency_time, time_between_attack;
	int health, damage;
	int direction;
	bool is_shot_available, is_shot;
	Player(sf::Image &image, float X, float Y, int W, int H, float Speed,
		int Health, float Time_between_attack, int Damage) :
		Entity(image, X, Y, W, H),
		score(0.0), direction(STAY), is_shot_available(true), is_shot(false) {
		health = Health;
		speed = Speed;

		time_between_attack = Time_between_attack;
		damage = Damage;
		attack_frequency_time = game_timer.getElapsedTime().asSeconds();
	}

	void control();

	virtual ~Player() {}

	int update(float time);

};