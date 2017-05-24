#include "Enemies_Cars.h"

int Enemies_cars::update(float time) {
	if (game_timer.getElapsedTime().asSeconds() - moving_timer > 1) {
		if (direction == 2 || direction == 6 || direction == 7) {
			int r = rand() % 3;
			switch (r) {
			case 0:
				direction = 6;
				break;
			case 1:
				direction = 7;
				break;
			case 2:
				direction = 2;
				break;
			}
		}
		if (direction == 3 || direction == 4 || direction == 5) {
			int r = rand() % 3;
			switch (r) {
			case 0:
				direction = 4;
				break;
			case 1:
				direction = 5;
				break;
			case 2:
				direction = 3;
				break;
			}
		}

		moving_timer = game_timer.getElapsedTime().asSeconds();
	}
	if (x < 0 && (direction == 2 || direction == 6 || direction == 7)) {
		direction = 6;
	}
	if (x + w > screen_width && (direction == 2 || direction == 6 || direction == 7)) {
		direction = 7;
	}
	if (x < 0 && (direction == 3 || direction == 4 || direction == 5)) {
		direction = 5;
	}
	if (x + w > screen_width && (direction == 3 || direction == 4 || direction == 5)) {
		direction = 4;
	}

	if (y - h / 2 > screen_hight + 300 || y + h / 2 < -300) {
		life = false;
	}

	Direction_convert(direction, dx, dy, speed);
	x += dx * time;
	y += dy * time;
	sprite.setPosition(x + w / 2, y + h / 2);
	if (game_timer.getElapsedTime().asSeconds() - attack_frequency_timer > time_between_attack) {
		attack_frequency_timer = game_timer.getElapsedTime().asSeconds();
		return 1;
	}
	return 0;
}