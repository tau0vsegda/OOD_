#pragma once
#include "CDecorator.h"
class CCircleDecorator : public CDecorator
{
public:
	CCircleDecorator(std::shared_ptr<IShape>& shape) : CDecorator(shape) {}
	std::string GetInfo() const;

};
class CConvexDecorator : public CDecorator
{
public:
	CConvexDecorator(std::shared_ptr<IShape>& shape) : CDecorator(shape) {}
	std::string GetInfo() const;
};
class CRectangleDecorator : public CDecorator
{
public:
	CRectangleDecorator(std::shared_ptr<IShape>& shape) : CDecorator(shape) {}
	std::string GetInfo() const;
};
