#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Player {
public:
	float x, y, w, h, dx, dy, speed = 0;
	int dir;
	String file;
	Image image;
	Texture texture;
	Sprite sprite;

	Player(String File, float X, float Y, float W, float H, float Speed);

	void update(float time);
};
