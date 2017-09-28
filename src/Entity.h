#pragma once

#include <SFML/Graphics.hpp>
#pragma once

#include <SFML/Graphics.hpp>
#include <list>
#include "Aliases.h"

class Entity {
public:
	float x, y;
	int w, h;
	bool life;
	sf::Texture texture;
	sf::Sprite sprite;
	Entity(sf::Image &image, float X, float Y, int W, int H) {
		x = X;
		y = Y;
		w = W;
		h = H;

		life = true;
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setOrigin(w / 2, h / 2);
	}

	virtual ~Entity() {}

	virtual int update(float time) = 0;

	sf::FloatRect getRect();
};