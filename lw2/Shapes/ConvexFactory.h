#pragma once
#include "ShapeFactory.h"
class ConvexFactory : public ShapeFactory
{
public:
    static ConvexFactory* Instance();
    sf::ConvexShape& createShape(std::vector<std::string>& args) const override;
protected:
    ConvexFactory();
private:
    static ConvexFactory* m_instance;
};

