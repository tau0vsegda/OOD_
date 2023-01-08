#include "CConcreteDecorator.h"

std::string CCircleDecorator::GetInfo() const
{
	return "Circle: P=" + std::to_string(m_sh->GetPerimeter()) + " S=" + std::to_string(m_sh->GetArea());
}
std::string CConvexDecorator::GetInfo() const
{
	return "Triangle: P=" + std::to_string(m_sh->GetPerimeter()) + " S=" + std::to_string(m_sh->GetArea());
}
std::string CRectangleDecorator::GetInfo() const
{
	return "Rectangle: P=" + std::to_string(m_sh->GetPerimeter()) + " S=" + std::to_string(m_sh->GetArea());
}