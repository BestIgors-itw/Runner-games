#include "Hedge.h"

#include "Player.h"
#include "Effect.h"

float Hedge::get_health() {
	return health;
}

int Hedge::update(float time) {
	x += dx * time;
	y += dy * time;

	if (y - h / 2 > screen_height + 300 || y + h / 2 < -300 || x - w / 2
		> screen_width + 300 || x + w / 2 < -300) {
		alive = false;
	}

	sprite.setPosition(x + w / 2, y + h / 2);

	return 0;
}

void generate_hedge(float &HEDGE_GENERATE_PROBABILITY,
	std::list<Hedge*> &HEDGES, float GAME_TIME, sf::Clock &HEDGE_TIMER,
	sf::Texture &HEDGES_DEADCARS1, sf::Texture &HEDGES_DEADCARS2) {
	if (HEDGE_GENERATE_PROBABILITY < 0) {
		int r = rand() % 2;
		switch (r) {
		case 0:
			HEDGES.push_back(new Hedge(HEDGES_DEADCARS1,
				Race_enemy_spawn_x, Race_enemy_spawn_y,
				DOWN, Race_hedges_deadcars1_health));
			break;
		case 1:
			HEDGES.push_back(new Hedge(HEDGES_DEADCARS2,
				Race_enemy_spawn_x, Race_enemy_spawn_y,
				DOWN, Race_hedges_deadcars2_health));
			break;
		}

		HEDGE_GENERATE_PROBABILITY = Race_game_difficulty - GAME_TIME * 25;
		if (HEDGE_GENERATE_PROBABILITY < Race_max_game_difficulty) {
			HEDGE_GENERATE_PROBABILITY = Race_max_game_difficulty;
		}
		HEDGE_TIMER.restart();
	}
}

void player_collision_hedges(Player &PLAYER, std::list<Hedge*> &HEDGES,
	std::list<Effect*> &EFFECTS, sf::Texture &EFFECTS_EXPLOSION_T) {
	for (std::list<Hedge*>::iterator it_hedges = HEDGES.begin(); it_hedges
		!= HEDGES.end(); ++it_hedges) {
		if ((*it_hedges)->get_rect().intersects(PLAYER.get_rect())) {
			(*it_hedges)->alive = false;
			EFFECTS.push_back(new Effect(EFFECTS_EXPLOSION_T,
				(*it_hedges)->get_x() + (*it_hedges)->get_w() / 2,
				(*it_hedges)->get_y() + (*it_hedges)->get_h() / 2,
				background_speed, DOWN, effects_explosion2_exist_time));

			PLAYER.change_health(-((*it_hedges)->health));

			PLAYER.change_score(-5);
		}
	}
}

void hedges_garbage_collector(std::list<Hedge*> &HEDGES) {
	for (std::list<Hedge*>::iterator it1_hedges = HEDGES.begin(); it1_hedges
		!= HEDGES.end(); ) {
		if ((*it1_hedges)->alive == false) {
			it1_hedges = HEDGES.erase(it1_hedges);
		}
		else {
			++it1_hedges;
		}
	}
}