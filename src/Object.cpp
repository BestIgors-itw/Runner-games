#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Object.h"

using namespace sf;

extern int screen_hight;

void  Object::update(float time) {
	if (name == "Background") {
		y += dy * time;
		sprite.setPosition(x + w / 2, y + h / 2);
		if (y - h / 2 > screen_hight) {
			life = false;
		}
	}
}