#pragma once

class Vector2 {
private:
	double x, y;
public:
	Vector2();
	Vector2(double x, double y);
	Vector2(const Vector2& v);

	Vector2 operator+ (const Vector2 v);

	Vector2 operator- (const Vector2 v);

	Vector2 operator* (const double a);

	Vector2 operator/ (const double a);

	double operator* (const Vector2 v);

	void operator+= (const Vector2 v);

	void operator-=  (const Vector2 v);

	void operator*= (const double v);

	void operator/= (const double v);

	double length();

	double getX();

	double getY();

	void setX(double x);

	void setY(double y);

	void normalize();

	Vector2 getNormalized();
};