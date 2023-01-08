#pragma once
#include "Decorator.h"
class CConvex : public Decorator
{
public:
	CConvex(float pX1, float pY1, float pX2, float pY2, float pX3, float pY3, float thickness, uint32_t outlineColor, uint32_t fillColor);
	~CConvex();
	double GetPerimeter() const override;
	double GetArea() const override;
private:
	sf::ConvexShape m_sh;
};

