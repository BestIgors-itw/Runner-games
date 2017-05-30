#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Direction.h"

extern sf::Clock game_timer, moving_timer;

class Shooter_enemies_cars : public Entity {
public:
	float speed, health, moving_timer, attack_frequency_time, time_between_attack, damage;
	int direction;

	Shooter_enemies_cars(sf::Image &image, float X, float Y, int W, int H, float Speed,
		int Direction, float Health, float Time_between_attack, float Damage)
		:Entity(image, X, Y, W, H) {
		direction = Direction;
		speed = Speed;
		Direction_convert(direction, dx, dy, speed);

		health = Health;

		time_between_attack = Time_between_attack;
		damage = Damage;
		attack_frequency_time = game_timer.getElapsedTime().asSeconds();

		moving_timer = attack_frequency_time;

	};

	virtual ~Shooter_enemies_cars (){}

	int update(float time);
};