#pragma once
#include "Decorator.h"
#include <iostream>
class CConvexDecorator : public Decorator
{
public:
	CConvexDecorator(sf::ConvexShape& shape) : Decorator(shape)
	{
		m_p1 = shape.getPoint(0);
		m_p2 = shape.getPoint(1);
		m_p3 = shape.getPoint(2);
	}
	double GetPerimeter() const override;
	double GetArea() const override;
	void Draw(sf::RenderWindow& window) const override;
private:
	sf::Vector2f m_p1;
	sf::Vector2f m_p2;
	sf::Vector2f m_p3;
};

