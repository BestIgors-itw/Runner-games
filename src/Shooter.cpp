#include "Shooter.h"

int Shooter(sf::RenderWindow & window) {
	sf::Image aim_i;
	if (!aim_i.loadFromFile("res/images/aim/aim.png")) {
		return 0;
	}

	sf::Image background_rocksand1_i;
	if (!background_rocksand1_i.loadFromFile("res/images/background/rocksand1.png")) {
		return 0;
	}

	sf::Image background_rocksand2_i;
	if (!background_rocksand2_i.loadFromFile("res/images/background/rocksand2.png")) {
		return 0;
	}

	sf::Image background_rockgray1_i;
	if (!background_rockgray1_i.loadFromFile("res/images/background/rockgray1.png")) {
		return 0;
	}

	sf::Image effects_explosion1_i;
	if (!effects_explosion1_i.loadFromFile("res/images/effects/explosion1.png")) {
		return 0;
	}

	sf::Image effects_explosion2_i;
	if (!effects_explosion2_i.loadFromFile("res/images/effects/explosion2.png")) {
		return 0;
	}

	sf::Image effects_shooting_i;
	if (!effects_shooting_i.loadFromFile("res/images/effects/shooting2.png")) {
		return 0;
	}

	sf::Image enemy_copsjups_i;
	if (!enemy_copsjups_i.loadFromFile("res/images/enemy/copsjups.png")) {
		return 0;
	}

	sf::Image enemy_hammer_i;
	if (!enemy_hammer_i.loadFromFile("res/images/enemy/hammer.png")) {
		return 0;
	}

	sf::Image enemy_lapdcar_i;
	if (!enemy_lapdcar_i.loadFromFile("res/images/enemy/lapdcar.png")) {
		return 0;
	}

	sf::Image background_i;
	if (!background_i.loadFromFile("res/images/background/shooter-background.png")) {
		return 0;
	}
	sf::Texture background_t;
	background_t.loadFromImage(background_i);

	sf::Sprite background_s;
	background_s.setTexture(background_t);
	background_s.setScale(Shooter_background_scale_x, Shooter_background_scale_y);

	sf::Font font;
	if (!font.loadFromFile("res/font/beer_money.ttf")) {
		return 0;
	}

	sf::Text text("", font, 50);
	text.setColor(sf::Color::Black);


	Player player(aim_i, player_spawn_x, player_spawn_y, aim_width, aim_hight,
		player_speed, player_health, Shooter_player_time_between_shots,
		Shooter_player_damage_per_shot);

	std::list<Background*>  background_objects;
	std::list<Background*>::iterator it_background;

	std::list<Effects*>  effects;
	std::list<Effects*>::iterator it_effects;

	std::list<Shooter_enemies_cars*>  enemies;
	std::list<Shooter_enemies_cars*>::iterator it_enemies;

	srand(time(NULL));

	float game_time = game_timer.getElapsedTime().asSeconds();
	float score_time = game_time;
	float enemy_generate_probability = Shooter_game_difficulty;
	float background_object_generate_probability = Shooter_background_object_probability;
	float background_time;
	float enemy_time;
	int enemy_number = 0;

	while (window.isOpen())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			break;
		}

		float Compensating_for_performance_losses_time = Compensating_for_performance_losses_timer.getElapsedTime().asMicroseconds();
		Compensating_for_performance_losses_timer.restart();
		Compensating_for_performance_losses_time = Compensating_for_performance_losses_coefficient;

		if (player.update(Compensating_for_performance_losses_time)) {
			break;
		}

		window.clear();
		window.draw(background_s);

		background_time = background_timer.getElapsedTime().asSeconds();

		background_object_generate_probability = background_object_generate_probability - background_time * 100 - rand() % 100;

		if (background_object_generate_probability < 0) {
			int r = rand() % 3;
			switch (r) {
			case 0:
				background_objects.push_back(new Background(background_rocksand1_i,
					Shooter_background_object_spawn_x, Shooter_background_object_spawn_y,
					background_rocksand1_width, background_rocksand1_hight, LEFT));
				break;
			case 1:
				background_objects.push_back(new Background(background_rocksand2_i,
					Shooter_background_object_spawn_x, Shooter_background_object_spawn_y,
					background_rocksand2_width, background_rocksand2_hight, LEFT));
				break;
			case 2:
				background_objects.push_back(new Background(background_rockgray1_i,
					Shooter_background_object_spawn_x, Shooter_background_object_spawn_y,
					background_rockgray1_width, background_rockgray1_hight, LEFT));
				break;
			}
			background_object_generate_probability = Shooter_game_difficulty;
			background_timer.restart();
		}

		game_time = game_timer.getElapsedTime().asSeconds();
		enemy_time = enemy_timer.getElapsedTime().asSeconds();
		enemy_generate_probability = enemy_generate_probability - enemy_time * 100 - rand() % 100;

		if (enemy_generate_probability < 0 && enemy_number < 7) {
			++enemy_number;

			int r = rand() % 3;
			switch (r) {
			case 0:
				enemies.push_back(new Shooter_enemies_cars(enemy_copsjups_i,
					Shooter_enemy_spawn_x, Shooter_enemy_spawn_y, Shooter_enemy_copsjups_width,
					Shooter_enemy_copsjups_hight, Shooter_enemy_copsjups_speed, RIGHT,
					Shooter_enemy_copsjups_health, Shooter_enemy_copsjups_time_between_attack,
					Shooter_enemy_copsjups_damage));
				break;
			case 1:
				enemies.push_back(new Shooter_enemies_cars(enemy_hammer_i,
					Shooter_enemy_spawn_x, Shooter_enemy_spawn_y, Shooter_enemy_hammer_width,
					Shooter_enemy_hammer_hight, Shooter_enemy_hammer_speed, RIGHT,
					Shooter_enemy_hammer_health, Shooter_enemy_hammer_time_between_attack,
					Shooter_enemy_hammer_damage));
				break;
			case 2:
				enemies.push_back(new Shooter_enemies_cars(enemy_lapdcar_i,
					Shooter_enemy_spawn_x, Shooter_enemy_spawn_y, Shooter_enemy_lapdcar_width,
					Shooter_enemy_lapdcar_hight, Shooter_enemy_lapdcar_speed, RIGHT,
					Shooter_enemy_lapdcar_health, Shooter_enemy_lapdcar_time_between_attack,
					Shooter_enemy_lapdcar_damage));
				break;
			}
			enemy_generate_probability = Shooter_game_difficulty - game_time * 25;
			if (enemy_generate_probability < Shooter_max_game_difficulty) {
				enemy_generate_probability = Shooter_max_game_difficulty;
			}
			enemy_timer.restart();
		}

		game_time = game_timer.getElapsedTime().asSeconds();
		player.score = player.score + game_time - score_time;
		score_time = game_time;

		for (it_background = background_objects.begin(); it_background != background_objects.end();)
		{
			Background *b = *it_background;
			b->update(Compensating_for_performance_losses_time);
			if (b->life == false) {
				it_background = background_objects.erase(it_background);
				delete b;
			}
			else ++it_background;
		}

		for (it_enemies = enemies.begin(); it_enemies != enemies.end();)
		{
			Shooter_enemies_cars *e = *it_enemies;
			if (e->update(Compensating_for_performance_losses_time)) {
				player.health -= e->damage;
				if (player.score > 5) {
					player.score -= 5;
				}
				else {
					player.score = 0;
				}
			}
			if (e->life == false || e->health <= 0) {
				if (e->health <= 0) {
					effects.push_back(new Effects(effects_explosion2_i,
						Effects_spawn_x, Effects_spawn_y, effects_explosion2_width, effects_explosion2_hight,
						background_speed, LEFT, effects_explosion2_exist_time));

					player.score += 5;

					it_enemies = enemies.erase(it_enemies);
					delete e;
					--enemy_number;
				}
				if (e->life == false) {
					it_enemies = enemies.erase(it_enemies);
					delete e;
					--enemy_number;
				}
			}
			else ++it_enemies;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && player.is_shot_available) {
			player.is_shot_available = false;
			player.is_shot = true;
			effects.push_back(new Effects(effects_shooting_i,
				Effects_player_spawn_x, Effects_player_spawn_y, Shooter_effects_shooting_width, Shooter_effects_shooting_hight,
				Shooter_effects_shooting_speed, STAY, Shooter_effects_shooting_exist_time));
			player.attack_frequency_time = game_timer.getElapsedTime().asSeconds();
		}

		for (it_enemies = enemies.begin(); it_enemies != enemies.end(); ++it_enemies)
		{
			Shooter_enemies_cars *e = *it_enemies;

			if (e->getRect().intersects(player.getRect()) && player.is_shot) {
				e->health -= player.damage;
				effects.push_back(new Effects(effects_explosion1_i,
					Effects_player_spawn_x, Effects_player_spawn_y, effects_explosion1_width, effects_explosion1_hight,
					background_speed, LEFT, effects_explosion1_exist_time));
			}
		}

		player.is_shot = false;

		for (it_effects = effects.begin(); it_effects != effects.end();)
		{
			Effects *e = *it_effects;
			e->update(Compensating_for_performance_losses_time);
			if (e->life == false) {
				it_effects = effects.erase(it_effects);
				delete e;
			}
			else ++it_effects;
		}


		for (it_background = background_objects.begin(); it_background != background_objects.end(); ++it_background)
		{
			window.draw((*it_background)->sprite);
		}

		for (it_enemies = enemies.begin(); it_enemies != enemies.end(); ++it_enemies)
		{
			window.draw((*it_enemies)->sprite);
		}

		for (it_effects = effects.begin(); it_effects != effects.end(); ++it_effects)
		{
			window.draw((*it_effects)->sprite);
		}

		window.draw(player.sprite);

		std::ostringstream playerScoreString;
		playerScoreString << player.score;
		std::ostringstream player_health_string;
		player_health_string << player.health;
		text.setString("Score:" + playerScoreString.str() + "\nHealth:" + player_health_string.str());
		text.setPosition(interface_text_x, interface_text_y);
		window.draw(text);

		window.display();
	}

	return 0;
}