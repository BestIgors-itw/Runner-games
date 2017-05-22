#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Direction.h"

using namespace sf;
extern Clock clock1, game_timer, background_timer, enemy_timer;

class Enemies : public Entity {
public:
	float speed, direction, health, moving_timer, attack_frequency_timer, time_between_attack;
	int damage;

	Enemies::Enemies(Image &image, float X, float Y, int W, int H, float Speed,
		float Direction, float Health, float Time_between_attack, int Damage)
		:Entity(image, X, Y, W, H) {
		direction = Direction;
		speed = Speed;
		Direction_convert(direction, dx, dy, speed);
		health = Health;
		time_between_attack = Time_between_attack;
		damage = Damage;
		attack_frequency_timer = game_timer.getElapsedTime().asSeconds();
		moving_timer = attack_frequency_timer;
	};

	int update(float time);
};