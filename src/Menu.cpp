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

	int mode = 4;
	float button_press_time = game_timer.getElapsedTime().asSeconds();
	bool is_pressed = false;

	int i;

	while (1) {
		window.clear();

		window.draw(background_s);

		for (i = 0; i < 5; ++i)
		{
			button_s.setPosition(menu_plate_x, menu_plate_y);

			window.draw(button_s);
		}

		i = Scroll_Shooter_text;
		text.setString("Scroll Shooter");
		text.setPosition(100, menu_text_y);
		if (mode == Scroll_Shooter_text) {
			text.setColor(sf::Color::Blue);
		}
		else {
			text.setColor(sf::Color::Black);
		}
		window.draw(text);

		i = Shooter_text;
		text.setString("Shooter");
		text.setPosition(150, menu_text_y);
		if (mode == Shooter_text) {
			text.setColor(sf::Color::Blue);
		}
		else {
			text.setColor(sf::Color::Black);
		}
		window.draw(text);

		i = Race_text;
		text.setString("Race");
		text.setPosition(180, menu_text_y);
		if (mode == Race_text) {
			text.setColor(sf::Color::Blue);
		}
		else {
			text.setColor(sf::Color::Black);
		}
		window.draw(text);

		i = Control_text;
		text.setString("Control");
		text.setPosition(180, menu_text_y);
		if (mode == Control_text) {
			text.setColor(sf::Color::Blue);
		}
		else {
			text.setColor(sf::Color::Black);
		}
		window.draw(text);

		i = Exit_text;
		text.setString("Exit");
		text.setPosition(180, menu_text_y);
		if (mode == Exit_text) {
			text.setColor(sf::Color::Blue);
		}
		else {
			text.setColor(sf::Color::Black);
		}
		window.draw(text);

		window.display();

		if (game_timer.getElapsedTime().asSeconds() - button_press_time > pause_between_press) {
			is_pressed = false;
			button_press_time = game_timer.getElapsedTime().asSeconds();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && is_pressed == false) {
			is_pressed = true;
			button_press_time = game_timer.getElapsedTime().asSeconds();
			if (mode > Exit_text) {
				--mode;
			}
			else {
				mode = Scroll_Shooter_text;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && is_pressed == false) {
			is_pressed = true;
			button_press_time = game_timer.getElapsedTime().asSeconds();
			if (mode < Scroll_Shooter_text) {
				++mode;
			}
			else {
				mode = Exit_text;
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