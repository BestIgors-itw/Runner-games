#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Entity.h"

#define screen_width 1600
#define screen_hight 900

using namespace sf;

void Player::control()
{
    if (Keyboard::isKeyPressed(Keyboard::Right))
    {
        if (x + w / 2 < screen_width)
        {
            dir = 0;
            sprite.setRotation(2.5);
        }
        else
        {
            dir = 8;
        }
    }

    if (Keyboard::isKeyPressed(Keyboard::Left))
    {
        if (x - w / 2 > 0)
        {
            dir = 1;
            sprite.setRotation(-2.5);
        }
        else
        {
            dir = 8;
        }
    }

    if (Keyboard::isKeyPressed(Keyboard::Down))
    {
        if (y + h / 2 < screen_hight)
        {
            dir = 2;
        }
        else
        {
            dir = 8;
        }
    }

    if (Keyboard::isKeyPressed(Keyboard::Up))
    {
        if (y - h / 2 > 0)
        {
            dir = 3;
        }
        else
        {
            dir = 8;
        }
    }

    if (!(Keyboard::isKeyPressed(Keyboard::Right)) && !(Keyboard::isKeyPressed(Keyboard::Left)))
    {
        sprite.setRotation(0);
    }

    if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Left))
    {
        if (y - h / 2 > 0)
        {
            dir = 3;
            sprite.setRotation(0);
        }
        if (x - w / 2 > 0)
        {
            dir = 1;
            sprite.setRotation(-2.5);
        }
        if (x - w / 2 > 0 && y - h / 2 > 0)
        {
            dir = 4;
        }
    }

    if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Right))
    {
        if (x + w / 2 < screen_width)
        {
            dir = 0;
            sprite.setRotation(2.5);
        }
        if (y - h / 2 > 0)
        {
            dir = 3;
            sprite.setRotation(0);
        }
        if (x + w / 2 < screen_width && y - h / 2 > 0)
        {
            dir = 5;
        }
    }

    if (Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard::Right))
    {
        if (y + h / 2 < screen_hight)
        {
            dir = 2;
            sprite.setRotation(0);
        }
        if (x + w / 2 < screen_width)
        {
            dir = 0;
            sprite.setRotation(2.5);
        }
        if (x + w / 2 < screen_width && y + h / 2 < screen_hight)
        {
            dir = 6;
        }
    }

    if (Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard::Left))
    {
        if (y + h / 2 < screen_hight)
        {
            dir = 2;
            sprite.setRotation(0);
        }
        if (x - w / 2 > 0)
        {
            dir = 1;
            sprite.setRotation(-2.5);
        }
        if (x - w / 2 > 0 && y + h / 2 < screen_hight)
        {
            dir = 7;
        }
    }

    if (!(Keyboard::isKeyPressed(Keyboard::Right)) && !(Keyboard::isKeyPressed(Keyboard::Left)) &&
        !(Keyboard::isKeyPressed(Keyboard::Up)) && !(Keyboard::isKeyPressed(Keyboard::Down)))
    {
        dir = 8;
    }
}

int Player::update(float time)
{
    control();
    switch (dir)
    {
    case 0:
        dx = speed;
        dy = 0;
        break;
    case 1:
        dx = -speed;
        dy = 0;
        break;
    case 2:
        dy = speed;
        dx = 0;
        break;
    case 3:
        dy = -speed;
        dx = 0;
        break;
    case 4:
        dx = -speed;
        dy = -speed;
        break;
    case 5:
        dx = speed;
        dy = -speed;
        break;
    case 6:
        dx = speed;
        dy = speed;
        break;
    case 7:
        dx = -speed;
        dy = speed;
        break;
    case 8:
        dx = 0;
        dy = 0;
        break;
    }
    x += dx * time;
    y += dy * time;

	sprite.setPosition(x, y );
    if (health <= 0)
    {
        return 1;
    }

    return 0;
}
