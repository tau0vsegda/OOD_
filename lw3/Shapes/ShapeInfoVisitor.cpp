#include "ShapeInfoVisitor.h"
ShapeInfoVisitor::ShapeInfoVisitor(std::ofstream& output)
	:m_outFileStream(output)
{
}
void ShapeInfoVisitor::Visit(CCircleDecorator& sh)
{
	PrintInfo("CIRCLE", sh);
}
void ShapeInfoVisitor::Visit(CConvexDecorator& sh)
{
	PrintInfo("TRIANGLE", sh);
}
void ShapeInfoVisitor::Visit(CRectangleDecorator& sh)
{
	PrintInfo("RECTANGLE", sh);
}
void ShapeInfoVisitor::PrintInfo(std::string shapeType, Decorator& sh)
{
	ShapeInfoVisitor::m_outFileStream << shapeType << " P=" << sh.GetPerimeter() << " S=" << sh.GetArea() << std::endl;
}