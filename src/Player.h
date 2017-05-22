#pragma once

#include "Entity.h"
#include <SFML/Graphics.hpp>

extern Clock clock1, game_timer, background_timer, enemy_timer;

class Player : public Entity {
public:
	float score, speed, attack_frequency_timer, time_between_attack;
	int health, direction, damage;
	bool shooting_available, shot;
	Player(Image &image, float X, float Y, int W, int H, float Speed,
		int Health, float Time_between_attack, int Damage) :
		Entity(image, X, Y, W, H),
		score(0.0), direction(8), shooting_available(true), shot(false) {
		health = Health;
		speed = Speed;
		time_between_attack = Time_between_attack;
		damage = Damage;
		attack_frequency_timer = game_timer.getElapsedTime().asSeconds();
	}

	void control();

	int update(float time);
};