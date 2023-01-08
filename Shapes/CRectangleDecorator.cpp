#include "CRectangleDecorator.h"

CRectangleDecorator::~CRectangleDecorator()
{
}

double CRectangleDecorator::GetPerimeter() const
{
	return (m_size.x + m_size.y) * 2;
}
double CRectangleDecorator::GetArea() const
{
	return m_size.x * m_size.y;
}