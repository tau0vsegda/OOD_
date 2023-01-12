#pragma once
#include "ShapeFactory.h"
#include <mutex>
class CircleFactory : public ShapeFactory
{
public:
    static CircleFactory* Instance();
    sf::CircleShape& createShape(std::vector<std::string>& args) const override;
protected:
    CircleFactory();
private:
    static CircleFactory* m_instance;
};

