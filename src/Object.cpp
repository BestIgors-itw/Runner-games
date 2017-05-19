#include <iostream> 
#include <SFML/Graphics.hpp>
#include "Object.h"

using namespace sf;

Object::Object(String File, float X, float Y, float W, float H, float Speed) {
	file = File;
	w = W; h = H;
	speed = Speed;
	x = X; y = Y;
	image.loadFromFile("res/images/" + file);

	texture.loadFromImage(image);
	sprite.setTexture(texture);
}

void Object::movement(float time) {
	switch (dir) {
	case 0: dx = speed; dy = 0; break;
	case 1: dx = -speed; dy = 0; break;
	case 2: dy = speed; dx = 0; break;
	case 3: dy = -speed; dx = 0; break;
	case 4: dx = -speed; dy = -speed; break;
	case 5: dx = speed; dy = -speed; break;
	case 6: dx = speed; dy = speed; break;
	case 7: dx = -speed; dy = speed; break;
	case 8: dx = 0; dy = 0; break;
	}

	x += dx * time;
	y += dy * time;

	sprite.setPosition(x, y);
}