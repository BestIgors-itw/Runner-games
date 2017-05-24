#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Direction.h"

#define screen_width 1600
#define screen_hight 900

extern sf::Clock game_timer;

class Enemies_cars : public Entity {
public:
	float speed, direction, health, moving_timer, attack_frequency_time, time_between_attack;
	int damage;
	Enemies_cars(sf::Image &image, float X, float Y, int W, int H, float Speed,
		float Direction, float Health, float Time_between_attack, int Damage)
		:Entity(image, X, Y, W, H) {
		health = Health;

		time_between_attack = Time_between_attack;
		damage = Damage;
		attack_frequency_time = game_timer.getElapsedTime().asSeconds();
		moving_timer = attack_frequency_time;

		direction = Direction;
		speed = Speed;
		Direction_convert(direction, dx, dy, speed);

		if (direction == 2) {
			sprite.setScale(1, -1);
		}
	}

	int update(float time);
};
