#include "Race.h"

int Race(sf::RenderWindow &WINDOW) {
	sf::Texture player_t;
	
	sf::Texture background_rocksand1_t;
	sf::Texture background_rocksand2_t;
	sf::Texture background_rockgray1_t;

	sf::Texture hedges_deadcars1_t;
	sf::Texture hedges_deadcars2_t;
	
	sf::Texture effects_explosion2_t;

	sf::Texture interface_plate_t;

	if (initializing(player_t, background_rocksand1_t, background_rocksand2_t,
		background_rockgray1_t, hedges_deadcars1_t,
		hedges_deadcars2_t, effects_explosion2_t, interface_plate_t)) {

		return 1;
	}

	sf::Texture background_t;
	if (!background_t.loadFromFile
		("res/images/background/sandbackground.png")) {
		return 1;
	}

	sf::Sprite background_s;
	background_s.setTexture(background_t);
	background_s.setScale(Race_background_scale_x, Race_background_scale_y);

	sf::Font font;
	font.loadFromFile("res/font/beer_money.ttf");
	sf::Text text("", font, 50);
	text.setColor(sf::Color::Black);


	Player player(player_t, player_spawn_x, player_spawn_y, player_speed,
		player_spawn_health, Scroll_Shooter_player_time_between_shots,
		Scroll_Shooter_player_damage_per_shot);
	Interface interface_health_and_score_bar(interface_plate_t, interface_plate_x,
		interface_plate_y, text);

	std::list<Background*> background_objects;
	std::list<Effect*> effects;
	std::list<Hedge*> hedges;

	srand(time(NULL));

	float game_time = game_timer.getElapsedTime().asSeconds();
	float score_time = game_time;

	float hedge_generate_probability = Race_game_difficulty;

	float background_object_generate_probability
		= Race_background_object_probability;

	while (WINDOW.isOpen()) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			break;
		}

		game_time = game_timer.getElapsedTime().asSeconds();

		player.change_score(game_time - score_time);
		score_time = game_time;

		generate(background_objects, hedges,
			background_object_generate_probability, hedge_generate_probability,
			background_rockgray1_t, background_rocksand1_t,
			background_rocksand2_t, hedges_deadcars1_t, hedges_deadcars2_t);

		player_collision_hedges(player, hedges, effects, effects_explosion2_t);

		if (!player.is_alive()) {
			break;
		}

		garbage_collector(background_objects, hedges, effects);

		update(WINDOW, background_objects, hedges, effects, player);

		draw(WINDOW, background_s, background_objects, hedges, effects,
			player);

		interface_health_and_score_bar.update(player.get_score(),
			player.get_health(), WINDOW);

		WINDOW.display();
	}

	return 0;
}

inline bool initializing(sf::Texture &player_t,
	sf::Texture &background_rocksand1_t, sf::Texture &background_rocksand2_t,
	sf::Texture &background_rockgray1_t, sf::Texture &hedges_deadcars1_t,
	sf::Texture &hedges_deadcars2_t, sf::Texture &effects_explosion2_t,
	sf::Texture &interface_plate_t) {
	if (!player_t.loadFromFile("res/images/unit/chevroletbattle.png")) {
		return 1;
	}

	if (!background_rocksand1_t.loadFromFile
	("res/images/background/rocksand1.png")) {

		return 1;
	}

	if (!background_rocksand2_t.loadFromFile
	("res/images/background/rocksand2.png")) {

		return 1;
	}

	if (!background_rockgray1_t.loadFromFile
	("res/images/background/rockgray1.png")) {

		return 1;
	}

	if (!hedges_deadcars1_t.loadFromFile("res/images/hedges/deadcars1.png")) {
		return 1;
	}

	if (!hedges_deadcars2_t.loadFromFile("res/images/hedges/deadcars2.png")) {
		return 1;
	}

	if (!effects_explosion2_t.loadFromFile
	("res/images/effects/explosion2.png")) {
		return 1;
	}

	if (!interface_plate_t.loadFromFile("res/images/interface/button.png")) {
		return 1;
	}

	return 0;
}

