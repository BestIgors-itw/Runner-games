#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Direction.h"

#define screen_width 1600
#define screen_hight 900

extern sf::Clock game_timer;

class Enemies : public Entity {
public:
	float speed, direction, health, moving_timer, attack_frequency_timer;
	float time_between_attack, damage;
	Enemies(sf::Image &image, float X, float Y, int W, int H,
		float Direction, float Health)
		:Entity(image, X, Y, W, H) {
		health = Health;

		/*damage = Damage;
		time_between_attack = Time_between_attack;
		attack_frequency_timer = game_timer.getElapsedTime().asSeconds();
		moving_timer = attack_frequency_timer;*/

		/*direction = Direction;
		speed = Speed;
		Direction_convert(direction, dx, dy, speed);*/

		/*if (direction == 2) {
			sprite.setScale(1, -1);
		}*/
	}

	int update(float time);
};
