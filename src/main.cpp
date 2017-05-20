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
	Clock hedge_timer;

	Image player_i;
	player_i.loadFromFile("res/images/unit/chevroletbattle.png");

	Image background_rocksand1_i;
	background_rocksand1_i.loadFromFile("res/images/background/rocksand1.png");

	Image background_rocksand2_i;
	background_rocksand2_i.loadFromFile("res/images/background/rocksand2.png");

	Image background_rockgray1_i;
	background_rockgray1_i.loadFromFile("res/images/background/rockgray1.png");

	Image hedges_deadcars1_i;
	hedges_deadcars1_i.loadFromFile("res/images/hedges/deadcars1.png");

	Image hedges_deadcars2_i;
	hedges_deadcars2_i.loadFromFile("res/images/hedges/deadcars2.png");

	Image effects_explosion2_i;
	effects_explosion2_i.loadFromFile("res/images/effects/explosion2.png");

	Image interface_button_i;
	interface_button_i.loadFromFile("res/images/interface/button.png");

	Font font;
	font.loadFromFile("res/images/interface/beer_money.ttf");
	Text text("", font, 50);
	text.setColor(Color::Black);


	Player player(player_i, 750, 650, 70, 150, 0.5, 100, "Player");
	Object interface_health_and_score_bar(interface_button_i, 1152, 792, 448, 108, 0, 0, "Interface");

	std::list<Entity*>  entities;
	std::list<Entity*>::iterator it;

	srand(time(NULL));

	float game_time = game_timer.getElapsedTime().asSeconds();
	float score_time = game_time;
	float hedge_generate_probability = 2000;
	float back_object_generate_probability = 3000;
	float bk_time;
	float hedge_time;

	RenderWindow window(sf::VideoMode(screen_width, 800), "ScrollShooter", Style::Fullscreen);

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

		window.clear(Color(250, 228, 153));

		game_time = game_timer.getElapsedTime().asSeconds();
		bk_time = background_timer.getElapsedTime().asSeconds();
		hedge_time = hedge_timer.getElapsedTime().asSeconds();

		back_object_generate_probability = back_object_generate_probability - bk_time * 100 - rand() % 100;

		if (back_object_generate_probability < 0) {
			int r = rand() % 3;
			switch (r) {
			case 0: entities.push_back(new Object(background_rocksand1_i, rand() % screen_width, -200, 113, 127, 0, 0, "Background")); break;
			case 1: entities.push_back(new Object(background_rocksand2_i, rand() % screen_width, -200, 78, 70, 0, 0, "Background")); break;
			case 2: entities.push_back(new Object(background_rockgray1_i, rand() % screen_width, -200, 93, 65, 0, 0, "Background")); break;
			}
			back_object_generate_probability = 2000;
			background_timer.restart();
		}

		hedge_generate_probability = hedge_generate_probability - hedge_time * 10 - rand() % 100;

		if (hedge_generate_probability < 0) {
			int r = rand() % 2;
			switch (r) {
			case 0: entities.push_back(new Object(hedges_deadcars1_i, rand() % screen_width, -200, 96, 111, 0, 0, "Hedge")); break;
			case 1: entities.push_back(new Object(hedges_deadcars2_i, rand() % screen_width, -200, 96, 111, 0, 0, "Hedge")); break;
			}
			hedge_generate_probability = 3000 - game_time * 25;
			if (hedge_generate_probability < 500) {
				hedge_generate_probability = 500;
			}
			hedge_timer.restart();
		}

		player.score = player.score + game_time - score_time;
		score_time = game_time;

		for (it = entities.begin(); it != entities.end(); ++it) {
			(*it)->update(time);
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