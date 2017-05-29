#include <SFML/Graphics.hpp>
#include <list>
#include <vector>
#include <sstream>
#include <ctime>
#include "Race.h"
#include "Scroll_Shooter.h"
#include "Shooter.h"
#include "Menu.h"

#define screen_width 1600
#define screen_hight 900

sf::Clock game_timer;
sf::Clock animation_timer;
sf::Clock background_timer;
sf::Clock hedge_timer;
sf::Clock enemy_timer;

int main() {
	sf::RenderWindow window(sf::VideoMode(screen_width, screen_hight), "Runner games", sf::Style::Fullscreen);

	window.setFramerateLimit(60);

	while (1) {
		switch (menu(window)) {
		case 0:
			Scroll_Shooter(window);
			break;
		case 1:
			Shooter(window);
			break;
		case 2:
			Race(window);
			break;
		case 3:
			Control_page(window);
			break;
		case 4:
			return 0;
			break;
		default:
			break;
		}
	}

	return 0;
}