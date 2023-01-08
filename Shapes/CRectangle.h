#pragma once
#include "IShape.h"
class CRectangle : public IShape
{
public:
	CRectangle(float pLTX, float pLTY, float pRBX, float pRBY, float thickness, uint32_t outlineColor, uint32_t fillColor);
	~CRectangle();
	void Draw(sf::RenderWindow& window) const override;
	double GetPerimeter() const override;
	double GetArea() const override;
private:
	sf::RectangleShape m_sh;
};

