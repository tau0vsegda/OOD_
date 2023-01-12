#pragma once
#include "CCircleDecorator.h"
#include "CConvexDecorator.h"
#include "CRectangleDecorator.h"
class ShapeVisitor
{
public:
    virtual void Visit(CCircleDecorator& sh) = 0;
    virtual void Visit(CConvexDecorator& sh) = 0;
    virtual void Visit(CRectangleDecorator& sh) = 0;
};