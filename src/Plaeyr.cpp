#include <SFML/Graphics.hpp>
#include <list>
#include <vector>
#include "Entity.h"
#include "Player.h"

using namespace sf;

void Player::control(void) {
	if (Keyboard::isKeyPressed(Keyboard::Right)) {
		dir = 0;
		sprite.setRotation(2.5);
	}

	if (Keyboard::isKeyPressed(Keyboard::Left)) {
		dir = 1;
		sprite.setRotation(-2.5);
	}

		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			dir = 2;
		}

		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			dir = 3;
		}

		if (!(Keyboard::isKeyPressed(Keyboard::Right)) && !(Keyboard::isKeyPressed(Keyboard::Left))) {
			sprite.setRotation(0);
		}

		if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Left)) {
			dir = 4;
		}

		if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Right)) {
			dir = 5;
		}

		if (Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard::Right)) {
			dir = 6;
		}

		if (Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard::Left)) {
			dir = 7;
		}

		if (!(Keyboard::isKeyPressed(Keyboard::Right)) && !(Keyboard::isKeyPressed(Keyboard::Left)) && !(Keyboard::isKeyPressed(Keyboard::Up))
			&& !(Keyboard::isKeyPressed(Keyboard::Down))) {
			dir = 8;
		}
	}

	void Player::update(float time) {
		control();
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
		if (health <= 0) {
			exit(0);
		}
	}