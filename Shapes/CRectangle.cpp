#include "CRectangle.h"

CRectangle::CRectangle(float pLTX, float pLTY, float pRBX, float pRBY, float thickness, uint32_t outlineColor, uint32_t fillColor)
{
	m_sh.setPosition({ pLTX, pLTY });
	m_sh.setSize({ pRBX - pLTX, pRBY - pLTY });
	m_sh.setOutlineThickness(-thickness);
	m_sh.setOutlineColor(sf::Color{ outlineColor });
	m_sh.setFillColor(sf::Color{ fillColor });
}
void CRectangle::Draw(sf::RenderWindow& window) const
{
	window.draw(m_sh);
}
double CRectangle::GetPerimeter() const
{
	sf::Vector2f size = m_sh.getSize();
	return (size.x + size.y) * 2;
}
double CRectangle::GetArea() const
{
	sf::Vector2f size = m_sh.getSize();
	return size.x * size.y;
}