#include <SFML/Graphics.hpp>
#include <list>
#include <vector>
#include <sstream>
#include <ctime>
#include "Entity.h"
#include "Object.h"
#include "Player.h"

#define screen_width 1600
#define screen_hight 900

using namespace sf;

int main() {
	Clock game_timer;
	Clock clock;
	Clock background_timer;
	Clock enemy_timer;

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

	Image effects_explosion2_i;
	if(!effects_explosion2_i.loadFromFile("res/images/effects/explosion2.png")) {
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


	Player player(aim_i, 750, 650, 69, 100, 0.7, 100, "Player");
	Object interface_health_and_score_bar(interface_button_i, 1152, 792, 448, 108, 0, 0, "Interface");

	std::list<Entity*>  entities;
	std::list<Entity*>::iterator it;

	srand(time(NULL));

	float game_time = game_timer.getElapsedTime().asSeconds();
	float score_time = game_time;
	float enemy_generate_probability = 50000;
	float back_object_generate_probability = 6000;
	float bk_time;
	float enemy_time;

	RenderWindow window(sf::VideoMode(screen_width, screen_hight), "Shooter", Style::Fullscreen);

	while (window.isOpen()){
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			break;
		}

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;

		if (player.update(time)) {
			break;
		}

		window.clear();
		window.draw(background_s);

		game_time = game_timer.getElapsedTime().asSeconds();
		bk_time = background_timer.getElapsedTime().asSeconds();
		enemy_time = enemy_timer.getElapsedTime().asSeconds();

		back_object_generate_probability = back_object_generate_probability - bk_time * 100 - rand() % 100;

		if (back_object_generate_probability < 0) {
			int r = rand() % 3;
			switch (r) {
			case 0: entities.push_back(new Object(background_rocksand1_i, 1800, rand() % 450 + 450, 113, 127, 0, 0, "Background")); break;
			case 1: entities.push_back(new Object(background_rocksand2_i, 1800, rand() % 450 + 450, 78, 70, 0, 0, "Background")); break;
			case 2: entities.push_back(new Object(background_rockgray1_i, 1800, rand() % 450 + 450, 93, 65, 0, 0, "Background")); break;
			}
			back_object_generate_probability = 6000;
			background_timer.restart();
		}

		enemy_generate_probability = enemy_generate_probability - enemy_time * 10 - rand() % 100;

		if (enemy_generate_probability < 0) {
			int r = rand() % 3;
			switch (r) {
			case 0: entities.push_back(new Object(enemy_copsjups_i, -200, rand() % 350 + 450, 198, 109, 0.3, 70, "Enemy")); break;
			case 1: entities.push_back(new Object(enemy_hammer_i, -200, rand() % 350 + 450, 198, 109, 0.3, 50, "Enemy")); break;
			case 2: entities.push_back(new Object(enemy_lapdcar_i, -200, rand() % 350 + 450, 198, 109, 0.4, 30, "Enemy")); break;
			}
			enemy_generate_probability = 50000 - game_time * 25;
			if (enemy_generate_probability < 1000) {
				enemy_generate_probability = 1000;
			}
			enemy_timer.restart();
		}

		player.score = player.score + game_time - score_time;
		score_time = game_time;

		for (it = entities.begin(); it != entities.end();){
			Entity *b = *it;
			b->update(time);
			if (b->life == false) {
				it = entities.erase(it);
				delete b;
			}
			else ++it;
		}

		for (it = entities.begin(); it != entities.end(); it++)
		{
			if ((*it)->getRect().intersects(player.getRect())){
				if (((*it)->name == "Enemy") && (Keyboard::isKeyPressed(Keyboard::Space))) {
					(*it)->life = false;
					entities.push_back(new Object(effects_explosion2_i, (*it)->x, (*it)->y, 67, 69, 0, 100, "Effect"));
					player.score += 5;
				}
			}
		}

		for (it = entities.begin(); it != entities.end(); ++it) {
			window.draw((*it)->sprite);
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