#include <SFML/Graphics.hpp>
#include <list>
#include <vector>
#include <sstream>
#include <ctime>
#include "Background.h"
#include "Direction.h"
#include "Effects.h"
#include "Enemies.h"
#include "Entity.h"
#include "Interface.h"
#include "Player.h"
#include "Hedges.h"

#define screen_width 1600
#define screen_hight 900

sf::Clock game_timer;
sf::Clock animation_timer;
sf::Clock background_timer;
sf::Clock hedge_timer;

int main() {
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

	sf::Image hedges_deadcars1_i;
	if (!hedges_deadcars1_i.loadFromFile("res/images/hedges/deadcars1.png")) {
		return 0;
	}

	sf::Image hedges_deadcars2_i;
	if (!hedges_deadcars2_i.loadFromFile("res/images/hedges/deadcars2.png")) {
		return 0;
	}

	sf::Image effects_explosion2_i;
	if (!effects_explosion2_i.loadFromFile("res/images/effects/explosion2.png")) {
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

	sf::Image interface_button_i;
	interface_button_i.loadFromFile("res/images/interface/button.png");

	sf::Font font;
	font.loadFromFile("res/font/beer_money.ttf");
	sf::Text text("", font, 50);
	text.setColor(sf::Color::Black);


	Player player(player_i, 750, 650, 70, 150, 0.5, 100, 0.25, 20);
	Interface interface_health_and_score_bar(interface_button_i, screen_width - 448, screen_hight - 108, 448, 108);

	std::list<Background*> background_objects;
	std::list<Background*>::iterator it_background;

	std::list<Effects*> effects;
	std::list<Effects*>::iterator it_effects;

	std::list<Hedges*> enemies;
	std::list<Hedges*>::iterator it1_enemies, it2_enemies;

	srand(time(NULL));

	float game_time = game_timer.getElapsedTime().asSeconds();
	float score_time = game_time;
	float hedge_generate_probability = 2000;
	float background_object_generate_probability = 3000;
	float bk_time;
	float hedge_time;

	sf::RenderWindow window(sf::VideoMode(screen_width, screen_hight), "Race", sf::Style::Fullscreen);

	window.setFramerateLimit(60);

	while (window.isOpen()){
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			break;
		}

		float time = animation_timer.getElapsedTime().asMicroseconds();
		animation_timer.restart();
		time = time / 800;

		if (player.update(time)) {
			break;
		}

		window.clear();
		window.draw(background_s);

		game_time = game_timer.getElapsedTime().asSeconds();
		bk_time = background_timer.getElapsedTime().asSeconds();
		hedge_time = hedge_timer.getElapsedTime().asSeconds();

		background_object_generate_probability = background_object_generate_probability - bk_time * 100 - rand() % 100;

		if (background_object_generate_probability < 0) {
			int r = rand() % 3;
			switch (r) {
			case 0: background_objects.push_back(new Background(background_rocksand1_i, rand() % screen_width, -200, 113, 127)); break;
			case 1: background_objects.push_back(new Background(background_rocksand2_i, rand() % screen_width, -200, 78, 70)); break;
			case 2: background_objects.push_back(new Background(background_rockgray1_i, rand() % screen_width, -200, 93, 65)); break;
			}
			background_object_generate_probability = 2000;
			background_timer.restart();
		}

		hedge_generate_probability = hedge_generate_probability - hedge_time * 10 - rand() % 100;

		if (hedge_generate_probability < 0) {
			int r = rand() % 2;
			switch (r) {
			case 0: enemies.push_back(new Hedges(hedges_deadcars1_i, rand() % screen_width, -200, 96, 111, 2, 10)); break;
			case 1: enemies.push_back(new Hedges(hedges_deadcars2_i, rand() % screen_width, -200, 96, 111, 2, 20)); break;
			}
			hedge_generate_probability = 3000 - game_time * 25;
			if (hedge_generate_probability < 500) {
				hedge_generate_probability = 500;
			}
			hedge_timer.restart();
		}

		player.score = player.score + game_time - score_time;
		score_time = game_time;

		for (it_background = background_objects.begin(); it_background != background_objects.end(); ++it_background)
		{
			Background *b = *it_background;
			b->update(time);
		}

		for (it_background = background_objects.begin(); it_background != background_objects.end();)
		{
			Background *b = *it_background;
			if (b->life == false) {
				it_background = background_objects.erase(it_background);
				delete b;
			}
			else {
				++it_background;
			}
		}

		for (it1_enemies = enemies.begin(); it1_enemies != enemies.end(); ++it1_enemies)
		{
			Enemies *e = *it1_enemies;
			e->update(time);
		}

		for (it1_enemies = enemies.begin(); it1_enemies != enemies.end(); ++it1_enemies)
		{
			Enemies *e = *it1_enemies;
			if (e->getRect().intersects(player.getRect())) {
				e->life = false;
				effects.push_back(new Effects(effects_explosion2_i, e->x, e->y, 67, 69, 0.6, 2, 0.1));
				player.health -= e->health;
				player.score -= 5;
			}
		}

		for (it1_enemies = enemies.begin(); it1_enemies != enemies.end();)
		{
			Enemies *e = *it1_enemies;
			if (e->life == false) {
				it1_enemies = enemies.erase(it1_enemies);
				delete e;
			}
			else ++it1_enemies;
		}

		for (it_effects = effects.begin(); it_effects != effects.end();  ++it_effects)
		{
			Effects *e = *it_effects;
			e->update(time);
		}

		for (it_effects = effects.begin(); it_effects != effects.end();)
		{
			Effects *e = *it_effects;
			if (e->life == false) {
				it_effects = effects.erase(it_effects);
				delete e;
			}
			else ++it_effects;
		}

		for (it_background = background_objects.begin(); it_background != background_objects.end(); ++it_background) {
			window.draw((*it_background)->sprite);
		}

		for (it1_enemies = enemies.begin(); it1_enemies != enemies.end(); ++it1_enemies) {
			window.draw((*it1_enemies)->sprite);
		}

		window.draw(player.sprite);

		for (it_effects = effects.begin(); it_effects != effects.end(); ++it_effects) {
			window.draw((*it_effects)->sprite);
		}

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