#include "Scroll_Shooter.h"

int Scroll_Shooter(sf::RenderWindow &WINDOW) {
	sf::Texture player_t;

	sf::Texture background_rocksand1_t;
	sf::Texture background_rocksand2_t;
	sf::Texture background_rockgray1_t;

	sf::Texture effects_explosion1_t;
	sf::Texture effects_explosion2_t;

	sf::Texture effects_shooting_t;

	sf::Texture bullet_t;

	sf::Texture enemy_battlemule_t;
	sf::Texture enemy_impalabattle_t;
	sf::Texture enemy_slage_t;

	sf::Texture interface_plate_t;

	sf::Texture background_t;
	if (!background_t.loadFromFile
		("res/images/background/sandbackground.png")) {

		return 1;
	}

	sf::Sprite background_s;
	background_s.setTexture(background_t);
	background_s.setScale(Scroll_Shooter_background_scale_x,
		Scroll_Shooter_background_scale_y);

	if (initializing(player_t, background_rocksand1_t, background_rocksand2_t,
		background_rockgray1_t, enemy_battlemule_t, enemy_impalabattle_t,
		enemy_slage_t, effects_explosion1_t, effects_explosion2_t,
		effects_shooting_t, bullet_t, interface_plate_t)) {

		return 1;
	}

	sf::Font font;
	if (!font.loadFromFile("res/font/beer_money.ttf")) {
		return 1;
	}

	sf::Text text("", font, 50);
	text.setColor(sf::Color::Black);


	Player player(player_t, player_spawn_x, player_spawn_y, player_speed,
		player_spawn_health, Scroll_Shooter_player_time_between_shots,
		Scroll_Shooter_player_damage_per_shot);
	Interface interface_health_and_score_bar(interface_plate_t,
		interface_plate_x, interface_plate_y, text);

	std::list<Background*> background_objects;
	std::list<Effect*> effects;
	std::list<Bullet*> bullets;
	std::list<Scroll_Shooter_enemies_car*> enemies;

	srand(time(NULL));

	float game_time = game_timer.getElapsedTime().asSeconds();
	float score_time = game_time;
	float enemy_generate_probability = Scroll_Shooter_game_difficulty;
	float background_object_generate_probability
		= Scroll_Shooter_background_object_probability;

	while (WINDOW.isOpen()) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			break;
		}

		background_objects_generate(DOWN,
			Scroll_Shooter_background_object_spawn_x,
			Scroll_Shooter_background_object_spawn_y,
			Scroll_Shooter_background_object_probability,
			background_object_generate_probability,
			background_objects, background_timer, background_rockgray1_t,
			background_rocksand1_t, background_rocksand2_t);

		game_time = game_timer.getElapsedTime().asSeconds();
		player.change_score(game_time - score_time);
		score_time = game_time;

		generate(background_objects, enemies,
			background_object_generate_probability, enemy_generate_probability,
			background_rockgray1_t, background_rocksand1_t,
			background_rocksand2_t, enemy_battlemule_t, enemy_impalabattle_t,
			enemy_slage_t);

		objects_interact(player, enemies, bullets, effects,
			effects_shooting_t, effects_explosion1_t, effects_explosion2_t);

		if (!player.is_alive()) {
			break;
		}

		garbage_collector(background_objects, enemies, bullets, effects);

		update(WINDOW, background_objects, enemies, bullets, effects, player,
			effects_shooting_t, bullet_t);
		
		draw(WINDOW, background_s, background_objects, enemies, effects,
			bullets, player);

		interface_health_and_score_bar.update(player.get_score(),
			player.get_health(), WINDOW);

		WINDOW.display();
	}

	return 0;
}

