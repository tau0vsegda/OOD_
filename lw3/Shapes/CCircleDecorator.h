#pragma once
#include "Decorator.h"

const double PI = 3.141592654;
class CCircleDecorator : public Decorator
{
public:
	CCircleDecorator(sf::CircleShape& shape) : Decorator(shape)
	{
		m_r = shape.getRadius();
	}
	double GetPerimeter() const override;
	double GetArea() const override;
	void Draw(sf::RenderWindow& window) const override;
	void Accept(ShapeVisitor& visitor) const override;
private:
	float m_r;
};

