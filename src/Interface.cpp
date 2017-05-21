#include "Entity.h"
#include "Interface.h"

int Interface::update(float time) {
	sprite.setPosition(x + w / 2, y + h / 2);
	return 0;
}
