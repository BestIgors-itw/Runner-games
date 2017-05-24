#include "Shooter_enemies_cars.h"

#define screen_width 1600
#define screen_hight 900

int Shooter_enemies_cars::update(float time) {
	if (game_timer.getElapsedTime().asSeconds() - moving_timer > 2) {
		if (direction == 1 || direction == 5 || direction == 6) {
			int r = rand() % 3;
			switch (r) {
			case 0:
				direction = 1;
				break;
			case 1:
				direction = 5;
				break;
			case 2:
				direction = 6;
				break;
			}
		}
		if (direction == 1 || direction == 4 || direction == 7) {
			int r = rand() % 3;
			switch (r) {
			case 0:
				direction = 1;
				break;
			case 1:
				direction = 4;
				break;
			case 2:
				direction = 7;
				break;
			}
		}

		moving_timer = game_timer.getElapsedTime().asSeconds();
	}
	if (y + h > screen_hight && (direction == 2 || direction == 5 || direction == 6)) {
		direction = 5;
	}
	if (y < screen_hight - 400 && (direction == 2 || direction == 5 || direction == 6)) {
		direction = 6;
	}
	if (y + h > screen_hight && (direction == 1 || direction == 4 || direction == 7)) {
		direction = 4;
	}
	if (y < screen_hight - 400 && (direction == 1 || direction == 4 || direction == 7)) {
		direction = 7;
	}

	if (x < 0) {
		direction = 0;
	}
	if (x + w > screen_width) {
		direction = 1;
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