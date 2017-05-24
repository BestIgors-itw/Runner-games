#include "Scroll_Shooter.h"

int Scroll_Shooter(sf::RenderWindow & window) {
	sf::Image player_i;
	if (!player_i.loadFromFile("res/images/unit/chevroletbattle.png")) {
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
	if (!effects_shooting_i.loadFromFile("res/images/effects/shooting.png")) {
		return 0;
	}

	sf::Image enemy_battlemule_i;
	if (!enemy_battlemule_i.loadFromFile("res/images/enemy/battlemule.png")) {
		return 0;
	}

	sf::Image enemy_impalabattle_i;
	if (!enemy_impalabattle_i.loadFromFile("res/images/enemy/impalabattle.png")) {
		return 0;
	}

	sf::Image enemy_slage_i;
	if (!enemy_slage_i.loadFromFile("res/images/enemy/slage.png")) {
		return 0;
	}

	sf::Image background_i;
	if (!background_i.loadFromFile("res/images/background/sandbackground.png")) {
		return 0;
	}
	sf::Texture background_t;
	background_t.loadFromImage(background_i);

	sf::Sprite background_s;
	background_s.setTexture(background_t);
	background_s.setScale(5.8181, 4.9180);

	sf::Image bullet_bullet_i;
	if (!bullet_bullet_i.loadFromFile("res/images/bullets/bullet.png")) {
		return 0;
	}

	sf::Image button_i;
	if (!button_i.loadFromFile("res/images/interface/button.png")) {
		return 0;
	}

	sf::Font font;
	if (!font.loadFromFile("res/font/beer_money.ttf")) {
		return 0;
	}

	sf::Text text("", font, 50);
	text.setColor(sf::Color::Black);


	Player player(player_i, 750, 650, 69, 150, 0.7, 100, 0.25, 20);
	Interface interface_health_and_score_bar(button_i, 1152, 792, 448, 108);

	std::list<Background*>  background_objects;
	std::list<Background*>::iterator it_background;

	std::list<Effects*>  effects;
	std::list<Effects*>::iterator it_effects;

	std::list<Bullets*>  bullets;
	std::list<Bullets*>::iterator it_bullets;

	std::list<Enemies_cars*>  enemies_cars;
	std::list<Enemies_cars*>::iterator it1_enemies_cars, it2_enemies_cars;

	srand(time(NULL));

	float game_time = game_timer.getElapsedTime().asSeconds();
	float score_time = game_time;
	float enemy_generate_probability = 5000;
	float back_object_generate_probability = 3000;
	float bk_time;
	float enemy_time;

	while (window.isOpen()) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			break;
		}

		float animation_time = animation_timer.getElapsedTime().asMicroseconds();
		animation_timer.restart();
		animation_time = animation_time / 800;

		if (player.update(animation_time)) {
			break;
		}

		window.clear();
		window.draw(background_s);

		bk_time = background_timer.getElapsedTime().asSeconds();

		back_object_generate_probability = back_object_generate_probability - bk_time * 100 - rand() % 100;

		if (back_object_generate_probability < 0) {
			int r = rand() % 3;
			switch (r) {
			case 0:
				background_objects.push_back(new Background(background_rocksand1_i,
					rand() % (screen_width - 100) + 100, -200, 113, 127));
				break;
			case 1:
				background_objects.push_back(new Background(background_rocksand2_i,
					rand() % (screen_width - 100) + 100, -200, 78, 70));
				break;
			case 2: background_objects.push_back(new Background(background_rockgray1_i,
				rand() % (screen_width - 100) + 100, -200, 93, 65));
				break;
			}
			back_object_generate_probability = 3000;
			background_timer.restart();
		}

		game_time = game_timer.getElapsedTime().asSeconds();
		enemy_time = enemy_timer.getElapsedTime().asSeconds();
		enemy_generate_probability = enemy_generate_probability - enemy_time * 10 - rand() % 100;

		if (enemy_generate_probability < 0) {
			int r = rand() % 8;
			switch (r) {
			case 0:
				enemies_cars.push_back(new Enemies_cars(enemy_battlemule_i,
					rand() % (screen_width - 100) + 100, -200, 90, 150, 0.15, 2, 25, 0.7, 5));
				break;
			case 1:
				enemies_cars.push_back(new Enemies_cars(enemy_impalabattle_i,
					rand() % (screen_width - 100) + 100, -200, 70, 150, 0.2, 2, 15, 0.7, 5));
				break;
			case 2:
				enemies_cars.push_back(new Enemies_cars(enemy_slage_i,
					rand() % (screen_width - 100) + 100, -300, 142, 295, 0.15, 2, 45, 2, 15));
				break;
			case 3:
				enemies_cars.push_back(new Enemies_cars(enemy_battlemule_i,
					rand() % (screen_width - 100) + 100, screen_hight + 200, 90, 150, 0.15, 3, 25, 0.7, 5));
				break;
			case 4:
				enemies_cars.push_back(new Enemies_cars(enemy_impalabattle_i,
					rand() % (screen_width - 100) + 100, screen_hight + 200, 70, 150, 0.2, 3, 15, 0.7, 5));
				break;
			case 5:
				enemies_cars.push_back(new Enemies_cars(enemy_slage_i,
					rand() % (screen_width - 100) + 100, screen_hight + 200, 142, 295, 0.15, 3, 45, 2, 15));
				break;
			}
			enemy_generate_probability = 5000 - game_time * 25;
			if (enemy_generate_probability < 1000) {
				enemy_generate_probability = 1000;
			}
			enemy_timer.restart();
		}

		if (player.is_shot_available == true) {
			effects.push_back(new Effects(effects_shooting_i, player.x - 20, player.y - player.h / 2, 35, 36, 0, 8, 0.1));
			bullets.push_back(new Bullets(bullet_bullet_i, player.x - 20, player.y - player.h / 2, 6, 15, 1, 3, player.damage));
			effects.push_back(new Effects(effects_shooting_i, player.x + 20, player.y - player.h / 2, 35, 36, 0, 8, 0.1));
			bullets.push_back(new Bullets(bullet_bullet_i, player.x + 20, player.y - player.h / 2, 6, 15, 1, 3, player.damage));
			player.is_shot_available = false;
			player.attack_frequency_time = game_timer.getElapsedTime().asSeconds();
		}

		game_time = game_timer.getElapsedTime().asSeconds();
		player.score = player.score + game_time - score_time;
		score_time = game_time;

		for (it_background = background_objects.begin(); it_background != background_objects.end();) {
			Background *b = *it_background;
			b->update(animation_time);
			if (b->life == false) {
				it_background = background_objects.erase(it_background);
				delete b;
			}
			else ++it_background;
		}

		for (it1_enemies_cars = enemies_cars.begin(); it1_enemies_cars != enemies_cars.end(); ++it1_enemies_cars) {
			Enemies_cars *e1 = *it1_enemies_cars;
			for (it2_enemies_cars = enemies_cars.begin(); it2_enemies_cars != enemies_cars.end(); ++it2_enemies_cars) {
				Enemies_cars *e2 = *it2_enemies_cars;
				if (e1 != e2) {
					if (e1->getRect().intersects(e2->getRect())) {
						e1->health = 0;
						e2->health = 0;
					}
				}
			}
		}

		for (it_bullets = bullets.begin(); it_bullets != bullets.end();) {
			Bullets *b = *it_bullets;
			for (it1_enemies_cars = enemies_cars.begin(); it1_enemies_cars != enemies_cars.end(); ++it1_enemies_cars) {
				Enemies_cars *e = *it1_enemies_cars;
				if (b->getRect().intersects(e->getRect())) {
					e->health -= b->damage;
					effects.push_back(new Effects(effects_explosion1_i, b->x, b->y, 67, 69, 0.6, 2, 0.1));
					player.score += 1;
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
			Bullets *b = *it_bullets;
			if (b->getRect().intersects(player.getRect())) {
				effects.push_back(new Effects(effects_explosion1_i, player.x, player.y, 67, 69, 0.6, 2, 0.1));
				player.health -= b->damage;
				player.score -= 5;
				it_bullets = bullets.erase(it_bullets);
				delete b;
			}
			else {
				++it_bullets;
			}
		}

		for (it1_enemies_cars = enemies_cars.begin(); it1_enemies_cars != enemies_cars.end();) {
			Enemies_cars *b = *it1_enemies_cars;
			if (b->getRect().intersects(player.getRect())) {
				effects.push_back(new Effects(effects_explosion2_i, player.x, player.y, 67, 69, 0.6, 2, 0.1));
				player.health -= b->health;
				player.score -= 5;
				it1_enemies_cars = enemies_cars.erase(it1_enemies_cars);
				delete b;
			}
			else {
				++it1_enemies_cars;
			}
		}

		for (it_bullets = bullets.begin(); it_bullets != bullets.end();) {
			Bullets *b = *it_bullets;
			b->update(animation_time);
			if (b->life == false) {
				it_bullets = bullets.erase(it_bullets);
				delete b;
			}
			else ++it_bullets;
		}

		for (it1_enemies_cars = enemies_cars.begin(); it1_enemies_cars != enemies_cars.end();) {
			Enemies_cars *e = *it1_enemies_cars;
			if (e->update(animation_time)) {
				if (e->direction == 2 || e->direction == 6 || e->direction == 7) {
					effects.push_back(new Effects(effects_shooting_i, e->x + e->w / 2,
						e->y + e->h, 35, 36, 0, 8, 0.1));
					bullets.push_back(new Bullets(bullet_bullet_i, e->x + e->w / 2,
						e->y + e->h, 6, 15, 0.5, 2, e->damage));
				}
				if (e->direction == 3 || e->direction == 4 || e->direction == 5) {
					effects.push_back(new Effects(effects_shooting_i, e->x + e->w / 2,
						e->y - 20, 35, 36, 0, 8, 0.1));
					bullets.push_back(new Bullets(bullet_bullet_i, e->x + e->w / 2,
						e->y - 20, 6, 15, 0.5, 3, e->damage));
				}
			}
			if (e->life == false || e->health <= 0) {
				if (e->health <= 0) {
					effects.push_back(new Effects(effects_explosion2_i, e->x,
						e->y, 151, 150, 0.6, 2, 0.5));
					it1_enemies_cars = enemies_cars.erase(it1_enemies_cars);
					delete e;
				}
				if (e->life == false) {
					it1_enemies_cars = enemies_cars.erase(it1_enemies_cars);
					delete e;
				}
			}
			else {
				++it1_enemies_cars;
			}
		}

		for (it_effects = effects.begin(); it_effects != effects.end();) {
			Effects *e = *it_effects;
			e->update(animation_time);
			if (e->life == false) {
				it_effects = effects.erase(it_effects);
				delete e;
			}
			else ++it_effects;
		}

		for (it_background = background_objects.begin(); it_background != background_objects.end(); ++it_background) {
			window.draw((*it_background)->sprite);
		}

		for (it1_enemies_cars = enemies_cars.begin(); it1_enemies_cars != enemies_cars.end(); ++it1_enemies_cars) {
			window.draw((*it1_enemies_cars)->sprite);
		}

		for (it_effects = effects.begin(); it_effects != effects.end(); ++it_effects) {
			window.draw((*it_effects)->sprite);
		}

		for (it_bullets = bullets.begin(); it_bullets != bullets.end(); ++it_bullets) {
			window.draw((*it_bullets)->sprite);
		}

		window.draw(player.sprite);

		interface_health_and_score_bar.update(animation_time);
		window.draw(interface_health_and_score_bar.sprite);

		std::ostringstream playerScoreString;
		playerScoreString << player.score;
		std::ostringstream player_health_string;
		player_health_string << player.health;
		text.setString("Score:" + playerScoreString.str() + "\nHealth:" + player_health_string.str());
		text.setPosition(screen_width - 400, screen_hight - 120);
		window.draw(text);

		window.display();
	}

	return 0;
}