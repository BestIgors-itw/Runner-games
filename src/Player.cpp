#include "Player.h"

void Player::control() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		if (x + w < screen_width) {
			direction = RIGHT;
			sprite.setRotation(2.5);
		}
		else {
			direction = STAY;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		if (x > 0) {
			direction = LEFT;
			sprite.setRotation(-2.5);
		}
		else {
			direction = STAY;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		if (y + h < screen_height) {
			direction = DOWN;
		}
		else {
			direction = STAY;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		if (y > 0) {
			direction = UP;
		}
		else {
			direction = STAY;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
		&& sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		if (y > 0) {
			direction = UP;
			sprite.setRotation(0);
		}
		if (x > 0) {
			direction = LEFT;
			sprite.setRotation(-2.5);
		}
		if (x > 0 && y > 0) {
			direction = UP_LEFT;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
		&& sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		if (x + w < screen_width) {
			direction = RIGHT;
			sprite.setRotation(2.5);
		}
		if (y > 0) {
			direction = UP;
			sprite.setRotation(0);
		}
		if (x + w < screen_width && y > 0) {
			direction = UP_RIGHT;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
		&& sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		if (y + h < screen_height) {
			direction = DOWN;
			sprite.setRotation(0);
		}
		if (x + w < screen_width) {
			direction = RIGHT;
			sprite.setRotation(2.5);
		}
		if (x + w < screen_width && y + h < screen_height) {
			direction = DOWN_RIGHT;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
		&& sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		if (y + h < screen_height) {
			direction = DOWN;
			sprite.setRotation(0);
		}
		if (x > 0) {
			direction = LEFT;
			sprite.setRotation(-2.5);
		}
		if (x > 0 && y + h < screen_height) {
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

int Player::update(float TIME) {
	control();
	Direction_convert(direction, dx, dy, speed);
	x += dx * TIME;
	y += dy * TIME;

	sprite.setPosition(x + w / 2, y + h / 2);

	if (game_timer.getElapsedTime().asSeconds() - attack_frequency_time
		> time_between_attack) {
		shot_available = true;
		attack_frequency_time = game_timer.getElapsedTime().asSeconds();
	}

	if (health <= 0) {
		return 1;
	}
	return 0;
}

void Player::change_score(float VARIABLE) {
	score += VARIABLE;
	if (score < 0) {
		score = 0;
	}
}

float Player::return_score() {
	return score;
}
