#include "Shooter_enemies_car.h"

#define screen_width 1600
#define screen_height 900

int Shooter_enemies_car::update(float time) {
	if (game_timer.getElapsedTime().asSeconds() - moving_timer > 2) {
		if (direction == RIGHT || direction == UP_RIGHT
			|| direction == DOWN_RIGHT) {
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
		if (direction == LEFT || direction == UP_LEFT
			|| direction == DOWN_LEFT) {
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
	if (y + h > screen_height && (direction == RIGHT
		|| direction == DOWN_RIGHT)) {
		direction = UP_RIGHT;
	}
	if (y < screen_height - 400 && (direction == RIGHT
		|| direction == UP_RIGHT)) {
		direction = DOWN_RIGHT;
	}
	if (y + h > screen_height && (direction == LEFT
		|| direction == DOWN_LEFT)) {
		direction = UP_LEFT;
	}
	if (y < screen_height - 400 && (direction == LEFT
		|| direction == UP_LEFT)) {
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

	if (game_timer.getElapsedTime().asSeconds() - attack_frequency_time
		> time_between_attack) {
		attack_frequency_time = game_timer.getElapsedTime().asSeconds();

		return 1;
	}

	return 0;
}

void shooter_enemies_car_generate(float &GENERATE_PROBABILITY,
	char &ENEMY_NUMBER, std::list<Shooter_enemies_car*> &ENEMIES,
	float GAME_TIME, sf::Clock &TIMER, sf::Texture &ENEMY_COPSJUPS_T,
	sf::Texture &ENEMY_HAMMER_T, sf::Texture &ENEMY_LAPDCAR_T) {

	if (GENERATE_PROBABILITY < 0 && ENEMY_NUMBER < 7) {
		++ENEMY_NUMBER;

		int r = rand() % 3;
		switch (r) {
		case 0:
			ENEMIES.push_back(new Shooter_enemies_car(ENEMY_COPSJUPS_T,
				Shooter_enemy_spawn_x, Shooter_enemy_spawn_y,
				Shooter_enemy_copsjups_speed, RIGHT,
				Shooter_enemy_copsjups_health,
				Shooter_enemy_copsjups_time_between_attack,
				Shooter_enemy_copsjups_damage));
			break;
		case 1:
			ENEMIES.push_back(new Shooter_enemies_car(ENEMY_HAMMER_T,
				Shooter_enemy_spawn_x, Shooter_enemy_spawn_y,
				Shooter_enemy_hammer_speed, RIGHT,
				Shooter_enemy_hammer_health,
				Shooter_enemy_hammer_time_between_attack,
				Shooter_enemy_hammer_damage));
			break;
		case 2:
			ENEMIES.push_back(new Shooter_enemies_car(ENEMY_LAPDCAR_T,
				Shooter_enemy_spawn_x, Shooter_enemy_spawn_y,
				Shooter_enemy_lapdcar_speed, RIGHT,
				Shooter_enemy_lapdcar_health,
				Shooter_enemy_lapdcar_time_between_attack,
				Shooter_enemy_lapdcar_damage));
			break;
		}

		GENERATE_PROBABILITY = Shooter_game_difficulty - GAME_TIME * 25;

		if (GENERATE_PROBABILITY < Shooter_max_game_difficulty) {
			GENERATE_PROBABILITY = Shooter_max_game_difficulty;
		}
		TIMER.restart();
	}
}

void shooter_enemies_car_garbage_collector(std::list<Shooter_enemies_car*> &ENEMIES) {
	for (std::list<Shooter_enemies_car*>::iterator it_enemies
		= ENEMIES.begin(); it_enemies != ENEMIES.end(); ) {
		if ((*it_enemies)->is_alive() == false) {
			it_enemies = ENEMIES.erase(it_enemies);
		}
		else {
			++it_enemies;
		}
	}
}