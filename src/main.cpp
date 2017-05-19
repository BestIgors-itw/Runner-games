#include <SFML/Graphics.hpp>
#include <list>
#include <vector>
#include "Entity.h"
#include "Object.h"
#include "Player.h"

using namespace sf;

int screen_width = 1600, screen_hight = 900;


int main() {
	RenderWindow window(sf::VideoMode(screen_width, screen_hight), "ScrollShooter", Style::Fullscreen);

	Clock clock;

	Image player_i;
	player_i.loadFromFile("res/images/unit/chevroletbattle.png");

	Image background_rocksand1_i;
	background_rocksand1_i.loadFromFile("res/images/hedges/rocksand1.png");

	Image background_rocksand2_i;
	background_rocksand2_i.loadFromFile("res/images/hedges/rocksand2.png");

	Image background_rockgray1_i;
	background_rockgray1_i.loadFromFile("res/images/hedges/rockgray1.png");

	Player player(player_i, 750, 650, 70, 150, 0.5, 100, "Player");

	std::list<Entity*>  entities;
	std::list<Entity*>::iterator it;

	int object_generate_probability;

	while (window.isOpen())
	{
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			window.close();
		}

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;

		player.update(time);

		window.clear(Color(214, 168, 48));

		object_generate_probability = rand() % 20;

		if (object_generate_probability == 0) {
			object_generate_probability = rand() % 3;
			switch (object_generate_probability) {
			case 0: entities.push_back(new Object(background_rocksand1_i, rand() % screen_width, -200, 113, 127, 0.6, 0, "Background")); break;
			case 1: entities.push_back(new Object(background_rocksand2_i, rand() % screen_width, -200, 78, 70, 0.6, 0, "Background")); break;
			case 2: entities.push_back(new Object(background_rockgray1_i, rand() % screen_width, -200, 93, 65, 0.6, 0, "Background")); break;
			}
		}

		for (it = entities.begin(); it != entities.end();) {
			Entity *b = *it;
			b->update(time);
			if (b->life == false) {
				it = entities.erase(it);
				delete b;
			}
			else ++it;
		}

		for (it = entities.begin(); it != entities.end(); ++it) {
			window.draw((*it)->sprite);
		}
		window.draw(player.sprite);
		window.display();
	}

	return 0;
}