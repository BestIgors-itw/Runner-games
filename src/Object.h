#pragma once

#include "Entity.h"

using namespace sf;

class Object : public Entity
{
  public:
	 Object::Object(Image &image, float X, float Y, int W, int H, float Speed, float Health, String Name) : 
		 Entity(image, X, Y, W, H, Speed, Health, Name)
	  {
		  dy = 0.6;
	  };

    int update(float time);

};
