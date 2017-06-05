#include <SFML/Graphics.hpp>
#include <list>
#include <vector>
#include <sstream>
#include <ctime>
#include "Race.h"
#include "Scroll_Shooter.h"
#include "Shooter.h"
#include "Aliases.h"
#include "Menu.h"

sf::Clock game_timer;
sf::Clock Compensating_for_performance_losses_timer;
sf::Clock background_timer;
sf::Clock hedge_timer;
sf::Clock enemy_timer;

int main() {
	sf::RenderWindow window(sf::VideoMode(screen_width, screen_hight), "Runner games", sf::Style::Fullscreen);

	window.setFramerateLimit(60);

	window.setVerticalSyncEnabled(1);

	while (1) {
		switch (menu(window)) {
		case 4:
			Scroll_Shooter(window);
			break;
		case 3:
			Race(window);
			break;
		case 2:
			Shooter(window);
			break;
		case 1:
			Control_page(window);
			break;
		case 0:
			return 0;
			break;
		default:
			break;
		}
	}

	return 0;
}