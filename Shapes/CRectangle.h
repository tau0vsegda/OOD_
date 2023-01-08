#pragma once
#include "Decorator.h"
class CRectangle : public Decorator
{
public:
	CRectangle(float pLTX, float pLTY, float pRBX, float pRBY, float thickness, uint32_t outlineColor, uint32_t fillColor);
	~CRectangle();
	double GetPerimeter() const override;
	double GetArea() const override;
private:
	sf::RectangleShape m_sh;
};

