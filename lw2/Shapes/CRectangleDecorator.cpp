#pragma once
#include "CRectangleDecorator.h"

double CRectangleDecorator::GetPerimeter() const
{
	return (m_size.x + m_size.y) * 2;
}
double CRectangleDecorator::GetArea() const
{
	return m_size.x * m_size.y;
}

void CRectangleDecorator::Draw(sf::RenderWindow& window) const
{
	window.draw(sh);
}