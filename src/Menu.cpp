#include "Menu.h"

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

		button_s.setPosition(0, screen_hight - 108 - 3 * 110);

		window.draw(button_s);

		button_s.setPosition(0, screen_hight - 108 - 4 * 110);

		window.draw(button_s);

		text.setString("Scroll Shooter");
		text.setPosition(100, screen_hight - 108 - 4 * 110 + 20);
		if (mode == 0) {
			text.setColor(sf::Color::Blue);
		}
		else {
			text.setColor(sf::Color::Black);
		}
		window.draw(text);

		text.setString("Shooter");
		text.setPosition(150, screen_hight - 108 - 3 * 110 + 20);
		if (mode == 1) {
			text.setColor(sf::Color::Blue);
		}
		else {
			text.setColor(sf::Color::Black);
		}
		window.draw(text);

		text.setString("Race");
		text.setPosition(180, screen_hight - 108 - 2 * 110 + 20);
		if (mode == 2) {
			text.setColor(sf::Color::Blue);
		}
		else {
			text.setColor(sf::Color::Black);
		}
		window.draw(text);

		text.setString("Control");
		text.setPosition(180, screen_hight - 108 - 110 + 20);
		if (mode == 3) {
			text.setColor(sf::Color::Blue);
		}
		else {
			text.setColor(sf::Color::Black);
		}
		window.draw(text);

		text.setString("Exit");
		text.setPosition(180, screen_hight - 108 + 20);
		if (mode == 4) {
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
			if (mode < 4) {
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
				mode = 4;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
			return mode;
		}
	}
}

int Control_page(sf::RenderWindow & window){
	sf::Image Control_page_i;
	if (!Control_page_i.loadFromFile("res/images/background/option_menu.png")) {
		return 1;
	}

	sf::Texture Control_page_t;
	Control_page_t.loadFromImage(Control_page_i);

	sf::Sprite Control_page_s;
	Control_page_s.setTexture(Control_page_t);

	sf::Font font;
	if (!font.loadFromFile("res/font/beer_money.ttf")) {
		return 0;
	}

	window.clear();

	window.draw(Control_page_s);

	sf::Text text("", font, 100);

	text.setString("Fire");
	text.setPosition(270, screen_hight - 165);
	text.setColor(sf::Color::Blue);

	window.draw(text);

	text.setCharacterSize(70);

	text.setString("Movement");
	text.setPosition(230, screen_hight - 550);

	window.draw(text);

	text.setString("Press Enter to return");
	text.setPosition(800, screen_hight - 100);
	text.setColor(sf::Color::Green);

	window.draw(text);

	text.setCharacterSize(50);

	text.setString("In shooter mode");
	text.setPosition(200, screen_hight - 280);
	text.setColor(sf::Color::Black);

	window.draw(text);

	window.display();

	while (1) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
			break;
		}
	}

	return 0;
}