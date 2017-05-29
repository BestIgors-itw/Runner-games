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
#include "Aliases.h"

extern sf::Clock game_timer, Compensating_for_performance_losses_timer, background_timer, hedge_timer;

int Race(sf::RenderWindow & window);