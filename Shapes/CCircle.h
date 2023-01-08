#pragma once
#include "IShape.h"

const double PI = 3.141592654;
class CCircle : public IShape
{
public:
	CCircle(float pCenterX, float pCenterY, float radius, float thickness, uint32_t outlineColor, uint32_t fillColor);
	~CCircle();
	void Draw(sf::RenderWindow& window) const override;
	double GetPerimeter() const override;
	double GetArea() const override;
private:
	sf::CircleShape m_sh;
};

