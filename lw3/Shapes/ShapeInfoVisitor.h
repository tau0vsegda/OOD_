#pragma once
#include "ShapeVisitor.h"
#include <fstream>
class ShapeInfoVisitor : public ShapeVisitor
{
public:
	ShapeInfoVisitor(std::ofstream& output);
	void Visit(CCircleDecorator& sh) override;
	void Visit(CConvexDecorator& sh) override;
	void Visit(CRectangleDecorator& sh) override;
private:
	void PrintInfo(std::string shapeType, Decorator& sh);
	std::ofstream& m_outFileStream;
};

