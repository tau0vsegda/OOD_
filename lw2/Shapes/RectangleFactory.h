#pragma once
#include "ShapeFactory.h"
class RectangleFactory : public ShapeFactory
{
public:
    static RectangleFactory* Instance();
    sf::RectangleShape& createShape(std::vector<std::string>& args) const override;
private:
    RectangleFactory();
    static RectangleFactory* m_instance;
};

