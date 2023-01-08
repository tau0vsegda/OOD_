#include "CCircleDecorator.h"

CCircleDecorator::~CCircleDecorator()
{
}

double CCircleDecorator::GetPerimeter() const
{
	return 2 * m_r * PI;
}
double CCircleDecorator::GetArea() const
{
	return pow(m_r, 2) * PI;
}
