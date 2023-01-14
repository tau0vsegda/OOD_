#pragma once
#include "Decorator.h"
class CRectangleDecorator : public Decorator
{
public:
	CRectangleDecorator(sf::RectangleShape& shape) : Decorator(shape)
	{
		m_size = shape.getSize();
	}
	double GetPerimeter() const override;
	double GetArea() const override;
	void Draw(sf::RenderWindow& window) const override;
	void Accept(ShapeVisitor& visitor) const override;
private:
	sf::Vector2f m_size;
};

