#include "Hedge.h"

float Hedge::return_health() {
	return health;
}

bool generate_hedge(float &HEDGE_GENERATE_PROBABILITY,
	std::list<Hedge*> &HEDGES, float GAME_TIME, sf::Clock &HEDGE_TIMER,
	sf::Image IMAGE1, sf::Image IMAGE2) {
	if (HEDGE_GENERATE_PROBABILITY < 0) {
		int r = rand() % 2;
		switch (r) {
		case 0:
			HEDGES.push_back(new Hedge(IMAGE1,
				Race_enemy_spawn_x, Race_enemy_spawn_y,
				Race_hedges_deadcars1_width, Race_hedges_deadcars1_hight,
				DOWN, Race_hedges_deadcars1_health));
			break;
		case 1:
			HEDGES.push_back(new Hedge(IMAGE2,
				Race_enemy_spawn_x, Race_enemy_spawn_y,
				Race_hedges_deadcars2_width, Race_hedges_deadcars2_hight,
				DOWN, Race_hedges_deadcars2_health));
			break;
		}

		HEDGE_GENERATE_PROBABILITY = Race_game_difficulty - GAME_TIME * 25;
		if (HEDGE_GENERATE_PROBABILITY < Race_max_game_difficulty) {
			HEDGE_GENERATE_PROBABILITY = Race_max_game_difficulty;
		}
		HEDGE_TIMER.restart();
	}

	return false;
}

int Hedge::update(float time) {
	x += dx * time;
	y += dy * time;

	if (y - h / 2 > screen_hight + 300 || y + h / 2 < -300 || x - w / 2 > screen_width + 300 || x + w / 2 < -300) {
		life = false;
	}

	sprite.setPosition(x + w / 2, y + h / 2);

	return 0;
}