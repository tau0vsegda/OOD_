#include "CCircle.h"

CCircle::CCircle(float pCenterX, float pCenterY, float radius, float thickness, uint32_t outlineColor, uint32_t fillColor)
{
	m_sh.setRadius(radius);
	m_sh.setPosition({ pCenterX, pCenterY });
	m_sh.setOutlineThickness(-thickness);
	m_sh.setOutlineColor(sf::Color{ outlineColor });
	m_sh.setFillColor(sf::Color{ fillColor });
}
CCircle::~CCircle()
{
}

void CCircle::Draw(sf::RenderWindow& window) const
{
	window.draw(m_sh);
}
double CCircle::GetPerimeter() const
{
	return m_sh.getRadius() * 2 * PI;
}
double CCircle::GetArea() const
{
	return pow(m_sh.getRadius(), 2)* PI;
}
