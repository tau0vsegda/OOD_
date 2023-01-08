#include "CConvex.h"

CConvex::CConvex(float pX1, float pY1, float pX2, float pY2, float pX3, float pY3, float thickness, uint32_t outlineColor, uint32_t fillColor)
{
	m_sh.setPosition({ std::min(pX1, std::min(pX2, pX3)), std::min(pY1, std::min(pY2, pY3)) });
	m_sh.setPointCount(3);
	m_sh.setPoint(0, { pX1 - std::min(pX1, std::min(pX2, pX3)), pY1 - std::min(pY1, std::min(pY2, pY3)) });
	m_sh.setPoint(1, { pX2 - std::min(pX1, std::min(pX2, pX3)), pY2 - std::min(pY1, std::min(pY2, pY3)) });
	m_sh.setPoint(2, { pX3 - std::min(pX1, std::min(pX2, pX3)), pY3 - std::min(pY1, std::min(pY2, pY3)) });
	m_sh.setOutlineThickness(-thickness);
	m_sh.setOutlineColor(sf::Color{ outlineColor });
	m_sh.setFillColor(sf::Color{ fillColor });
}
CConvex::~CConvex()
{
}

void CConvex::Draw(sf::RenderWindow& window) const
{
	window.draw(m_sh);
}
double CConvex::GetPerimeter() const
{
	sf::Vector2f p1 = m_sh.getPoint(0);
	sf::Vector2f p2 = m_sh.getPoint(1);
	sf::Vector2f p3 = m_sh.getPoint(2);
	double a = sqrt(pow(abs(p1.x - p2.x), 2) + pow(abs(p1.y - p2.y), 2));
	double b = sqrt(pow(abs(p2.x - p3.x), 2) + pow(abs(p2.y - p3.y), 2));
	double c = sqrt(pow(abs(p1.x - p3.x), 2) + pow(abs(p1.y - p3.y), 2));
	return a + b + c;
}
double CConvex::GetArea() const
{
	sf::Vector2f p1 = m_sh.getPoint(0);
	sf::Vector2f p2 = m_sh.getPoint(1);
	sf::Vector2f p3 = m_sh.getPoint(2);
	return abs((p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y)) / 2;
}