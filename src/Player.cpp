#include <iostream> 
#include <SFML/Graphics.hpp>
#include "Player.h"


using namespace sf;

	Player::Player(String F, float X, float Y, float W, float H, float speed) {
		File = F;
		w = W; h = H;
		image.loadFromFile("res/images/" + File);
		image.createMaskFromColor(Color(255, 255, 255));
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		x = X; y = Y;
	}

	void Player::update (float time)
	{
		switch (dir) {
		case 0: dx = speed; break;
		case 1: dx = -speed; break;
		case 2: dy = speed; break;
		case 3: dy = -speed; break;
		default: dx = 0; dy = 0; break;
		}

		x += dx * time;
		y += dy * time;

		sprite.setPosition(x, y);
		dy = 0;
		dx = 0;
		dir = -1;
	}