#include "Interface.h"

int Interface::update(float TIME) {
	return 0;
}

int Interface::update(float PLAYER_SCORE, float PLAYER_HEALTH,
	sf::RenderWindow &WINDOW) {
	std::ostringstream player_score_string;
	player_score_string << PLAYER_SCORE;
	std::ostringstream player_health_string;
	player_health_string << PLAYER_HEALTH;

	text.setString("Score:" + player_score_string.str() + "\nHealth:"
		+ player_health_string.str());
	text.setPosition(interface_text_x, interface_text_y);

	WINDOW.draw(sprite);
	WINDOW.draw(text);

	return 0;
}