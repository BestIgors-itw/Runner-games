#include "Unit.h"

int Unit::update(float time) {
	if (x < 0 && (direction == DOWN || direction == DOWN_LEFT)) {
		direction = DOWN_RIGHT;
	}
	if (x + w > screen_width && (direction == DOWN || direction == DOWN_RIGHT)) {
		direction = DOWN_LEFT;
	}
	if (x < 0 && (direction == UP || direction == UP_LEFT)) {
		direction = UP_RIGHT;
	}
	if (x + w > screen_width && (direction == UP || direction == UP_RIGHT)) {
		direction = UP_LEFT;
	}

	if (y + h > screen_hight && (direction == RIGHT || direction == DOWN_RIGHT)) {
		direction = UP_RIGHT;
	}
	if (y < screen_hight && (direction == RIGHT || direction == UP_RIGHT)) {
		direction = DOWN_RIGHT;
	}
	if (y + h > screen_hight && (direction == LEFT || direction == DOWN_LEFT)) {
		direction = UP_LEFT;
	}
	if (y < screen_hight && (direction == LEFT || direction == UP_LEFT)) {
		direction = DOWN_LEFT;
	}

	Direction_convert(direction, dx, dy, speed);
	x += dx * time;
	y += dy * time;
	sprite.setPosition(x + w / 2, y + h / 2);

	if (game_timer.getElapsedTime().asSeconds() - attack_frequency_time > time_between_attack) {
		attack_frequency_time = game_timer.getElapsedTime().asSeconds();
		return 1;
	}
	return 0;
}

void Unit::change_health(float VARIABLE) {
	health += VARIABLE;
	if (health < 0) {
		health = 0;
	}
}

int Unit::get_health() {
	return health;
}

int Unit::return_damage() {
	return damage;
}

void Unit::shoot() {
	shot_available = false;
	attack_frequency_time = game_timer.getElapsedTime().asSeconds();
}

bool Unit::is_shot_available() {
	return shot_available;
}
