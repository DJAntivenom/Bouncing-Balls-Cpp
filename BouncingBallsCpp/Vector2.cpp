#include "Vector2.hpp"
#include <cmath>

Vector2::Vector2() : x(0.0), y(0.0) {};
Vector2::Vector2(double x, double y) :x(x), y(y) {};
Vector2::Vector2(const Vector2& v): x(v.x), y(v.y) {};

Vector2 Vector2::operator+ (const Vector2 v) {
	return Vector2(x + v.x, y + v.y);
}

Vector2 Vector2::operator- (const Vector2 v) {
	return Vector2(x - v.x, y - v.y);
}

Vector2 Vector2::operator* (const double v) {
	return Vector2(x * v, y * v);
}

Vector2 Vector2::operator/ (double v) {
	return Vector2(x / v, y / v);
}

double Vector2::operator* (const Vector2 v) {
	return x * v.x + y * v.y;
}

void Vector2::operator+= (const Vector2 v) {
	x += v.x;
	y += v.y;
}

void Vector2::operator-= (const Vector2 v) {
	x -= v.x;
	y -= v.y;
}

void Vector2::operator*= (double v) {
	x *= v;
	y *= v;
}

void Vector2::operator/= (double v) {
	x /= v;
	y /= v;
}

double Vector2::length() {
	return std::sqrt(x * x + y * y);
}

double Vector2::getX() {
	return x;
}

double Vector2::getY() {
	return y;
}

void Vector2::setX(double x) {
	this->x = x;
}

void Vector2::setY(double y) {
	this->y = y;
}

void Vector2::normalize() {
	*this /= length();
}

Vector2 Vector2::getNormalized() {
	return *this / length();
}