#include "Shooter.h"

int Shooter(sf::RenderWindow &WINDOW) {
	sf::Texture aim_t;

	sf::Texture background_rocksand1_t;
	sf::Texture background_rocksand2_t;
	sf::Texture background_rockgray1_t;

	sf::Texture effects_explosion1_t;
	sf::Texture effects_explosion2_t;

	sf::Texture effects_shooting_t;

	sf::Texture enemy_copsjups_t;
	sf::Texture enemy_hammer_t;
	sf::Texture enemy_lapdcar_t;

	sf::Texture interface_plate_t;

	if (initializing(aim_t, background_rocksand1_t, background_rocksand2_t,
		background_rockgray1_t, enemy_copsjups_t, enemy_hammer_t,
		enemy_lapdcar_t, effects_explosion1_t, effects_explosion2_t,
		effects_shooting_t, interface_plate_t)) {

		return 1;
	}

	sf::Texture background_t;
	if (!background_t.loadFromFile
		("res/images/background/shooter-background.png")) {

		return 1;
	}

	sf::Sprite background_s;
	background_s.setTexture(background_t);
	background_s.setScale(Shooter_background_scale_x,
		Shooter_background_scale_y);

	sf::Font font;
	font.loadFromFile("res/font/beer_money.ttf");
	sf::Text text("", font, 50);
	text.setColor(sf::Color::Black);


	Player player(aim_t, player_spawn_x, player_spawn_y, player_speed,
		player_spawn_health, Shooter_player_time_between_shots,
		Shooter_player_damage_per_shot);
	Interface interface_health_and_score_bar(interface_plate_t, interface_plate_x,
		interface_plate_y, text);

	std::list<Background*> background_objects;
	std::list<Effect*> effects;
	std::list<Shooter_enemies_car*> enemies;

	srand(time(NULL));

	float game_time = game_timer.getElapsedTime().asSeconds();
	float score_time = game_time;
	float enemy_generate_probability = Shooter_game_difficulty;
	float background_object_generate_probability
		= Shooter_background_object_probability;
	char enemy_number = 0;

	while (WINDOW.isOpen()) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			break;
		}

		game_time = game_timer.getElapsedTime().asSeconds();

		player.change_score(game_time - score_time);
		score_time = game_time;

		generate(background_objects, enemies,
			background_object_generate_probability, enemy_generate_probability,
			enemy_number, background_rockgray1_t, background_rocksand1_t,
			background_rocksand2_t, enemy_copsjups_t, enemy_hammer_t,
			enemy_lapdcar_t);

		objects_interact(player, enemies, effects, enemy_number,
			effects_shooting_t, effects_explosion1_t, effects_explosion2_t);

		if (!player.is_alive()) {
			break;
		}

		garbage_collector(background_objects, enemies, effects);

		update(WINDOW, background_objects, enemies, effects, player);

		draw(WINDOW, background_s, background_objects, enemies, effects,
			player);

		interface_health_and_score_bar.update(player.get_score(),
			player.get_health(), WINDOW);

		WINDOW.display();
	}

	return 0;
}

inline bool initializing(sf::Texture &AIM_T,
	sf::Texture &BACKGROUND_ROCKSAND1_T, sf::Texture &BACKGROUND_ROCKSAND2_T,
	sf::Texture &BACKGROUND_ROCKGRAY1_T, sf::Texture &ENEMY_COPSJUPS_T,
	sf::Texture &ENEMY_HAMMER_T, sf::Texture &ENEMY_LAPDCAR_T, sf::Texture &EFFECTS_EXPLOSION1_T,
	sf::Texture &EFFECTS_EXPLOSION2_T, sf::Texture &EFFECTS_SHOOTING_T, 
	sf::Texture &INTERFACE_PLATE_T) {

	if (!AIM_T.loadFromFile("res/images/aim/aim.png")) {
		return 1;
	}

	if (!BACKGROUND_ROCKSAND1_T.loadFromFile
	("res/images/background/rocksand1.png")) {

		return 1;
	}

	if (!BACKGROUND_ROCKSAND2_T.loadFromFile
	("res/images/background/rocksand2.png")) {

		return 1;
	}

	if (!BACKGROUND_ROCKGRAY1_T.loadFromFile
	("res/images/background/rockgray1.png")) {

		return 1;
	}

	if (!ENEMY_COPSJUPS_T.loadFromFile("res/images/enemy/copsjups.png")) {
		return 1;
	}

	if (!ENEMY_HAMMER_T.loadFromFile("res/images/enemy/hammer.png")) {
		return 1;
	}

	if (!ENEMY_LAPDCAR_T.loadFromFile("res/images/enemy/lapdcar.png")) {
		return 1;
	}

	if (!EFFECTS_EXPLOSION1_T.loadFromFile
	("res/images/effects/explosion1.png")) {

		return 1;
	}

	if (!EFFECTS_EXPLOSION2_T.loadFromFile
	("res/images/effects/explosion2.png")) {
		return 1;
	}

	if (!EFFECTS_SHOOTING_T.loadFromFile("res/images/effects/shooting2.png")) {
		return 1;
	}

	if (!INTERFACE_PLATE_T.loadFromFile("res/images/interface/button.png")) {
		return 1;
	}

	return 0;
}

