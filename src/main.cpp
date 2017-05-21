#include <SFML/Graphics.hpp>
#include <list>
#include <vector>
#include <sstream>
#include <ctime>
#include "Background.h"
#include "Bullets.h"
#include "Direction.h"
#include "Entity.h"
#include "Effects.h"
#include "Interface.h"
#include "Player.h"


#define screen_width 1600
#define screen_hight 900

enum { RIGHT, LEFT, DOWN, UP, UP_LEFT, UP_RIGHT, DOWN_RIGHT, DOWN_LEFT, STAY } direction;

sf::Clock clock1;
sf::Clock game_timer;
sf::Clock background_timer;

int main() {
	sf::Image player_i;
	if (!player_i.loadFromFile("res/images/unit/chevroletbattle.png")) {
		return 1;
	}

	sf::Image background_rocksand1_i;
	if(!background_rocksand1_i.loadFromFile("res/images/background/rocksand1.png")) {
		return 1;
	}

	sf::Image background_rocksand2_i;
	if(!background_rocksand2_i.loadFromFile("res/images/background/rocksand2.png")) {
		return 1;
	}

	sf::Image background_rockgray1_i;
	if(!background_rockgray1_i.loadFromFile("res/images/background/rockgray1.png")) {
		return 1;
	}

	sf::Image effects_explosion1_i;
	if (!effects_explosion1_i.loadFromFile("res/images/effects/explosion1.png")) {
		return 1;
	}

	sf::Image effects_explosion2_i;
	if(!effects_explosion2_i.loadFromFile("res/images/effects/explosion2.png")) {
		return 1;
	}

	sf::Image effects_shooting_i;
	if (!effects_shooting_i.loadFromFile("res/images/effects/shooting1.png")) {
		return 1;
	}

	sf::Image background_i;
	if(!background_i.loadFromFile("res/images/background/sandbackground.png")) {
		return 1;
	}
	sf::Texture background_t;
	background_t.loadFromImage(background_i);

	sf::Sprite background_s;
	background_s.setTexture(background_t);
	background_s.setScale(5.8181, 4.9180);

	sf::Image bullet_bullet1_i;
	if (!bullet_bullet1_i.loadFromFile("res/images/bullets/bullet1.png")) {
		return 1;
	}

	sf::Image interface_button_i;
	if(!interface_button_i.loadFromFile("res/images/interface/button.png")) {
		return 1;
	}

	sf::Font font;
	if(!font.loadFromFile("res/font/beer_money.ttf")) {
		return 1;
	}

	sf::Text text("", font, 50);
	text.setColor(sf::Color::Black);


	Player player(player_i, 750, 650, 69, 100, 0.7, 100, 0.25, 20);
	Interface interface_health_and_score_bar(interface_button_i, 1152, 792, 448, 108);

	std::list<Background*>  background_objects;
	std::list<Background*>::iterator it_background;

	std::list<Effects*>  effects;
	std::list<Effects*>::iterator it_effects;

	std::list<Bullets*>  bullets;
	std::list<Bullets*>::iterator it_bullets;

	srand(time(NULL));

	float game_time = game_timer.getElapsedTime().asSeconds();
	float score_time = game_time;
	float back_object_generate_probability = 3000;
	float bk_time;

	sf::RenderWindow window(sf::VideoMode(screen_width, screen_hight), "ScrollShooter", sf::Style::Fullscreen);

	window.setFramerateLimit(60);

	while (window.isOpen()){
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
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
			case 0: background_objects.push_back(new Background(background_rocksand1_i, rand() % (screen_width - 100) + 100, -200, 113, 127)); break;
			case 1: background_objects.push_back(new Background(background_rocksand2_i, rand() % (screen_width - 100) + 100, -200, 78, 70)); break;
			case 2: background_objects.push_back(new Background(background_rockgray1_i, rand() % (screen_width - 100) + 100, -200, 93, 65)); break;
			}
			back_object_generate_probability = 3000;
			background_timer.restart();
		}

		if (player.is_shot) {
			effects.push_back(new Effects(effects_shooting_i, player.x - 20, player.y - player.h / 2, 35, 36, 0, STAY, 0.1));
			bullets.push_back(new Bullets(bullet_bullet1_i, player.x - 20, player.y - player.h / 2, 6, 15, 1, UP, player.damage));
			effects.push_back(new Effects(effects_shooting_i, player.x + 20, player.y - player.h / 2, 35, 36, 0, STAY, 0.1));
			bullets.push_back(new Bullets(bullet_bullet1_i, player.x + 20, player.y - player.h / 2, 6, 15, 1, UP, player.damage));
			player.is_shot = false;
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

		for (it_bullets = bullets.begin(); it_bullets != bullets.end();) {
			Bullets *b = *it_bullets;
			b->update(time);
			if (b->life == false) {
				it_bullets = bullets.erase(it_bullets);
				delete b;
			}
			else ++it_bullets;
		}

		for (it_effects = effects.begin(); it_effects != effects.end();) {
			Effects *e = *it_effects;
			e->update(time);
			if (e->life == false) {
				it_effects = effects.erase(it_effects);
				delete e;
			}
			else ++it_effects;
		}


		for (it_background = background_objects.begin(); it_background != background_objects.end(); ++it_background) {
			window.draw((*it_background)->sprite);
		}

		for (it_effects = effects.begin(); it_effects != effects.end(); ++it_effects) {
			window.draw((*it_effects)->sprite);
		}

		for (it_bullets = bullets.begin(); it_bullets != bullets.end(); ++it_bullets) {
			window.draw((*it_bullets)->sprite);
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