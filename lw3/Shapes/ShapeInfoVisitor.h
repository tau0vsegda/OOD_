#pragma once
#include <fstream>
#include "Decorator.h"
class ShapeInfoVisitor : public ShapeVisitor
{
public:
	ShapeInfoVisitor(std::ofstream& output);
	void Visit(CCircleDecorator const& sh) override;
	void Visit(CConvexDecorator const& sh) override;
	void Visit(CRectangleDecorator const& sh) override;
private:
	void PrintInfo(std::string shapeType, const Decorator& sh);
	std::ofstream& m_outFileStream;
	const std::string P = " P=";
	const std::string S = " S=";
	const std::string CIRCLE = "CIRCLE:";
	const std::string TRIANGLE = "TRIANGLE:";
	const std::string RECTANGLE = "RECTANGLE:";
};

