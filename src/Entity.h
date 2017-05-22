#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Entity {
public:
	float x, y, dx, dy;
	int w, h;
	bool life;
	Texture texture;
	Sprite sprite;

	Entity::Entity(Image &image, float X, float Y, int W, int H) {
		x = X;
		y = Y;
		w = W;
		h = H;
		dx = 0;
		dy = 0;

		life = true;
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setOrigin(w / 2, h / 2);
	}

	virtual int update(float time);

	FloatRect getRect();
};