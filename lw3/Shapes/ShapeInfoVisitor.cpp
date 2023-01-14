#include "ShapeInfoVisitor.h"
#include "CRectangleDecorator.h"
#include "CConvexDecorator.h"
#include "CCircleDecorator.h"

ShapeInfoVisitor::ShapeInfoVisitor(std::ofstream& output)
	:m_outFileStream(output)
{
}
void ShapeInfoVisitor::Visit(CCircleDecorator const& sh)
{
	PrintInfo( CIRCLE, sh);
}
void ShapeInfoVisitor::Visit(CConvexDecorator const& sh)
{
	PrintInfo(TRIANGLE, sh);
}
void ShapeInfoVisitor::Visit(CRectangleDecorator const& sh)
{
	PrintInfo(RECTANGLE, sh);
}
void ShapeInfoVisitor::PrintInfo(std::string shapeType, const Decorator& sh)
{
	ShapeInfoVisitor::m_outFileStream << shapeType << P << sh.GetPerimeter() << S << sh.GetArea() << std::endl;
}