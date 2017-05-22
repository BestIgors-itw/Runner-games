#include "Enemies.h"
#include "Entity.h"
#include <SFML/Graphics.hpp>

#define screen_width 1600
#define screen_hight 900

extern Clock clock1, game_timer, background_timer, enemy_timer;

using namespace sf;

	int Enemies::update(float time) {
		if (health <= 0) {
			life = false;
		}
		if (game_timer.getElapsedTime().asSeconds() - moving_timer > 1 || x + w / 2 > screen_width || x < -200) {
			int r = rand() % 2;
			switch (r) {
			case 0:
				direction = 0;
				break;
			case 1:
				direction = 1;
				break;
			}
			Direction_convert(direction, dx, dy, speed);
			moving_timer = game_timer.getElapsedTime().asSeconds();
		}
		x += dx * time;
		y += dy * time;
		sprite.setPosition(x, y);
		if (game_timer.getElapsedTime().asSeconds() - attack_frequency_timer > time_between_attack) {
			attack_frequency_timer = game_timer.getElapsedTime().asSeconds();
			return 1;
		}
		return 0;
	};