#pragma once
#include "Decorator.h"

const double PI = 3.141592654;
class CCircle : public Decorator
{
public:
	//CCircle(float pCenterX, float pCenterY, float radius, float thickness, uint32_t outlineColor, uint32_t fillColor);
	CCircle(sf::CircleShape& shape) : Decorator(shape) {}
	~CCircle();
	double GetPerimeter() const override;
	double GetArea() const override;
/*private:
	sf::CircleShape m_sh;*/
};

