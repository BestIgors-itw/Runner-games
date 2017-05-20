#include "Entity.h"
#include "Object.h"
#include "Player.h"

using namespace sf;

FloatRect Entity::getRect()
{
    return FloatRect(x, y, w, h);
}

int Entity::update(float time) {
	return 0;
}