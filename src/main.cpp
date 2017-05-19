#include <iostream> 
#include <SFML/Graphics.hpp>
#include "Object.h"

int screen_width = 1600, screen_hight = 900;

using namespace sf;

int main(){
	RenderWindow window(sf::VideoMode(screen_width, screen_hight), "ScrollShooter", Style::Fullscreen);

	Clock clock;

	Object p("chevroletbattle.png", 765, 650, 70, 150, 0.5);

	while (window.isOpen())
	{

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;

		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			if (p.x + p.w < screen_width){
				p.dir = 0;
				p.sprite.setRotation(2.5);
			}
			else {
				p.dir = 8;
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			if (p.x > 0) {
				p.dir = 1;
				p.sprite.setRotation(-2.5);
			}
			else {
				p.dir = 8;
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			if (p.y + p.h < screen_hight) {
				p.dir = 2;
			}
			else {
				p.dir = 8;
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			if (p.y > 0) {
				p.dir = 3;
			}
			else {
				p.dir = 8;
			}
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

		p.movement(time);

		window.clear(Color(214, 145, 48));

		window.draw(p.sprite);
		window.display();
	}

	return 0;
}