inline bool initializing(sf::Texture &PLAYER_T,
	sf::Texture &BACKGROUND_ROCKSAND1_T, sf::Texture &BACKGROUND_ROCKSAND2_T,
	sf::Texture &BACKGROUND_ROCKGRAY1_T, sf::Texture &ENEMY_BATTLEMULE_T,
	sf::Texture &ENEMY_IMPALABATTLE_T, sf::Texture &ENEMY_SLAGE_T,
	sf::Texture &EFFECTS_EXPLOSION1_T, sf::Texture &EFFECTS_EXPLOSION2_T,
	sf::Texture &EFFECTS_SHOOTING_T, sf::Texture &BULLET_T,
	sf::Texture &INTERFACE_PLATE_T) {

	if (!PLAYER_T.loadFromFile("res/images/unit/chevroletbattle.png")) {
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

	if (!ENEMY_BATTLEMULE_T.loadFromFile("res/images/enemy/battlemule.png")) {
		return 1;
	}

	if (!ENEMY_IMPALABATTLE_T.loadFromFile
	("res/images/enemy/impalabattle.png")) {

		return 1;
	}

	if (!ENEMY_SLAGE_T.loadFromFile("res/images/enemy/slage.png")) {
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

	if (!EFFECTS_SHOOTING_T.loadFromFile("res/images/effects/shooting.png")) {
		return 1;
	}

	if (!BULLET_T.loadFromFile("res/images/bullets/bullet.png")) {
		return 1;
	}

	if (!INTERFACE_PLATE_T.loadFromFile("res/images/interface/button.png")) {
		return 1;
	}

	return 0;
}

inline void generate(std::list<Background*> &BACKGROUND_OBJECTS,
	std::list<Scroll_Shooter_enemies_car*> &ENEMIES,
	float &BACKGROUND_OBJECT_GENERATE_PROBABILITY,
	float &ENEMY_GENERATE_PROBABILITY,
	sf::Texture &BACKGROUND_ROCKGRAY1_T, sf::Texture &BACKGROUND_ROCKSAND1_T,
	sf::Texture &BACKGROUND_ROCKSAND2_T, sf::Texture &ENEMY_BATTLEMULE_T,
	sf::Texture &ENEMY_IMPALABATTLE_T, sf::Texture &ENEMY_SLAGE_T) {

	float background_time = background_timer.getElapsedTime().asSeconds();
	float enemy_time = enemy_timer.getElapsedTime().asSeconds();
	float game_time = game_timer.getElapsedTime().asSeconds();

	BACKGROUND_OBJECT_GENERATE_PROBABILITY
		= BACKGROUND_OBJECT_GENERATE_PROBABILITY - background_time * 100
		- rand() % 100;

	ENEMY_GENERATE_PROBABILITY = ENEMY_GENERATE_PROBABILITY - enemy_time
		* 100 - rand() % 100;

	background_objects_generate(DOWN, Scroll_Shooter_background_object_spawn_x,
		Scroll_Shooter_background_object_spawn_y, 
		Scroll_Shooter_background_object_probability,
		BACKGROUND_OBJECT_GENERATE_PROBABILITY, BACKGROUND_OBJECTS,
		background_timer, BACKGROUND_ROCKGRAY1_T,
		BACKGROUND_ROCKSAND1_T, BACKGROUND_ROCKSAND2_T);

	scroll_shooter_enemies_car_generate(ENEMY_GENERATE_PROBABILITY,
		ENEMIES, game_time, enemy_timer, ENEMY_BATTLEMULE_T,
		ENEMY_IMPALABATTLE_T, ENEMY_SLAGE_T);
}

inline void objects_interact(Player &PLAYER,
	std::list<Scroll_Shooter_enemies_car*> &ENEMIES,
	std::list<Bullet*> &BULLETS, std::list<Effect*> &EFFECTS,
	sf::Texture &EFFECTS_SHOOTING_T, sf::Texture &EFFECTS_EXPLOSION1_T,
	sf::Texture &EFFECTS_EXPLOSION2_T) {
	std::list<Scroll_Shooter_enemies_car*>::iterator it_enemies;
	std::list<Scroll_Shooter_enemies_car*>::iterator it2_enemies;
	std::list<Bullet*>::iterator it_bullets;

	for (it_enemies = ENEMIES.begin();
		it_enemies != ENEMIES.end(); ++it_enemies) {

		for (it2_enemies = ENEMIES.begin();
			it2_enemies != ENEMIES.end(); ++it2_enemies) {

			if (it_enemies != it2_enemies) {
				if ((*it_enemies)->get_rect().
					intersects((*it2_enemies)->get_rect())) {
					(*it_enemies)->change_health(-(*it_enemies)->get_health());
					(*it2_enemies)->change_health
					(-(*it_enemies)->get_health());
				}
			}
		}
	}

	for (it_bullets = BULLETS.begin(); it_bullets != BULLETS.end();
		++it_bullets) {

		if ((*it_bullets)->get_rect().intersects(PLAYER.get_rect())
			&& (*it_bullets)->side == enemies_side) {
			EFFECTS.push_back(new Effect(EFFECTS_EXPLOSION1_T,
				(*it_bullets)->get_x() + (*it_bullets)->get_w() / 2,
				(*it_bullets)->get_y() + (*it_bullets)->get_h() / 2,
				background_speed, DOWN, effects_explosion1_exist_time));

			PLAYER.change_health(-(*it_bullets)->damage);
			PLAYER.change_score(-5);

			(*it_bullets)->kill_object();

			continue;
		}

		for (it_enemies = ENEMIES.begin(); it_enemies != ENEMIES.end();
			++it_enemies) {

			if ((*it_bullets)->get_rect()
				.intersects((*it_enemies)->get_rect())
				&& (*it_bullets)->side == player_side) {

				(*it_enemies)->change_health(-(*it_bullets)->damage);

				EFFECTS.push_back(new Effect(EFFECTS_EXPLOSION1_T,
					Effects_bullets_spawn_x, Effects_bullets_spawn_y,
					background_speed, DOWN,
					effects_explosion1_exist_time));

				PLAYER.change_score(1);

				(*it_bullets)->kill_object();

				break;
			}
		}
	}

	for (it_enemies = ENEMIES.begin(); it_enemies != ENEMIES.end();) {

		if ((*it_enemies)->get_rect().intersects(PLAYER.get_rect())) {
			EFFECTS.push_back(new Effect(EFFECTS_EXPLOSION2_T,
				Effects_spawn_x, Effects_spawn_y, background_speed, DOWN,
				effects_explosion2_exist_time));

			PLAYER.change_health(-(*it_enemies)->get_health());

			PLAYER.change_score(-5);

			it_enemies = ENEMIES.erase(it_enemies);
		}
		else {
			++it_enemies;
		}
	}

	for (it_enemies = ENEMIES.begin(); it_enemies != ENEMIES.end();
		++it_enemies) {
		if ((*it_enemies)->get_health() <= 0) {
			EFFECTS.push_back(new Effect(EFFECTS_EXPLOSION2_T,
				Effects_spawn_x, Effects_spawn_y, background_speed,
				DOWN, effects_explosion2_exist_time));

			PLAYER.change_score(5);

			(*it_enemies)->kill_object();
		}
	}
}

inline void garbage_collector(std::list<Background*> &BACKGROUND_OBJECTS,
	std::list<Scroll_Shooter_enemies_car*> &ENEMIES,
	std::list<Bullet*> &BULLETS, std::list<Effect*> &EFFECTS) {

	background_garbage_collector(BACKGROUND_OBJECTS);

	scroll_shooter_enemies_car_garbage_collector(ENEMIES);

	bullet_garbage_collector(BULLETS);

	effect_garbage_collector(EFFECTS);
}

inline void update(sf::RenderWindow &WINDOW,
	std::list<Background*> &BACKGROUND_OBJECTS,
	std::list<Scroll_Shooter_enemies_car*> &ENEMIES,
	std::list<Bullet*> &BULLETS, std::list<Effect*> &EFFECTS, Player &PLAYER,
	sf::Texture &EFFECTS_SHOOTING_T, sf::Texture &BULLET_T) {

	float Compensating_for_performance_losses_time
		= Compensating_for_performance_losses_timer.getElapsedTime()
		.asMicroseconds();

	Compensating_for_performance_losses_timer.restart();

	Compensating_for_performance_losses_time
		= Compensating_for_performance_losses_coefficient;

	PLAYER.update(Compensating_for_performance_losses_time);

	if (PLAYER.is_shot_available() == true) {
		EFFECTS.push_back(new Effect(EFFECTS_SHOOTING_T,
			player_shot_1point_x, player_shot_1point_y,
			Scroll_Shooter_effects_shooting_speed, STAY,
			Scroll_Shooter_effects_shooting_exist_time));
		BULLETS.push_back(new Bullet(BULLET_T,
			player_shot_1point_x, player_shot_1point_y,
			player_bullet_speed, UP, PLAYER.return_damage(), player_side));
		EFFECTS.push_back(new Effect(EFFECTS_SHOOTING_T,
			player_shot_2point_x, player_shot_2point_y,
			Scroll_Shooter_effects_shooting_speed, STAY,
			Scroll_Shooter_effects_shooting_exist_time));
		BULLETS.push_back(new Bullet(BULLET_T,
			player_shot_2point_x, player_shot_1point_y,
			player_bullet_speed, UP, PLAYER.return_damage(), player_side));

		PLAYER.shoot();
	}

	for (std::list<Background*>::iterator it_background
		= BACKGROUND_OBJECTS.begin(); it_background
		!= BACKGROUND_OBJECTS.end(); ++it_background) {
		(*it_background)->update(Compensating_for_performance_losses_time);
	}

	for (std::list<Scroll_Shooter_enemies_car*>::iterator it_enemies
		= ENEMIES.begin(); it_enemies != ENEMIES.end(); ++it_enemies) {

		if ((*it_enemies)->update(Compensating_for_performance_losses_time)) {
			if ((*it_enemies)->get_direction() == DOWN
				|| (*it_enemies)->get_direction() == DOWN_LEFT
				|| (*it_enemies)->get_direction() == DOWN_LEFT) {

				EFFECTS.push_back(new Effect(EFFECTS_SHOOTING_T,
					enemy_shot_point_x, enemy_shot_down_point_y,
					Scroll_Shooter_effects_shooting_speed, DOWN,
					Scroll_Shooter_effects_shooting_exist_time));
				BULLETS.push_back(new Bullet(BULLET_T,
					enemy_shot_point_x, enemy_shot_down_point_y,
					enemy_bullet_speed, DOWN, (*it_enemies)->return_damage(),
					enemies_side));
			}
			if ((*it_enemies)->get_direction() == UP
				|| (*it_enemies)->get_direction() == UP_LEFT
				|| (*it_enemies)->get_direction() == UP_RIGHT) {

				EFFECTS.push_back(new Effect(EFFECTS_SHOOTING_T,
					enemy_shot_point_x, enemy_shot_up_point_y,
					Scroll_Shooter_effects_shooting_speed, UP,
					Scroll_Shooter_effects_shooting_exist_time));
				BULLETS.push_back(new Bullet(BULLET_T,
					enemy_shot_point_x, enemy_shot_up_point_y,
					enemy_bullet_speed, UP, (*it_enemies)->return_damage(),
					enemies_side));
			}
		}
	}

	for (std::list<Bullet*>::iterator it_bullets = BULLETS.begin(); it_bullets
		!= BULLETS.end(); ++it_bullets) {
		(*it_bullets)->update(Compensating_for_performance_losses_time);
	}

	for (std::list<Effect*>::iterator it_effects = EFFECTS.begin(); it_effects
		!= EFFECTS.end(); ++it_effects) {
		(*it_effects)->update(Compensating_for_performance_losses_time);
	}
}

inline void draw(sf::RenderWindow &WINDOW, sf::Sprite &BACKGROUND,
	std::list<Background*> &BACKGROUND_OBJECTS,
	std::list<Scroll_Shooter_enemies_car*> &ENEMIES,
	std::list<Effect*> &EFFECTS, std::list<Bullet*> &BULLETS, Player &PLAYER) {

	WINDOW.draw(BACKGROUND);

	for (std::list<Background*>::iterator it_background
		= BACKGROUND_OBJECTS.begin(); it_background
		!= BACKGROUND_OBJECTS.end(); ++it_background) {
		WINDOW.draw((*it_background)->get_sprite());
	}

	for (std::list<Scroll_Shooter_enemies_car*>::iterator it_enemies
		= ENEMIES.begin(); it_enemies != ENEMIES.end();
		++it_enemies) {
		WINDOW.draw((*it_enemies)->get_sprite());
	}

	for (std::list<Bullet*>::iterator it_bullets = BULLETS.begin(); it_bullets
		!= BULLETS.end(); ++it_bullets) {
		WINDOW.draw((*it_bullets)->get_sprite());
	}

	WINDOW.draw(PLAYER.get_sprite());

	for (std::list<Effect*>::iterator it_effects = EFFECTS.begin(); it_effects
		!= EFFECTS.end(); ++it_effects) {
		WINDOW.draw((*it_effects)->get_sprite());
	}
}