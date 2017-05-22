#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.h"

using namespace sf;

class Entity {
public:
	float dx, dy, x, y, speed;
	int w, h, health, dir;
	bool life;
	Texture texture;
	Sprite sprite;
	String name;
	Entity::Entity(Image &image, float X, float Y, int W, int H, float Speed, float Health, String Name) {
		x = X;
		y = Y;
		w = W;
		h = H;
		name = Name;
		speed = Speed;
		health = Health;
		dx = 0;
		dy = 0;
		life = true;
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setOrigin(w / 2, h / 2);
	};

	virtual int update(float time);

	FloatRect getRect();
};