inline void generate(std::list<Background*> &BACKGROUND_OBJECTS,
	std::list<Hedge*> &HEDGES, float &BACKGROUND_OBJECT_GENERATE_PROBABILITY,
	float &HEDGE_GENERATE_PROBABILITY, sf::Texture &BACKGROUND_ROCKGRAY1_T,
	sf::Texture &BACKGROUND_ROCKSAND1_T, sf::Texture &BACKGROUND_ROCKSAND2_T,
	sf::Texture &HEDGES_DEADCARS1_T, sf::Texture &HEDGES_DEADCARS2_T) {
	float background_time = background_timer.getElapsedTime().asSeconds();
	float hedge_time = hedge_timer.getElapsedTime().asSeconds();
	float game_time = game_timer.getElapsedTime().asSeconds();

	BACKGROUND_OBJECT_GENERATE_PROBABILITY
		= BACKGROUND_OBJECT_GENERATE_PROBABILITY - background_time * 100
		- rand() % 100;

	HEDGE_GENERATE_PROBABILITY = HEDGE_GENERATE_PROBABILITY - hedge_time
		* 100 - rand() % 100;

	background_objects_generate(DOWN, Race_background_object_spawn_x,
		Race_background_object_spawn_y, Race_background_object_probability,
		BACKGROUND_OBJECT_GENERATE_PROBABILITY,
		BACKGROUND_OBJECTS, background_timer, BACKGROUND_ROCKGRAY1_T,
		BACKGROUND_ROCKSAND1_T, BACKGROUND_ROCKSAND2_T);

	generate_hedge(HEDGE_GENERATE_PROBABILITY, HEDGES, game_time,
		hedge_timer, HEDGES_DEADCARS1_T, HEDGES_DEADCARS2_T);
}

inline void garbage_collector(std::list<Background*> &BACKGROUND_OBJECTS,
	std::list<Hedge*> &HEDGES, std::list<Effect*> &EFFECTS) {

	background_garbage_collector(BACKGROUND_OBJECTS);

	hedge_garbage_collector(HEDGES);

	effect_garbage_collector(EFFECTS);
}

inline void update(sf::RenderWindow &WINDOW,
	std::list<Background*> &BACKGROUND_OBJECTS, std::list<Hedge*> &HEDGES,
	std::list<Effect*> &EFFECTS, Player &PLAYER) {

	float Compensating_for_performance_losses_time
		= Compensating_for_performance_losses_timer.getElapsedTime()
		.asMicroseconds();

	Compensating_for_performance_losses_timer.restart();

	Compensating_for_performance_losses_time
		= Compensating_for_performance_losses_coefficient;

	PLAYER.update(Compensating_for_performance_losses_time);

	for (std::list<Background*>::iterator it_background
		= BACKGROUND_OBJECTS.begin(); it_background
		!= BACKGROUND_OBJECTS.end(); ++it_background) {
		(*it_background)->update(Compensating_for_performance_losses_time);
	}

	for (std::list<Hedge*>::iterator it1_hedges = HEDGES.begin(); it1_hedges
		!= HEDGES.end(); ++it1_hedges) {
		(*it1_hedges)->update(Compensating_for_performance_losses_time);
	}

	for (std::list<Effect*>::iterator it_effects = EFFECTS.begin(); it_effects
		!= EFFECTS.end(); ++it_effects) {
		(*it_effects)->update(Compensating_for_performance_losses_time);
	}
}

inline void draw(sf::RenderWindow &WINDOW, sf::Sprite &BACKGROUND,
	std::list<Background*> &BACKGROUND_OBJECTS, std::list<Hedge*> &HEDGES,
	std::list<Effect*> &EFFECTS, Player &PLAYER) {
	WINDOW.draw(BACKGROUND);

	for (std::list<Background*>::iterator it_background
		= BACKGROUND_OBJECTS.begin(); it_background
		!= BACKGROUND_OBJECTS.end(); ++it_background) {
		WINDOW.draw((*it_background)->get_sprite());
	}

	for (std::list<Hedge*>::iterator it1_hedges
		= HEDGES.begin(); it1_hedges != HEDGES.end(); ++it1_hedges) {
		WINDOW.draw((*it1_hedges)->get_sprite());
	}

	WINDOW.draw(PLAYER.get_sprite());

	for (std::list<Effect*>::iterator it_effects = EFFECTS.begin(); it_effects
		!= EFFECTS.end(); ++it_effects) {
		WINDOW.draw((*it_effects)->get_sprite());
	}
}