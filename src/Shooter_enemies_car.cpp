#include "Shooter_enemies_car.h"

#define screen_width 1600
#define screen_hight 900

int Shooter_enemies_cars::update(float time) {
	if (game_timer.getElapsedTime().asSeconds() - moving_timer > 2) {
		if (direction == RIGHT || direction == UP_RIGHT || direction == DOWN_RIGHT) {
			int r = rand() % 3;
			switch (r) {
			case 0:
				direction = RIGHT;
				break;
			case 1:
				direction = UP_RIGHT;
				break;
			case 2:
				direction = DOWN_RIGHT;
				break;
			}
		}
		if (direction == LEFT || direction == UP_LEFT || direction == DOWN_LEFT) {
			int r = rand() % 3;
			switch (r) {
			case 0:
				direction = LEFT;
				break;
			case 1:
				direction = UP_LEFT;
				break;
			case 2:
				direction = DOWN_LEFT;
				break;
			}
		}

		moving_timer = game_timer.getElapsedTime().asSeconds();
	}
	if (y + h > screen_hight && (direction == RIGHT || direction == DOWN_RIGHT)) {
		direction = UP_RIGHT;
	}
	if (y < screen_hight - 400 && (direction == RIGHT || direction == UP_RIGHT)) {
		direction = DOWN_RIGHT;
	}
	if (y + h > screen_hight && (direction == LEFT || direction == DOWN_LEFT)) {
		direction = UP_LEFT;
	}
	if (y < screen_hight - 400 && (direction == LEFT || direction == UP_LEFT)) {
		direction = DOWN_LEFT;
	}

	if (x < 0) {
		direction = RIGHT;
	}
	if (x + w > screen_width) {
		direction = LEFT;
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