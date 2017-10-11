#include "Race.h"

int Race(sf::RenderWindow & window) {
	sf::Image player_i;
	if (!player_i.loadFromFile("res/images/unit/chevroletbattle.png")) {
		return 0;
	}

	sf::Image background_rocksand1_i;
	if (!background_rocksand1_i.loadFromFile
		("res/images/background/rocksand1.png")) {

		return 0;
	}

	sf::Image background_rocksand2_i;
	if (!background_rocksand2_i.loadFromFile
		("res/images/background/rocksand2.png")) {

		return 0;
	}

	sf::Image background_rockgray1_i;
	if (!background_rockgray1_i.loadFromFile
		("res/images/background/rockgray1.png")) {

		return 0;
	}

	sf::Image hedges_deadcars1_i;
	if (!hedges_deadcars1_i.loadFromFile("res/images/hedges/deadcars1.png")) {
		return 0;
	}

	sf::Image hedges_deadcars2_i;
	if (!hedges_deadcars2_i.loadFromFile("res/images/hedges/deadcars2.png")) {
		return 0;
	}

	sf::Image effects_explosion2_i;
	if (!effects_explosion2_i.loadFromFile
		("res/images/effects/explosion2.png")) {

		return 0;
	}

	sf::Image background_i;
	if (!background_i.loadFromFile
		("res/images/background/sandbackground.png")) {
		return 0;
	}
	sf::Texture background_t;
	background_t.loadFromImage(background_i);

	sf::Sprite background_s;
	background_s.setTexture(background_t);
	background_s.setScale(Race_background_scale_x, Race_background_scale_y);

	sf::Image plate_i;
	plate_i.loadFromFile("res/images/interface/button.png");

	sf::Font font;
	font.loadFromFile("res/font/beer_money.ttf");
	sf::Text text("", font, 50);
	text.setColor(sf::Color::Black);


	Player player(player_i, player_spawn_x, player_spawn_y, player_speed,
		player_spawn_health, Scroll_Shooter_player_time_between_shots,
		Scroll_Shooter_player_damage_per_shot);
	Interface interface_health_and_score_bar(plate_i, interface_plate_x,
		interface_plate_y, text);

	std::list<Background*> background_objects;
	std::list<Background*>::iterator it_background;

	std::list<Effect*> effects;
	std::list<Effect*>::iterator it_effects;

	std::list<Hedge*> hedges;
	std::list<Hedge*>::iterator it1_hedges, it2_hedges;

	srand(time(NULL));

	float game_time = game_timer.getElapsedTime().asSeconds();
	float score_time = game_time;

	float hedge_generate_probability = Race_game_difficulty;
	float hedge_time;

	float background_object_generate_probability
		= Race_background_object_probability;
	float background_time;

	float Compensating_for_performance_losses_time;

	while (window.isOpen()) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			break;
		}

		Compensating_for_performance_losses_time
			= Compensating_for_performance_losses_timer.getElapsedTime()
			.asMicroseconds();

		Compensating_for_performance_losses_timer.restart();

		Compensating_for_performance_losses_time
			= Compensating_for_performance_losses_coefficient;

		game_time = game_timer.getElapsedTime().asSeconds();

		player.change_score(game_time - score_time);
		score_time = game_time;

		background_time = background_timer.getElapsedTime().asSeconds();

		background_object_generate_probability
			= background_object_generate_probability - background_time * 100
			- rand() % 100;

		generate_background_objects(DOWN, Race_background_object_spawn_x,
			Race_background_object_spawn_y, Race_background_object_probability,
			background_object_generate_probability,
			background_objects, background_timer, background_rockgray1_i,
			background_rocksand1_i, background_rocksand2_i);

		hedge_time = hedge_timer.getElapsedTime().asSeconds();
		hedge_generate_probability = hedge_generate_probability - hedge_time
			* 10 - rand() % 100;

		generate_hedge(hedge_generate_probability, hedges, game_time,
			hedge_timer, hedges_deadcars1_i, hedges_deadcars2_i);

		background_garbage_collector(background_objects);

		player_collision_hedges(player, hedges, effects, effects_explosion2_i);

		for (it1_hedges = hedges.begin(); it1_hedges != hedges.end();) {
			Hedge *e = *it1_hedges;
			if (e->is_alive() == false) {
				it1_hedges = hedges.erase(it1_hedges);
				delete e;
			}
			else ++it1_hedges;
		}

		for (it_effects = effects.begin(); it_effects != effects.end();) {
			Effect *e = *it_effects;
			if (e->is_alive() == false) {
				it_effects = effects.erase(it_effects);
				delete e;
			}
			else ++it_effects;
		}

		if (player.update(Compensating_for_performance_losses_time)) {
			break;
		}

		for (it_background = background_objects.begin();
			it_background != background_objects.end(); ++it_background) {
			(*it_background)->update(Compensating_for_performance_losses_time);
		}

		for (it1_hedges = hedges.begin(); it1_hedges != hedges.end();
			++it1_hedges) {
			(*it1_hedges)->update(Compensating_for_performance_losses_time);
		}

		for (it_effects = effects.begin(); it_effects != effects.end();
			++it_effects) {
			(*it_effects)->update(Compensating_for_performance_losses_time);
		}

		window.draw(background_s);

		for (it_background = background_objects.begin();
			it_background != background_objects.end(); ++it_background) {
			window.draw((*it_background)->get_sprite());
		}

		for (it1_hedges = hedges.begin(); it1_hedges != hedges.end();
			++it1_hedges) {
			window.draw((*it1_hedges)->get_sprite());
		}

		window.draw(player.get_sprite());

		for (it_effects = effects.begin(); it_effects != effects.end();
			++it_effects) {
			window.draw((*it_effects)->get_sprite());
		}

		interface_health_and_score_bar.update(player.get_score(),
			player.get_health(), window);

		window.display();
	}

	return 0;
}