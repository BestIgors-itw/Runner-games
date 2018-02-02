#include "Scroll_Shooter_Enemies_Car.h"

int Scroll_Shooter_enemies_car::update(float TIME) {
	if (game_timer.getElapsedTime().asSeconds() - moving_timer > 1) {
		if (direction == DOWN || direction == DOWN_LEFT
			|| direction == DOWN_RIGHT) {
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
	if (x + w > screen_width && (direction == DOWN
		|| direction == DOWN_RIGHT)) {
		direction = DOWN_LEFT;
	}
	if (x < 0 && (direction == UP || direction == UP_LEFT)) {
		direction = UP_RIGHT;
	}
	if (x + w > screen_width && (direction == UP || direction == UP_RIGHT)) {
		direction = UP_LEFT;
	}

	if (y - h / 2 > screen_height + 300 || y + h / 2 < -300) {
		alive = false;
	}

	Direction_convert(direction, dx, dy, speed);
	x += dx * TIME;
	y += dy * TIME;
	sprite.setPosition(x + w / 2, y + h / 2);

	if (game_timer.getElapsedTime().asSeconds() - attack_frequency_time
	> time_between_attack) {
		attack_frequency_time = game_timer.getElapsedTime().asSeconds();

		return 1;
	}

	return 0;
}

void scroll_shooter_enemies_car_generate
(float &ENEMY_GENERATE_PROBABILITY,
	std::list<Scroll_Shooter_enemies_car*> &ENEMIES, float GAME_TIME,
	sf::Clock &ENEMY_TIMER, sf::Texture &ENEMY_BATTLEMULE_T,
	sf::Texture &ENEMY_IMPALABATTLE_T, sf::Texture &ENEMY_SLAGE_T) {

	if (ENEMY_GENERATE_PROBABILITY < 0) {
		int r = rand() % 8;
		switch (r) {
		case 0:
			ENEMIES.push_back(new Scroll_Shooter_enemies_car
			(ENEMY_BATTLEMULE_T, Scroll_Shooter_enemy_up_spawn_x,
				Scroll_Shooter_enemy_up_spawn_y,
				Scroll_Shooter_enemy_battlemule_speed,
				DOWN, Scroll_Shooter_enemy_battlemule_health,
				Scroll_Shooter_enemy_battlemule_time_between_attack,
				Scroll_Shooter_enemy_battlemule_damage));
			break;
		case 1:
			ENEMIES.push_back(new Scroll_Shooter_enemies_car
			(ENEMY_IMPALABATTLE_T, Scroll_Shooter_enemy_up_spawn_x,
				Scroll_Shooter_enemy_up_spawn_y,
				Scroll_Shooter_enemy_impalabattle_speed,
				DOWN, Scroll_Shooter_enemy_impalabattle_health,
				Scroll_Shooter_enemy_impalabattle_time_between_attack,
				Scroll_Shooter_enemy_impalabattle_damage));
			break;
		case 2:
			ENEMIES.push_back(new Scroll_Shooter_enemies_car(ENEMY_SLAGE_T,
				Scroll_Shooter_enemy_up_spawn_x,
				Scroll_Shooter_enemy_up_spawn_y,
				Scroll_Shooter_enemy_slage_speed,
				DOWN, Scroll_Shooter_enemy_slage_health,
				Scroll_Shooter_enemy_slage_time_between_attack,
				Scroll_Shooter_enemy_slage_damage));
			break;
		case 3:
			ENEMIES.push_back(new Scroll_Shooter_enemies_car
			(ENEMY_BATTLEMULE_T, Scroll_Shooter_enemy_down_spawn_x,
				Scroll_Shooter_enemy_down_spawn_y,
				Scroll_Shooter_enemy_battlemule_speed,
				UP, Scroll_Shooter_enemy_battlemule_health,
				Scroll_Shooter_enemy_battlemule_time_between_attack,
				Scroll_Shooter_enemy_battlemule_damage));
			break;
		case 4:
			ENEMIES.push_back(new Scroll_Shooter_enemies_car
			(ENEMY_IMPALABATTLE_T, Scroll_Shooter_enemy_down_spawn_x,
				Scroll_Shooter_enemy_down_spawn_y,
				Scroll_Shooter_enemy_impalabattle_speed,
				UP, Scroll_Shooter_enemy_impalabattle_health,
				Scroll_Shooter_enemy_impalabattle_time_between_attack,
				Scroll_Shooter_enemy_impalabattle_damage));
			break;
		case 5:
			ENEMIES.push_back(new Scroll_Shooter_enemies_car(ENEMY_SLAGE_T,
				Scroll_Shooter_enemy_down_spawn_x,
				Scroll_Shooter_enemy_down_spawn_y,
				Scroll_Shooter_enemy_slage_speed,
				UP, Scroll_Shooter_enemy_slage_health,
				Scroll_Shooter_enemy_slage_time_between_attack,
				Scroll_Shooter_enemy_slage_damage));
			break;
		}
		ENEMY_GENERATE_PROBABILITY = Scroll_Shooter_game_difficulty
			- GAME_TIME * 25;
		if (ENEMY_GENERATE_PROBABILITY < Scroll_Shooter_max_game_difficulty) {
			ENEMY_GENERATE_PROBABILITY = Scroll_Shooter_max_game_difficulty;
		}
		ENEMY_TIMER.restart();
	}
}

void scroll_shooter_enemies_car_garbage_collector
(std::list<Scroll_Shooter_enemies_car*> &ENEMIES) {
	for (std::list<Scroll_Shooter_enemies_car*>::iterator it_enemies
		= ENEMIES.begin(); it_enemies
		!= ENEMIES.end(); ) {
		if ((*it_enemies)->alive == false) {
			it_enemies = ENEMIES.erase(it_enemies);
		}
		else {
			++it_enemies;
		}
	}
}
