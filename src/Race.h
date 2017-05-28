#pragma once

#include <SFML/Graphics.hpp>
#include <list>
#include <vector>
#include <sstream>
#include <ctime>
#include "Background.h"
#include "Bullets.h"
#include "Direction.h"
#include "Effects.h"
#include "Hedges.h"
#include "Entity.h"
#include "Interface.h"
#include "Player.h"

#define screen_width 1600
#define screen_hight 900

extern sf::Clock game_timer, animation_timer, background_timer, hedge_timer;

int Race(sf::RenderWindow & window);