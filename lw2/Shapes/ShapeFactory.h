#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
class ShapeFactory
{
public:
    virtual sf::Shape& createShape(std::vector<std::string>& args) const = 0;
    virtual ~ShapeFactory() {}
};