inline void generate(std::list<Background*> &BACKGROUND_OBJECTS,
	std::list<Shooter_enemies_car*> &ENEMIES,
	float &BACKGROUND_OBJECT_GENERATE_PROBABILITY,
	float &ENEMY_GENERATE_PROBABILITY, char &ENEMY_NUMBER,
	sf::Texture &BACKGROUND_ROCKGRAY1_T, sf::Texture &BACKGROUND_ROCKSAND1_T,
	sf::Texture &BACKGROUND_ROCKSAND2_T, sf::Texture &ENEMY_COPSJUPS_T,
	sf::Texture &ENEMY_HAMMER_T, sf::Texture &ENEMY_LAPDCAR_T) {

	float background_time = background_timer.getElapsedTime().asSeconds();
	float enemy_time = enemy_timer.getElapsedTime().asSeconds();
	float game_time = game_timer.getElapsedTime().asSeconds();

	BACKGROUND_OBJECT_GENERATE_PROBABILITY
		= BACKGROUND_OBJECT_GENERATE_PROBABILITY - background_time * 100
		- rand() % 100;

	ENEMY_GENERATE_PROBABILITY = ENEMY_GENERATE_PROBABILITY - enemy_time
		* 100 - rand() % 100;

	background_objects_generate(LEFT, Shooter_background_object_spawn_x,
		Shooter_background_object_spawn_y, Shooter_background_object_probability,
		BACKGROUND_OBJECT_GENERATE_PROBABILITY,
		BACKGROUND_OBJECTS, background_timer, BACKGROUND_ROCKGRAY1_T,
		BACKGROUND_ROCKSAND1_T, BACKGROUND_ROCKSAND2_T);

	shooter_enemies_car_generate(ENEMY_GENERATE_PROBABILITY,
		ENEMY_NUMBER, ENEMIES, game_time, enemy_timer, ENEMY_COPSJUPS_T,
		ENEMY_HAMMER_T, ENEMY_LAPDCAR_T);
}

inline void objects_interact(Player &PLAYER,
	std::list<Shooter_enemies_car*> &ENEMIES, std::list<Effect*> &EFFECTS,
	char &ENEMY_NUMBER, sf::Texture &EFFECTS_SHOOTING_T,
	sf::Texture &EFFECTS_EXPLOSION1_T, sf::Texture &EFFECTS_EXPLOSION2_T) {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)
		&& PLAYER.is_shot_available()) {
		PLAYER.shoot();

		EFFECTS.push_back(new Effect(EFFECTS_SHOOTING_T,
			Shooter_effects_player_shot_spawn_x, Shooter_effects_player_shot_spawn_y,
			Shooter_effects_shooting_speed, STAY,
			Shooter_effects_shooting_exist_time));

		for (std::list<Shooter_enemies_car*>::iterator it_enemies
			= ENEMIES.begin(); it_enemies != ENEMIES.end();
			++it_enemies) {

			if ((*it_enemies)->get_rect().intersects(PLAYER.get_rect())) {
				(*it_enemies)->change_health(-PLAYER.return_damage());
				EFFECTS.push_back(new Effect(EFFECTS_EXPLOSION1_T,
					Shooter_effects_player_shot_spawn_x, Shooter_effects_player_shot_spawn_y,
					background_speed, LEFT,
					effects_explosion1_exist_time));
			}
		}
	}

	for (std::list<Shooter_enemies_car*>::iterator it_enemies
		= ENEMIES.begin(); it_enemies != ENEMIES.end(); ++it_enemies) {
		if ((*it_enemies)->get_health() <= 0) {
			EFFECTS.push_back(new Effect(EFFECTS_EXPLOSION2_T,
				Effects_spawn_x, Effects_spawn_y, background_speed,
				LEFT, effects_explosion2_exist_time));

			PLAYER.change_score(5);

			--ENEMY_NUMBER;
			(*it_enemies)->kill_object();
		}
	}
}

inline void garbage_collector(std::list<Background*> &BACKGROUND_OBJECTS,
	std::list<Shooter_enemies_car*> &ENEMIES, std::list<Effect*> &EFFECTS) {

	background_garbage_collector(BACKGROUND_OBJECTS);

	shooter_enemies_car_garbage_collector(ENEMIES);

	effect_garbage_collector(EFFECTS);
}

inline void update(sf::RenderWindow &WINDOW,
	std::list<Background*> &BACKGROUND_OBJECTS, std::list<Shooter_enemies_car*> &ENEMIES,
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

	for (std::list<Shooter_enemies_car*>::iterator it_enemies
		= ENEMIES.begin(); it_enemies != ENEMIES.end(); ++it_enemies) {

		if ((*it_enemies)->update(Compensating_for_performance_losses_time)) {
			PLAYER.change_health(-(*it_enemies)->return_damage());
			PLAYER.change_score(-5);
		}
	}

	for (std::list<Effect*>::iterator it_effects = EFFECTS.begin(); it_effects
		!= EFFECTS.end(); ++it_effects) {
		(*it_effects)->update(Compensating_for_performance_losses_time);
	}
}

inline void draw(sf::RenderWindow &WINDOW, sf::Sprite &BACKGROUND,
	std::list<Background*> &BACKGROUND_OBJECTS, std::list<Shooter_enemies_car*> &ENEMIES,
	std::list<Effect*> &EFFECTS, Player &PLAYER) {
	WINDOW.draw(BACKGROUND);

	for (std::list<Background*>::iterator it_background
		= BACKGROUND_OBJECTS.begin(); it_background
		!= BACKGROUND_OBJECTS.end(); ++it_background) {
		WINDOW.draw((*it_background)->get_sprite());
	}

	for (std::list<Shooter_enemies_car*>::iterator it_enemies
		= ENEMIES.begin(); it_enemies != ENEMIES.end();
		++it_enemies) {
		WINDOW.draw((*it_enemies)->get_sprite());
	}

	for (std::list<Effect*>::iterator it_effects = EFFECTS.begin(); it_effects
		!= EFFECTS.end(); ++it_effects) {
		WINDOW.draw((*it_effects)->get_sprite());
	}

	WINDOW.draw(PLAYER.get_sprite());
}