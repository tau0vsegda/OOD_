#pragma once
#include <string>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Decorator// : sf::Shape
{
public:
	Decorator(sf::Shape& shape);
	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	sf::Shape& sh;
};