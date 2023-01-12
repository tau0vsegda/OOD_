#pragma once
#include "Decorator.h"
#include <iostream>
class CConvexDecorator : public Decorator
{
public:
	//CConvex(float pX1, float pY1, float pX2, float pY2, float pX3, float pY3, float thickness, uint32_t outlineColor, uint32_t fillColor);
	CConvexDecorator(sf::ConvexShape& shape) : Decorator(shape)
	{
		m_p1 = shape.getPoint(0);
		m_p2 = shape.getPoint(1);
		m_p3 = shape.getPoint(2);
	}
	double GetPerimeter() const override;
	double GetArea() const override;
private:
	sf::Vector2f m_p1;
	sf::Vector2f m_p2;
	sf::Vector2f m_p3;
};

