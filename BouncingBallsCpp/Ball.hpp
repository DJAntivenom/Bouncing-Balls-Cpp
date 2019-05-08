#pragma once
#include "Vector2.hpp"
#include <SFML/Graphics.hpp>

class Ball {
private:
	double r;
	Vector2 pos;
	Vector2 vel;
	sf::Color col;
public:
	Ball(const Vector2& pos, const Vector2& vel, double r);

	void render(sf::RenderWindow* window);
	void update(double deltaTime);
};