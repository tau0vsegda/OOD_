#include "CConvexDecorator.h"

CConvexDecorator::~CConvexDecorator()
{
}

double CConvexDecorator::GetPerimeter() const
{
	double a = sqrt(pow((m_p1.x - m_p2.x), 2) + pow((m_p1.y - m_p2.y), 2));
	double b = sqrt(pow((m_p2.x - m_p3.x), 2) + pow((m_p2.y - m_p3.y), 2));
	double c = sqrt(pow((m_p1.x - m_p3.x), 2) + pow((m_p1.y - m_p3.y), 2));
	return a + b + c;
}
double CConvexDecorator::GetArea() const
{
	return abs((m_p2.x - m_p1.x) * (m_p3.y - m_p1.y) - (m_p3.x - m_p1.x) * (m_p2.y - m_p1.y)) / 2;
}