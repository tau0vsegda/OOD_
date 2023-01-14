#pragma once
#include "Decorator.h"
class CRectangleDecorator : public Decorator
{
public:
	//CRectangle(float pLTX, float pLTY, float pRBX, float pRBY, float thickness, uint32_t outlineColor, uint32_t fillColor);
	CRectangleDecorator(sf::RectangleShape& shape) : Decorator(shape)
	{
		m_size = shape.getSize();
	}
	double GetPerimeter() const override;
	double GetArea() const override;
	void Draw(sf::RenderWindow& window) const override;
private:
	sf::Vector2f m_size;
};

