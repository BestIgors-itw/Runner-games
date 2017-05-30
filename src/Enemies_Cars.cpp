#include "Enemies_Cars.h"

int Enemies_cars::update(float time) {
	if (game_timer.getElapsedTime().asSeconds() - moving_timer > 1) {
		if (direction == DOWN || direction == DOWN_LEFT || direction == DOWN_RIGHT) {
			int r = rand() % 3;
			switch (r) {
			case 0:
				direction = DOWN_RIGHT;
				break;
			case 1:
				direction = DOWN_LEFT;
				break;
			case 2:
				direction = DOWN;
				break;
			}
		}
		if (direction == UP || direction == UP_LEFT || direction == UP_RIGHT) {
			int r = rand() % 3;
			switch (r) {
			case 0:
				direction = UP_LEFT;
				break;
			case 1:
				direction = UP_RIGHT;
				break;
			case 2:
				direction = UP;
				break;
			}
		}

		moving_timer = game_timer.getElapsedTime().asSeconds();
	}
	if (x < 0 && (direction == DOWN || direction == DOWN_LEFT)) {
		direction = DOWN_RIGHT;
	}
	if (x + w > screen_width && (direction == DOWN || direction == DOWN_RIGHT)) {
		direction = DOWN_LEFT;
	}
	if (x < 0 && (direction == UP || direction == UP_RIGHT)) {
		direction = UP_RIGHT;
	}
	if (x + w > screen_width && (direction == UP || direction == UP_RIGHT)) {
		direction = UP_LEFT;
	}

	if (y - h / 2 > screen_hight + 300 || y + h / 2 < -300) {
		life = false;
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