#include <SFML/Graphics.hpp>
#include "Player.h"

using namespace sf;

int main()
{
	RenderWindow window(sf::VideoMode(1600, 900), "ScrollShooter", Style::Fullscreen);

	Clock clock;

	Player p("car1.png", 750, 650, 50, 100, 0.5);

	while (window.isOpen())
	{
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			break;
		}

		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			p.dir = 0;
			p.sprite.setRotation(2.5);
		}

		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			p.dir = 1;
			p.sprite.setRotation(-2.5);
		}

		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			p.dir = 2;
		}

		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			p.dir = 3;
		}

		if (!(Keyboard::isKeyPressed(Keyboard::Right)) && !(Keyboard::isKeyPressed(Keyboard::Left))) {
			p.sprite.setRotation(0);
		}

		if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Left)) {
			p.dir = 4;
		}

		if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Right)) {
			p.dir = 5;
		}

		if (Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard::Right)) {
			p.dir = 6;
		}

		if (Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard::Left)) {
			p.dir = 7;
		}

		if (!(Keyboard::isKeyPressed(Keyboard::Right)) && !(Keyboard::isKeyPressed(Keyboard::Left)) && !(Keyboard::isKeyPressed(Keyboard::Up))
			&& !(Keyboard::isKeyPressed(Keyboard::Down))) {
			p.dir = 8;
		}

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;

		p.update(time);

		window.clear();
		window.draw(p.sprite);
		window.display();
	}

	return 0;
}