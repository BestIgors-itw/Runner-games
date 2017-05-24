#include <SFML/Graphics.hpp>
#include <list>
#include <vector>
#include <sstream>
#include <ctime>
#include "Race.h"
#include "Scroll_Shooter.h"

#define screen_width 1600
#define screen_hight 900

sf::Clock game_timer;
sf::Clock animation_timer;
sf::Clock background_timer;
sf::Clock hedge_timer;
sf::Clock enemy_timer;

int menu(sf::RenderWindow & window) {
	sf::Image background_i;
	if (!background_i.loadFromFile("res/images/menu/menuback.png")) {
		return 0;
	}

	sf::Texture background_t;
	background_t.loadFromImage(background_i);

	sf::Sprite background_s;
	background_s.setTexture(background_t);

	sf::Image button_i;
	if (!button_i.loadFromFile("res/images/interface/button.png")) {
		return 0;
	}

	sf::Texture button_t;
	button_t.loadFromImage(button_i);

	sf::Sprite button_s;
	button_s.setTexture(button_t);

	sf::Font font;
	if (!font.loadFromFile("res/font/beer_money.ttf")) {
		return 0;
	}

	sf::Text text("", font, 50);
	text.setColor(sf::Color::Black);

	int mode = 0;
	float button_press_time = game_timer.getElapsedTime().asSeconds();
	bool is_pressed = false;

	while (1) {
		window.clear();

		window.draw(background_s);

		button_s.setPosition(0, screen_hight - 108);

		window.draw(button_s);

		button_s.setPosition(0, screen_hight - 108 - 110);

		window.draw(button_s);

		button_s.setPosition(0, screen_hight - 108 - 2 * 110);

		window.draw(button_s);

		text.setString("Scroll Shooter");
		text.setPosition(180, screen_hight - 108 - 2 * 110 + 20);
		if (mode == 0) {
			text.setColor(sf::Color::Blue);
		}
		else {
			text.setColor(sf::Color::Black);
		}
		window.draw(text);

		text.setString("Race");
		text.setPosition(180, screen_hight - 108 - 110 + 20);
		if (mode == 1) {
			text.setColor(sf::Color::Blue);
		}
		else {
			text.setColor(sf::Color::Black);
		}
		window.draw(text);

		text.setString("Exit");
		text.setPosition(180, screen_hight - 108 + 20);
		if (mode == 2) {
			text.setColor(sf::Color::Blue);
		}
		else {
			text.setColor(sf::Color::Black);
		}
		window.draw(text);

		window.display();

		if (game_timer.getElapsedTime().asSeconds() - button_press_time > 0.25) {
			is_pressed = false;
			button_press_time = game_timer.getElapsedTime().asSeconds();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && is_pressed == false) {
			is_pressed = true;
			button_press_time = game_timer.getElapsedTime().asSeconds();
			if (mode < 2) {
				++mode;
			}
			else {
				mode = 0;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && is_pressed == false) {
			is_pressed = true;
			button_press_time = game_timer.getElapsedTime().asSeconds();
			if (mode > 0) {
				--mode;
			}
			else {
				mode = 2;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
			switch (mode) {
			case 0:
				return 2;
				break;
			case 1:
				return 1;
				break;
			case 2:
				return 0;
				break;
			}
		}
	}
}

int main() {
	sf::RenderWindow window(sf::VideoMode(screen_width, screen_hight), "Runner games", sf::Style::Fullscreen);

	window.setFramerateLimit(60);

	while (1) {
		switch (menu(window)) {
		case 0:
			return 0;
			break;
		case 1:
			Race(window);
			break;
		case 2:
			Scroll_Shooter(window);
			break;
		default:
			break;
		}
	}

	return 0;
}