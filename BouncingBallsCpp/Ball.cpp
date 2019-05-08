#include "Ball.hpp"
#include "GlobalVariables.hpp"

Ball::Ball(double r, double m, const Vector2& vel, const Vector2& pos = Vector2()) : pos(pos), vel(vel), r(r), m(m) {
	color = sf::Color(std::rand() % 256, std::rand() % 256, std::rand() % 256);
	circle.setFillColor(color);
	circle.setRadius((float) r);
	circle.setPosition((float)this->pos.getX(), (float)this->pos.getY());
};

void Ball::render(sf::RenderWindow& window) {
	window.draw(circle);
}

void Ball::update(double deltaTime, const sf::RenderWindow& window, Ball* balls[]) {
	move(deltaTime);
	checkBorders(window);

	for (int i = 0; i < ballAmount; i++) {
		if (balls[i] != this && collidesWith(*balls[i])) {
			calculateCollision(*balls[i], window);
		}
	}
}

bool Ball::collidesWith(const Ball b) {
	return r + b.r >= (pos - b.pos).length();
}

void Ball::checkBorders(const sf::RenderWindow& window) {
	if (crossedHorizontal(window)) {
		vel.setX(vel.getX() * -1);
		do
		{
			move();
		} while (crossedHorizontal(window));
	}
	else if (crossedVertical(window)) {
		vel.setY(vel.getY() * -1);
		do
		{
			move();
		} while (crossedVertical(window));
	}
}

bool Ball::crossedHorizontal(const sf::RenderWindow& window) {
	return pos.getX() - r < 0 || pos.getX() + r > window.getSize().x;
}

bool Ball::crossedVertical(const sf::RenderWindow& window) {
	return pos.getY() - r < 0 || pos.getY() + r > window.getSize().y;
}

Ball::Calc Ball::calculateCollision1D(Calc c) {
	Vector2 v1 = (c.v1 * (c.m1 - c.m2) + c.v2 * 2 * c.m2) / (c.m1 + c.m2);
	Vector2 v2 = (c.v2 * (c.m2 - c.m1) + c.v1 * 2 * c.m1) / (c.m1 + c.m2);

	Calc res;
	res.v1 = v1;
	res.v2 = v2;

	return res;
}

void Ball::calculateCollision(Ball& b, const sf::RenderWindow& window) {
	Calc c;
	Vector2 dist = b.pos - pos;
	c.v1 = dist.getNormalized() * (dist * vel / dist.length());
	dist *= -1;
	c.v2 = dist.getNormalized() * (dist * b.vel / dist.length());
	c.m1 = m;
	c.m2 = b.m;

	Calc res = calculateCollision1D(c);
	vel = res.v1 + vel - c.v1;
	b.vel = res.v2 + b.vel - c.v2;

	do
	{
		move();
		b.move();
		checkBorders(window);
		b.checkBorders(window);
	} while (collidesWith(b));
}

void Ball::move(double deltaTime) {
	pos += vel * deltaTime;
	circle.setPosition((float) (pos.getX() - r), (float) (pos.getY() - r));
}

void Ball::move() {
	move(updateInterval);
}