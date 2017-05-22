#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Object.h"

#define screen_width 1600
#define screen_hight 900

using namespace sf;

	int Object::update(float time) {
		if (name == "Background") {
			x += dx * time;
			sprite.setPosition(x + w / 2, y + h / 2);
			if (x + w < 0) {
				life = false;
			}
		}
		if (name == "Effect") {
			x += dx * time;
			sprite.setPosition(x + w / 2, y + h / 2);
			if (x + w < 0 || health <= 0) {
				life = false;
			}
			else {
				--health;
			}
		}
		if (name == "Enemy") {
			x += dx * time;
			sprite.setPosition(x + w / 2, y + h / 2);
			if (x > screen_width || health <= 0) {
				life = false;
			}
		}
		if (name == "Interface") {
			sprite.setPosition(x + w / 2, y + h / 2);
			if (health) {
				sprite.setRotation(5);
				sprite.setRotation(0);
				sprite.setRotation(-5);
				sprite.setRotation(0);
				--health;
			}
		}
		return 0;
	}