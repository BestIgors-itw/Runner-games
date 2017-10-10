#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include <sstream>
#include "Player.h"

class Interface : public Entity {
private:
	sf::Text text;
public:
	Interface(sf::Image &IMAGE, float X, float Y, sf::Text TEXT) :Entity(IMAGE, X, Y) {
		sprite.setPosition(x + w / 2, y + h / 2);
		text = TEXT;
	}

	int update(float TIME);
	int update(float PLAYER_SCORE, float PLAYER_HEALTH, sf::RenderWindow & WINDOW);
};

