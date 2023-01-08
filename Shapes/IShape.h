#pragma once
#include <string>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class IShape
{
public:
	virtual ~IShape() {};
	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual void Draw(sf::RenderWindow& window) const = 0;
};