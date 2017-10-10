#pragma once

#include <SFML/Graphics.hpp>
#pragma once

#include <SFML/Graphics.hpp>
#include <list>
#include "Aliases.h"

class Entity {
protected:
	float x, y;
	unsigned short int w, h;
	bool alive;
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Entity(sf::Image &image, float X, float Y, int W, int H) {
		x = X;
		y = Y;
		w = W;
		h = H;

		alive = true;
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setOrigin(w / 2, h / 2);
	}

	virtual ~Entity() {}

	virtual int update(float) = 0;

	sf::FloatRect get_rect();

	bool is_alive();

	unsigned short int get_w();
	unsigned short int get_h();

	float get_x();
	float get_y();

	sf::Sprite get_sprite();

	void kill_object();
};