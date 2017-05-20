#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Entity.h"

#define screen_width 1600
#define screen_hight 900

using namespace sf;

int Object::update(float time)
{
    if (name == "Background")
    {
        y += dy * time;
        sprite.setPosition(x + w / 2, y + h / 2);
        if (y - h / 2 > screen_hight)
        {
            life = false;
        }
    }
    if (name == "Hedge")
    {
        y += dy * time;
        sprite.setPosition(x + w / 2, y + h / 2);
        if (y - h / 2 > screen_hight)
        {
            life = false;
        }
    }
    if (name == "Effect")
    {
        y += dy * time;
        sprite.setPosition(x + w / 2, y + h / 2);
        if (y - h / 2 > screen_hight || health <= 0)
        {
            life = false;
        }
        else
        {
            --health;
        }
    }
	if (name == "Interface")
	{
		sprite.setPosition(x + w / 2, y + h / 2);
	}
    return 0;
}
