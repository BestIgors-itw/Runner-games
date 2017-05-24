#include "Player.h"

void Player::control() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		if (x + w / 2 < screen_width) {
			direction = RIGHT;
			sprite.setRotation(2.5);
		}
		else {
			direction = STAY;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		if (x - w / 2 > 0) {
			direction = LEFT;
			sprite.setRotation(-2.5);
		}
		else {
			direction = STAY;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		if (y + h / 2 < screen_hight) {
			direction = DOWN;
		}
		else {
			direction = STAY;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		if (y - h / 2 > 0) {
			direction = UP;
		}
		else {
			direction = STAY;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
		&& sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		if (y - h / 2 > 0) {
			direction = UP;
			sprite.setRotation(0);
		}
		if (x - w / 2 > 0) {
			direction = LEFT;
			sprite.setRotation(-2.5);
		}
		if (x - w / 2 > 0 && y - h / 2 > 0) {
			direction = UP_LEFT;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
		&& sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		if (x + w / 2 < screen_width) {
			direction = RIGHT;
			sprite.setRotation(2.5);
		}
		if (y - h / 2 > 0) {
			direction = UP;
			sprite.setRotation(0);
		}
		if (x + w / 2 < screen_width && y - h / 2 > 0) {
			direction = UP_RIGHT;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
		&& sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		if (y + h / 2 < screen_hight) {
			direction = DOWN;
			sprite.setRotation(0);
		}
		if (x + w / 2 < screen_width) {
			direction = RIGHT;
			sprite.setRotation(2.5);
		}
		if (x + w / 2 < screen_width && y + h < screen_hight) {
			direction = DOWN_RIGHT;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
		&& sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		if (y + h / 2 < screen_hight) {
			direction = DOWN;
			sprite.setRotation(0);
		}
		if (x - w / 2 > 0) {
			direction = LEFT;
			sprite.setRotation(-2.5);
		}
		if (x - w / 2 > 0 && y + h < screen_hight) {
			direction = DOWN_LEFT;
		}
	}

	if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		&& !(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		&& !(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		&& !(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))) {
		direction = STAY;
		sprite.setRotation(0);
	}
}

int Player::update(float time) {
	control();
	Direction_convert(direction, dx, dy, speed);
	x += dx * time;
	y += dy * time;

	sprite.setPosition(x, y);

	if (game_timer.getElapsedTime().asSeconds() - attack_frequency_time > time_between_attack) {
		is_shot_available = true;
		attack_frequency_time = game_timer.getElapsedTime().asSeconds();
	}

	if (health <= 0) {
		return 1;
	}
	return 0;
}