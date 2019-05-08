#include <SFML/Graphics.hpp>
#include "Vector2.hpp"
#include "GlobalVariables.hpp"
#include "Ball.hpp"

Ball* balls[ballAmount];

sf::RenderWindow window;
sf::Clock c;

int main() {
	window.create(sf::VideoMode(width, height), "Bouncing Circles", sf::Style::Titlebar | sf::Style::Close);

	std::srand(1337);

	for (int i = 0; i < ballAmount; i++) {
		balls[i] = new Ball(std::rand() % (maxSize - minSize + 1) + (double)minSize, std::rand() % (maxMass - minMass + 1) + (double)minMass, 
			Vector2(std::rand() % (maxSpeed - minSpeed + 1) + (double)minSpeed, std::rand() % (maxSpeed - minSpeed + 1) + (double)minSpeed),
			Vector2(std::rand() % (width - xOffset * 2 + 1) + (double)xOffset, std::rand() % (height - yOffset * 2 + 1) + (double)yOffset));
	}

	c.restart();
	while (window.isOpen()) {
		sf::Event e;
		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed || e.key.code == sf::Keyboard::Escape) {
				window.close();
			}
		}

		if (c.getElapsedTime() > sf::seconds((float)updateInterval)) {
			double deltaTime = c.restart().asSeconds();
			for (int i = 0; i < ballAmount; i++) {
				balls[i]->update(deltaTime, window, balls);
			}
		}

		window.clear();
		for (int i = 0; i < ballAmount; i++)
		{
			balls[i]->render(window);
		}
		window.display();
	}

	for (int i = 0; i < ballAmount; i++) {
		delete balls[i];
	}

	return 0xb;
}