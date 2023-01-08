#include "CCircle.h"

/*CCircle::CCircle(float pCenterX, float pCenterY, float radius, float thickness, uint32_t outlineColor, uint32_t fillColor)
{
}*/
CCircle::~CCircle()
{
}

double CCircle::GetPerimeter() const
{
	return sh.getRadius() * 2 * PI;
}
double CCircle::GetArea() const
{
	return pow(sh.getRadius(), 2)* PI;
}
