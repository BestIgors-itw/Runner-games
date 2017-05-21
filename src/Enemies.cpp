#include "Entity.h"
#include "Enemies.h"
#include "Direction.h"

#define screen_width 1600
#define screen_hight 900

int Enemies::update(float time) {
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

	if (y - h / 2 > screen_hight + 200 || y + h / 2 < -200) {
		life = false;
	}

	Direction_convert(direction, dx, dy, speed);
	x += dx * time;
	y += dy * time;
	sprite.setPosition(x + w / 2, y + h / 2);

	return 0;
}