#include <SFML/Graphics.hpp>
#include <list>
#include <vector>
#include <sstream>
#include <ctime>
#include "Entity.h"
#include "Effects.h"
#include "Enemies.h"
#include "Background.h"
#include "Direction.h"
#include "Interface.h"
#include "Player.h"

#define screen_width 1600
#define screen_hight 900

using namespace sf;

Clock clock1;
Clock game_timer;
Clock background_timer;
Clock enemy_timer;


int main() {
	Image aim_i;
	if (!aim_i.loadFromFile("res/images/aim/aim.png")) {
		return 1;
	}

	Image background_rocksand1_i;
	if(!background_rocksand1_i.loadFromFile("res/images/background/rocksand1.png")) {
		return 1;
	}

	Image background_rocksand2_i;
	if(!background_rocksand2_i.loadFromFile("res/images/background/rocksand2.png")) {
		return 1;
	}

	Image background_rockgray1_i;
	if(!background_rockgray1_i.loadFromFile("res/images/background/rockgray1.png")) {
		return 1;
	}

	Image effects_explosion1_i;
	if (!effects_explosion1_i.loadFromFile("res/images/effects/explosion1.png")) {
		return 1;
	}

	Image effects_explosion2_i;
	if(!effects_explosion2_i.loadFromFile("res/images/effects/explosion2.png")) {
		return 1;
	}

	Image effects_shooting_i;
	if (!effects_shooting_i.loadFromFile("res/images/effects/shooting2.png")) {
		return 1;
	}

	Image enemy_copsjups_i;
	if(!enemy_copsjups_i.loadFromFile("res/images/enemy/copsjups.png")) {
		return 1;
	}

	Image enemy_hammer_i;
	if(!enemy_hammer_i.loadFromFile("res/images/enemy/hammer.png")) {
		return 1;
	}

	Image enemy_lapdcar_i;
	if(!enemy_lapdcar_i.loadFromFile("res/images/enemy/lapdcar.png")) {
		return 1;
	}

	Image background_i;
	if(!background_i.loadFromFile("res/images/background/shooter-background.png")) {
		return 1;
	}
	Texture background_t;
	background_t.loadFromImage(background_i);

	Sprite background_s;
	background_s.setTexture(background_t);
	background_s.setScale(0.4517, 0.6024);

	Image interface_button_i;
	if(!interface_button_i.loadFromFile("res/images/interface/button.png")) {
		return 1;
	}

	Font font;
	if(!font.loadFromFile("res/images/interface/beer_money.ttf")) {
		return 1;
	}

	Text text("", font, 50);
	text.setColor(Color::Black);


	Player player(aim_i, 750, 650, 69, 100, 0.7, 100, 0.5, 20);
	Interface interface_health_and_score_bar(interface_button_i, 1152, 792, 448, 108);

	std::list<Background*>  background_objects;
	std::list<Background*>::iterator it_background;

	std::list<Effects*>  effects;
	std::list<Effects*>::iterator it_effects;

	std::list<Enemies*>  enemies;
	std::list<Enemies*>::iterator it_enemies;

	srand(time(NULL));

	float game_time = game_timer.getElapsedTime().asSeconds();
	float score_time = game_time;
	float enemy_generate_probability = 50000;
	float back_object_generate_probability = 6000;
	float bk_time;
	float enemy_time;
	int enemy_number = 0;

	RenderWindow window(sf::VideoMode(screen_width, screen_hight), "Shooter", Style::Fullscreen);

	while (window.isOpen()){
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			break;
		}

		float time = clock1.getElapsedTime().asMicroseconds();
		clock1.restart();
		time = time / 800;

		if (player.update(time)) {
			break;
		}

		window.clear();
		window.draw(background_s);

		bk_time = background_timer.getElapsedTime().asSeconds();

		back_object_generate_probability = back_object_generate_probability - bk_time * 100 - rand() % 100;

		if (back_object_generate_probability < 0) {
			int r = rand() % 3;
			switch (r) {
			case 0: background_objects.push_back(new Background(background_rocksand1_i, 1800, rand() % 350 + 550, 113, 127)); break;
			case 1: background_objects.push_back(new Background(background_rocksand2_i, 1800, rand() % 350 + 550, 78, 70)); break;
			case 2: background_objects.push_back(new Background(background_rockgray1_i, 1800, rand() % 350 + 550, 93, 65)); break;
			}
			back_object_generate_probability = 6000;
			background_timer.restart();
		}

		game_time = game_timer.getElapsedTime().asSeconds();
		enemy_time = enemy_timer.getElapsedTime().asSeconds();
		enemy_generate_probability = enemy_generate_probability - enemy_time * 10 - rand() % 100;

		if (enemy_generate_probability < 0 && enemy_number < 5) {
			++enemy_number;
			int r = rand() % 3;
			switch (r) {
			case 0: enemies.push_back(new Enemies(enemy_copsjups_i, -200, rand() % 350 + 500, 198, 109, 0.3, 0, 35, 10, 10)); break;
			case 1: enemies.push_back(new Enemies(enemy_hammer_i, -200, rand() % 350 + 500, 198, 109, 0.3, 0, 25, 10, 15)); break;
			case 2: enemies.push_back(new Enemies(enemy_lapdcar_i, -200, rand() % 350 + 500, 198, 109, 0.4, 0, 15, 5, 5)); break;
			}
			enemy_generate_probability = 50000 - game_time * 25;
			if (enemy_generate_probability < 1000) {
				enemy_generate_probability = 1000;
			}
			enemy_timer.restart();
		}

		game_time = game_timer.getElapsedTime().asSeconds();
		player.score = player.score + game_time - score_time;
		score_time = game_time;

		for (it_background = background_objects.begin(); it_background != background_objects.end();){
			Background *b = *it_background;
			b->update(time);
			if (b->life == false) {
				it_background = background_objects.erase(it_background);
				delete b;
			}
			else ++it_background;
		}

		for (it_enemies = enemies.begin(); it_enemies != enemies.end();) {
			Enemies *b = *it_enemies;
			if (b->update(time)) {
				player.health -= b->damage;
				if (player.score > 5) {
					player.score -= 5;
				}
				else {
					player.score = 0;
				}
			}
			if (b->life == false || b->health <= 0) {
				if (b->health <= 0) {
					effects.push_back(new Effects(effects_explosion2_i, b->x, b->y, 151, 150, 0.6, 1, 0.5));
					it_enemies = enemies.erase(it_enemies);
					delete b;
					--enemy_number;
				}
				if (b->life == false) {
					it_enemies = enemies.erase(it_enemies);
					delete b;
					--enemy_number;
				}
			}
			else ++it_enemies;
		}

		if (Keyboard::isKeyPressed(Keyboard::Space) && player.shooting_available) {
			player.shooting_available = false;
			player.shot = true;
			effects.push_back(new Effects(effects_shooting_i, player.x, player.y, 181, 166, 0, 8, 0.1));
			player.attack_frequency_timer = game_timer.getElapsedTime().asSeconds();
		}

		for (it_enemies = enemies.begin(); it_enemies != enemies.end(); ++it_enemies) {
			Enemies *b = *it_enemies;

			if (b->getRect().intersects(player.getRect()) && player.shot){
				b->health -= player.damage;
				effects.push_back(new Effects(effects_explosion1_i, b->x, b->y, 67, 69, 0.6, 1, 0.2));
				player.score += 5;
				}
		}

		player.shot = false;

		for (it_effects = effects.begin(); it_effects != effects.end();) {
			Entity *b = *it_effects;
			b->update(time);
			if (b->life == false) {
				it_effects = effects.erase(it_effects);
				delete b;
			}
			else ++it_effects;
		}


		for (it_background = background_objects.begin(); it_background != background_objects.end(); ++it_background) {
			window.draw((*it_background)->sprite);
		}

		for (it_enemies = enemies.begin(); it_enemies != enemies.end(); ++it_enemies) {
			window.draw((*it_enemies)->sprite);
		}

		for (it_effects = effects.begin(); it_effects != effects.end(); ++it_effects) {
			window.draw((*it_effects)->sprite);
		}

		window.draw(player.sprite);

		interface_health_and_score_bar.update(time);
		window.draw(interface_health_and_score_bar.sprite);

		std::ostringstream playerScoreString;
		playerScoreString << player.score;
		std::ostringstream player_health_string;
		player_health_string << player.health;
		text.setString("Score:" + playerScoreString.str() + "\nHealth:" + player_health_string.str());
		text.setPosition(1200, 780);
		window.draw(text);

		window.display();
	}

	return 0;
}