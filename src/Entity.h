#pragma once

#include "Entity.h"

using namespace sf;

class Entity
{
  public:
    float dx, dy, x, y, speed;
    int w, h, health, dir;
    bool life;
    Texture texture;
    Sprite sprite;
    String name;

    Entity(Image &image, float X, float Y, int W, int H, float Speed, float Health, String Name);

    virtual int update(float time) = 0;

    FloatRect getRect();
};
