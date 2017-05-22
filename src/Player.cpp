#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Entity.h"
#include "Direction.h"

#define screen_width 1600
#define screen_hight 900

extern Clock clock1, game_timer, background_timer, enemy_timer;

using namespace sf;

	void Player::control() {
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			if (x + w / 2 < screen_width) {
				direction = 0;
			}
			else {
				direction = 8;
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			if (x - w / 2 > 0) {
				direction = 1;
			}
			else {
				direction = 8;
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			if (y < screen_hight) {
				direction = 2;
			}
			else {
				direction = 8;
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			if (y - h / 2 > 0) {
				direction = 3;
			}
			else {
				direction = 8;
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Up)
			&& Keyboard::isKeyPressed(Keyboard::Left)) {
			if (y - h / 2 > 0) {
				direction = 3;
			}
			if (x - w / 2 > 0) {
				direction = 1;
			}
			if (x - w / 2 > 0 && y - h / 2 > 0) {
				direction = 4;
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Up)
			&& Keyboard::isKeyPressed(Keyboard::Right)) {
			if (x + w / 2 < screen_width) {
				direction = 0;
			}
			if (y - h / 2 > 0) {
				direction = 3;
			}
			if (x + w / 2 < screen_width && y - h / 2 > 0) {
				direction = 5;
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Down)
			&& Keyboard::isKeyPressed(Keyboard::Right)) {
			if (y < screen_hight) {
				direction = 2;
			}
			if (x + w / 2 < screen_width) {
				direction = 0;
			}
			if (x + w / 2 < screen_width && y < screen_hight) {
				direction = 6;
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Down)
			&& Keyboard::isKeyPressed(Keyboard::Left)) {
			if (y < screen_hight) {
				direction = 2;
			}
			if (x - w / 2 > 0) {
				direction = 1;
			}
			if (x - w / 2 > 0 && y < screen_hight) {
				direction = 7;
			}
		}

		if (!(Keyboard::isKeyPressed(Keyboard::Right))
			&& !(Keyboard::isKeyPressed(Keyboard::Left))
			&& !(Keyboard::isKeyPressed(Keyboard::Up))
			&& !(Keyboard::isKeyPressed(Keyboard::Down))) {
			direction = 8;
		}
	}

	int Player::update(float time) {
		control();
		Direction_convert(direction, dx, dy, speed);
		x += dx * time;
		y += dy * time;

		sprite.setPosition(x, y);

		if (game_timer.getElapsedTime().asSeconds() - attack_frequency_timer > time_between_attack) {
			shooting_available = true;
		}
		if (health <= 0) {
			return 1;
		}
		return 0;
	}