#pragma once
#include "Vector2.hpp"
#include <SFML/Graphics.hpp>

class Ball {
private:
	struct Calc {
		Vector2 v1, v2;
		double m1, m2;
	};
	double r, m;
	Vector2 pos;
	Vector2 vel;
	sf::Color color;
	sf::CircleShape circle;

	Calc calculateCollision1D(Calc c);
	void calculateCollision(Ball& b, const sf::RenderWindow& window);
	void move();
	void move(double deltaTime);
	void checkBorders(const sf::RenderWindow& window);
	bool collidesWith(const Ball ball);
	bool crossedHorizontal(const sf::RenderWindow& window);
	bool crossedVertical(const sf::RenderWindow& window);

public:
	Ball(double r, double m, const Vector2& vel, const Vector2& pos);

	void render(sf::RenderWindow& window);
	void update(double deltaTime, const sf::RenderWindow& window, Ball* balls[]);
};