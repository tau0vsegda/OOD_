#pragma once
#include "Decorator.h"

const double PI = 3.141592654;
class CCircleDecorator : public Decorator
{
public:
	//CCircle(float pCenterX, float pCenterY, float radius, float thickness, uint32_t outlineColor, uint32_t fillColor);
	CCircleDecorator(sf::CircleShape& shape) : Decorator(shape)
	{
		m_r = shape.getRadius();
	}
	~CCircleDecorator();
	double GetPerimeter() const override;
	double GetArea() const override;
private:
	float m_r;
};

