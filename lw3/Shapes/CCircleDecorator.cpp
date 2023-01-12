#include "CCircleDecorator.h"

double CCircleDecorator::GetPerimeter() const
{
	return PI * m_r * 2;
}
double CCircleDecorator::GetArea() const
{
	return pow(m_r, 2) * PI;
}
