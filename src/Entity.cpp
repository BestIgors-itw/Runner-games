#include <SFML/Graphics.hpp>
#include "Entity.h"

using namespace sf;

Entity::Entity(Image &image, float X, float Y, int W, int H, float Speed, float Health, String Name)
{
    x = X;
    y = Y;
    w = W;
    h = H;
    name = Name;
    speed = Speed;
    health = Health;
    dx = 0;
    dy = 0;
    life = true;
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    sprite.setOrigin(w / 2, h / 2);
}

FloatRect Entity::getRect()
{
    return FloatRect(x, y, w, h);
}