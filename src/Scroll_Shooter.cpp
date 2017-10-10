#include "Scroll_Shooter.h"

int Scroll_Shooter(sf::RenderWindow & window) {
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

	sf::Image effects_explosion1_i;
	if (!effects_explosion1_i.loadFromFile
		("res/images/effects/explosion1.png")) {

		return 0;
	}

	sf::Image effects_explosion2_i;
	if (!effects_explosion2_i.loadFromFile
		("res/images/effects/explosion2.png")) {

		return 0;
	}

	sf::Image effects_shooting_i;
	if (!effects_shooting_i.loadFromFile("res/images/effects/shooting.png")) {
		return 0;
	}

	sf::Image enemy_battlemule_i;
	if (!enemy_battlemule_i.loadFromFile("res/images/enemy/battlemule.png")) {
		return 0;
	}

	sf::Image enemy_impalabattle_i;
	if (!enemy_impalabattle_i.loadFromFile
		("res/images/enemy/impalabattle.png")) {

		return 0;
	}

	sf::Image enemy_slage_i;
	if (!enemy_slage_i.loadFromFile("res/images/enemy/slage.png")) {
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
	background_s.setScale(Scroll_Shooter_background_scale_x,
		Scroll_Shooter_background_scale_y);

	sf::Image bullet_bullet_i;
	if (!bullet_bullet_i.loadFromFile("res/images/bullets/bullet.png")) {
		return 0;
	}

	sf::Image plate_i;
	if (!plate_i.loadFromFile("res/images/interface/button.png")) {
		return 0;
	}

	sf::Font font;
	if (!font.loadFromFile("res/font/beer_money.ttf")) {
		return 0;
	}

	sf::Text text("", font, 50);
	text.setColor(sf::Color::Black);


	Player player(player_i, player_spawn_x, player_spawn_y, player_speed,
		player_spawn_health, Scroll_Shooter_player_time_between_shots,
		Scroll_Shooter_player_damage_per_shot);
	Interface interface_health_and_score_bar(plate_i, interface_plate_x,
		interface_plate_y, text);

	std::list<Background*>  background_objects;
	std::list<Background*>::iterator it_background;

	std::list<Effect*>  effects;
	std::list<Effect*>::iterator it_effects;

	std::list<Bullet*>  bullets;
	std::list<Bullet*>::iterator it_bullets;

	std::list<Enemies_cars*>  enemies_cars;
	std::list<Enemies_cars*>::iterator it1_enemies_cars, it2_enemies_cars;

	srand(time(NULL));

	float game_time = game_timer.getElapsedTime().asSeconds();
	float score_time = game_time;
	float enemy_generate_probability = Scroll_Shooter_game_difficulty;
	float background_object_generate_probability
		= Scroll_Shooter_background_object_probability;
	float background_time;
	float enemy_time;

	while (window.isOpen()) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			break;
		}

		float Compensating_for_performance_losses_time
			= Compensating_for_performance_losses_timer.getElapsedTime()
			.asMicroseconds();

		Compensating_for_performance_losses_timer.restart();

		Compensating_for_performance_losses_time
			= Compensating_for_performance_losses_coefficient;

		if (player.update(Compensating_for_performance_losses_time)) {
			break;
		}

		window.clear();
		window.draw(background_s);

		background_time = background_timer.getElapsedTime().asSeconds();

		background_object_generate_probability
			= background_object_generate_probability - background_time
			* 100 - rand() % 100;

		if (background_object_generate_probability < 0) {
			int r = rand() % 3;
			switch (r) {
			case 0:
				background_objects.push_back(new Background
					(background_rocksand1_i,
					Scroll_Shooter_background_object_spawn_x,
					Scroll_Shooter_background_object_spawn_y, DOWN));
				break;
			case 1:
				background_objects.push_back(new Background
					(background_rocksand2_i,
					Scroll_Shooter_background_object_spawn_x,
					Scroll_Shooter_background_object_spawn_y, DOWN));
				break;
			case 2: background_objects.push_back(new Background
					(background_rockgray1_i,
					Scroll_Shooter_background_object_spawn_x,
					Scroll_Shooter_background_object_spawn_y, DOWN));
				break;
			}
			background_object_generate_probability
				= Scroll_Shooter_background_object_probability;
			background_timer.restart();
		}

		game_time = game_timer.getElapsedTime().asSeconds();
		enemy_time = enemy_timer.getElapsedTime().asSeconds();
		enemy_generate_probability = enemy_generate_probability
			- enemy_time * 10 - rand() % 100;

		if (enemy_generate_probability < 0) {
			int r = rand() % 8;
			switch (r) {
			case 0:
				enemies_cars.push_back(new Enemies_cars(enemy_battlemule_i,
					Scroll_Shooter_enemy_up_spawn_x,
					Scroll_Shooter_enemy_up_spawn_y,
					Scroll_Shooter_enemy_battlemule_speed,
					DOWN, Scroll_Shooter_enemy_battlemule_health,
					Scroll_Shooter_enemy_battlemule_time_between_attack,
					Scroll_Shooter_enemy_battlemule_damage));
				break;
			case 1:
				enemies_cars.push_back(new Enemies_cars(enemy_impalabattle_i,
					Scroll_Shooter_enemy_up_spawn_x,
					Scroll_Shooter_enemy_up_spawn_y,
					Scroll_Shooter_enemy_impalabattle_speed,
					DOWN, Scroll_Shooter_enemy_impalabattle_health,
					Scroll_Shooter_enemy_impalabattle_time_between_attack,
					Scroll_Shooter_enemy_impalabattle_damage));
				break;
			case 2:
				enemies_cars.push_back(new Enemies_cars(enemy_slage_i,
					Scroll_Shooter_enemy_up_spawn_x,
					Scroll_Shooter_enemy_up_spawn_y,					
					Scroll_Shooter_enemy_slage_speed,
					DOWN, Scroll_Shooter_enemy_slage_health,
					Scroll_Shooter_enemy_slage_time_between_attack,
					Scroll_Shooter_enemy_slage_damage));
				break;
			case 3:
				enemies_cars.push_back(new Enemies_cars(enemy_battlemule_i,
					Scroll_Shooter_enemy_down_spawn_x,
					Scroll_Shooter_enemy_down_spawn_y,				
					Scroll_Shooter_enemy_battlemule_speed,
					UP, Scroll_Shooter_enemy_battlemule_health,
					Scroll_Shooter_enemy_battlemule_time_between_attack,
					Scroll_Shooter_enemy_battlemule_damage));
				break;
			case 4:
				enemies_cars.push_back(new Enemies_cars(enemy_impalabattle_i,
					Scroll_Shooter_enemy_down_spawn_x,
					Scroll_Shooter_enemy_down_spawn_y,					
					Scroll_Shooter_enemy_impalabattle_speed,
					UP, Scroll_Shooter_enemy_impalabattle_health,
					Scroll_Shooter_enemy_impalabattle_time_between_attack,
					Scroll_Shooter_enemy_impalabattle_damage));
				break;
			case 5:
				enemies_cars.push_back(new Enemies_cars(enemy_slage_i,
					Scroll_Shooter_enemy_down_spawn_x,
					Scroll_Shooter_enemy_down_spawn_y,					
					Scroll_Shooter_enemy_slage_speed,
					UP, Scroll_Shooter_enemy_slage_health,
					Scroll_Shooter_enemy_slage_time_between_attack,
					Scroll_Shooter_enemy_slage_damage));
				break;
			}
			enemy_generate_probability = Scroll_Shooter_game_difficulty
				- game_time * 25;
			if (enemy_generate_probability < Scroll_Shooter_max_game_difficulty) {
				enemy_generate_probability = Scroll_Shooter_max_game_difficulty;
			}
			enemy_timer.restart();
		}

		if (player.is_shot_available() == true) {
			effects.push_back(new Effect(effects_shooting_i,
				player_shot_1point_x, player_shot_1point_y,
				Scroll_Shooter_effects_shooting_speed, STAY,
				Scroll_Shooter_effects_shooting_exist_time));
			bullets.push_back(new Bullet(bullet_bullet_i,
				player_shot_1point_x, player_shot_1point_y,
				player_bullet_speed, UP, player.return_damage(), player_side));
			effects.push_back(new Effect(effects_shooting_i,
				player_shot_2point_x, player_shot_2point_y,
				Scroll_Shooter_effects_shooting_speed, STAY,
				Scroll_Shooter_effects_shooting_exist_time));
			bullets.push_back(new Bullet(bullet_bullet_i,
				player_shot_2point_x, player_shot_1point_y,
				player_bullet_speed, UP, player.return_damage(), player_side));

			player.shoot();
		}

		player.change_score(game_time - score_time);
		score_time = game_time;

		for (it_background = background_objects.begin();
			it_background != background_objects.end();) {
			Background *b = *it_background;
			b->update(Compensating_for_performance_losses_time);
			if (b->is_alive() == false) {
				it_background = background_objects.erase(it_background);
				delete b;
			}
			else ++it_background;
		}

		for (it1_enemies_cars = enemies_cars.begin();
			it1_enemies_cars != enemies_cars.end(); ++it1_enemies_cars) {
			Enemies_cars *e1 = *it1_enemies_cars;

			for (it2_enemies_cars = enemies_cars.begin();
				it2_enemies_cars != enemies_cars.end(); ++it2_enemies_cars) {
				Enemies_cars *e2 = *it2_enemies_cars;

				if (e1 != e2) {
					if (e1->get_rect().intersects(e2->get_rect())) {
						e1->change_health(-e1->get_health());
						e2->change_health(-e1->get_health());
					}
				}
			}
		}

		for (it_bullets = bullets.begin(); it_bullets != bullets.end();) {
			Bullet *b = *it_bullets;

			for (it1_enemies_cars = enemies_cars.begin();
				it1_enemies_cars != enemies_cars.end(); ++it1_enemies_cars) {
				Enemies_cars *e = *it1_enemies_cars;

				if (b->get_rect().intersects(e->get_rect()) && b->side == player_side) {
					e->change_health(-b->damage);

					effects.push_back(new Effect(effects_explosion1_i,
						Effects_bullets_spawn_x, Effects_bullets_spawn_y,
						background_speed, DOWN, effects_explosion1_exist_time));

					player.change_score(1);
					it_bullets = bullets.erase(it_bullets);
					delete b;
					break;
				}
			}
			if (it1_enemies_cars == enemies_cars.end()) {
				++it_bullets;
			}
		}

		for (it_bullets = bullets.begin(); it_bullets != bullets.end();) {
			Bullet *b = *it_bullets;

			if (b->get_rect().intersects(player.get_rect())
				&& b->side == enemies_side) {
				effects.push_back(new Effect(effects_explosion1_i,
					b->get_x() + b->get_w() / 2, b->get_y() + b->get_h() / 2,
					background_speed, DOWN, effects_explosion1_exist_time));

				player.change_health(-b->damage);

				player.change_score(-5);

				it_bullets = bullets.erase(it_bullets);
				delete b;
			}
			else {
				++it_bullets;
			}
		}

		for (it1_enemies_cars = enemies_cars.begin();
			it1_enemies_cars != enemies_cars.end();) {
			Enemies_cars *e = *it1_enemies_cars;
			
			if (e->get_rect().intersects(player.get_rect())) {
				effects.push_back(new Effect(effects_explosion2_i, Effects_spawn_x,
					Effects_spawn_y, background_speed, DOWN,
					effects_explosion2_exist_time));

				player.change_health(-e->get_health());

				player.change_score(-5);

				it1_enemies_cars = enemies_cars.erase(it1_enemies_cars);
				delete e;
			}
			else {
				++it1_enemies_cars;
			}
		}

		for (it_bullets = bullets.begin(); it_bullets != bullets.end();) {
			Bullet *b = *it_bullets;
			
			b->update(Compensating_for_performance_losses_time);
			if (b->is_alive() == false) {
				it_bullets = bullets.erase(it_bullets);
				delete b;
			}
			else ++it_bullets;
		}

		for (it1_enemies_cars = enemies_cars.begin();
			it1_enemies_cars != enemies_cars.end();) {
			Enemies_cars *e = *it1_enemies_cars;
			
			if (e->update(Compensating_for_performance_losses_time)) {
				if (e->return_direction() == DOWN || e->return_direction()
					== DOWN_LEFT || e->return_direction() == DOWN_LEFT) {
					effects.push_back(new Effect(effects_shooting_i,
						enemy_shot_point_x, enemy_shot_down_point_y,
						Scroll_Shooter_effects_shooting_speed, DOWN,
						Scroll_Shooter_effects_shooting_exist_time));
					bullets.push_back(new Bullet(bullet_bullet_i,
						enemy_shot_point_x, enemy_shot_down_point_y,
						enemy_bullet_speed, DOWN, e->return_damage(),
						enemies_side));
				}
				if (e->return_direction() == UP || e->return_direction()
					== UP_LEFT || e->return_direction() == UP_RIGHT) {
					effects.push_back(new Effect(effects_shooting_i,
						enemy_shot_point_x, enemy_shot_up_point_y,
						Scroll_Shooter_effects_shooting_speed, UP,
						Scroll_Shooter_effects_shooting_exist_time));
					bullets.push_back(new Bullet(bullet_bullet_i,
						enemy_shot_point_x, enemy_shot_up_point_y,
						enemy_bullet_speed, UP, e->return_damage(),
						enemies_side));
				}
			}
			if (e->is_alive() == false || e->get_health() <= 0) {
				if (e->get_health() <= 0) {
					effects.push_back(new Effect(effects_explosion2_i,
						Effects_spawn_x, Effects_spawn_y, background_speed,
						DOWN, effects_explosion2_exist_time));
					it1_enemies_cars = enemies_cars.erase(it1_enemies_cars);
					delete e;
				}
				if (e->is_alive() == false) {
					it1_enemies_cars = enemies_cars.erase(it1_enemies_cars);
					delete e;
				}
			}
			else {
				++it1_enemies_cars;
			}
		}

		for (it_effects = effects.begin(); it_effects != effects.end();) {
			Effect *e = *it_effects;
			
			e->update(Compensating_for_performance_losses_time);
			if (e->is_alive() == false) {
				it_effects = effects.erase(it_effects);
				delete e;
			}
			else ++it_effects;
		}

		for (it_background = background_objects.begin();
			it_background != background_objects.end(); ++it_background) {
			window.draw((*it_background)->get_sprite());
		}

		for (it1_enemies_cars = enemies_cars.begin();
			it1_enemies_cars != enemies_cars.end(); ++it1_enemies_cars) {
			window.draw((*it1_enemies_cars)->get_sprite());
		}

		for (it_effects = effects.begin(); it_effects != effects.end();
			++it_effects) {
			window.draw((*it_effects)->get_sprite());
		}

		for (it_bullets = bullets.begin(); it_bullets != bullets.end();
			++it_bullets) {
			window.draw((*it_bullets)->get_sprite());
		}

		window.draw(player.get_sprite());

		interface_health_and_score_bar.update(player.return_score(),
			player.get_health(), window);

		window.display();
	}

	return 0;
}