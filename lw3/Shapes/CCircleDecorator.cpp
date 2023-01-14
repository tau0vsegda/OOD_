#pragma once
#include "CCircleDecorator.h"

double CCircleDecorator::GetPerimeter() const
{
	return PI * m_r * 2;
}
double CCircleDecorator::GetArea() const
{
	return pow(m_r, 2) * PI;
}
void CCircleDecorator::Draw(sf::RenderWindow& window) const
{
	window.draw(sh);
}
void CCircleDecorator::Accept(ShapeVisitor& visitor) const
{
	visitor.Visit(*this);
}