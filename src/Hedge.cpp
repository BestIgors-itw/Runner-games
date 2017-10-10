#include "Hedge.h"

#include "Player.h"
#include "Effect.h"

float Hedge::get_health() {
	return health;
}

int Hedge::update(float time) {
	x += dx * time;
	y += dy * time;

	if (y - h / 2 > screen_hight + 300 || y + h / 2 < -300 || x - w / 2 > screen_width + 300 || x + w / 2 < -300) {
		alive = false;
	}

	sprite.setPosition(x + w / 2, y + h / 2);

	return 0;
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

void player_collision_hedges(Player &PLAYER, std::list<Hedge*> &HEDGES,
	std::list<Effect*> &EFFECTS, sf::Image EFFECTS_EXPLOSION_i) {
	std::list<Hedge*>::iterator it1_hedges;
	for (it1_hedges = HEDGES.begin(); it1_hedges != HEDGES.end(); ++it1_hedges) {
		Hedge *e = *it1_hedges;
		if (e->get_rect().intersects(PLAYER.get_rect())) {
			e->kill_object();
			EFFECTS.push_back(new Effect(EFFECTS_EXPLOSION_i, Effects_spawn_x, Effects_spawn_y,
				effects_explosion2_width, effects_explosion2_hight,
				background_speed, DOWN, effects_explosion2_exist_time));

			PLAYER.change_health(-(e->get_health()));

			PLAYER.change_score(-5);
		}
	}
}