#pragma once
#include "CDecorator.h"
#include "CCircle.h"
#include "CConvex.h"
class CCircleDecorator : public CDecorator
{
public:
	CCircleDecorator(CCircle shape) : CDecorator(shape) {}
	std::string GetInfo() const;

};
class CConvexDecorator : public CDecorator
{
public:
	CConvexDecorator(CConvex shape) : CDecorator(shape) {}
	std::string GetInfo() const;
};
class CRectangleDecorator : public CDecorator
{
public:
	CRectangleDecorator(std::shared_ptr<IShape>& shape) : CDecorator(shape) {}
	std::string GetInfo() const;
};
