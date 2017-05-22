#include <SFML/Graphics.hpp>
#include "Interface.h"
#include "Entity.h"

#define screen_width 1600
#define screen_hight 900

using namespace sf;

	int Interface::update(float time) {
		sprite.setPosition(x + w / 2, y + h / 2);
		return 0;
	};