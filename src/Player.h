#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Player {
public:
	float x, y, w, h, dx, dy, speed = 0;
	int dir;
	String File;
	Image image;
	Texture texture;
	Sprite sprite;

		Player(String F, float X, float Y, float W, float H, float speed);

		void update(float time);
};