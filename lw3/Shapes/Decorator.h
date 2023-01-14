#pragma once
#include <string>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class CCircleDecorator;
class CConvexDecorator;
class CRectangleDecorator;

class ShapeVisitor
{
public:
	virtual void Visit(CCircleDecorator const& sh) = 0;
	virtual void Visit(CConvexDecorator const& sh) = 0;
	virtual void Visit(CRectangleDecorator const& sh) = 0;
};

class Decorator
{
public:
	Decorator(sf::Shape& shape)
		:sh(shape)
	{
	}
	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual void Draw(sf::RenderWindow& window) const = 0;
	virtual void Accept(ShapeVisitor& visitor) const = 0;
protected:
	sf::Shape& sh;
};

/*const double PI = 3.141592654;
class CCircleDecorator : public Decorator
{
public:
	CCircleDecorator(sf::CircleShape& shape) : Decorator(shape)
	{
		m_r = shape.getRadius();
	}
	double GetPerimeter() const override;
	double GetArea() const override;
	void Draw(sf::RenderWindow& window) const override;
	void Accept(ShapeVisitor& visitor) const override;
private:
	float m_r;
};
class CConvexDecorator : public Decorator
{
public:
	CConvexDecorator(sf::ConvexShape& shape) : Decorator(shape)
	{
		m_p1 = shape.getPoint(0);
		m_p2 = shape.getPoint(1);
		m_p3 = shape.getPoint(2);
	}
	double GetPerimeter() const override;
	double GetArea() const override;
	void Draw(sf::RenderWindow& window) const override;
	void Accept(ShapeVisitor& visitor) const override;
private:
	sf::Vector2f m_p1;
	sf::Vector2f m_p2;
	sf::Vector2f m_p3;
};
class CRectangleDecorator : public Decorator
{
public:
	CRectangleDecorator(sf::RectangleShape& shape) : Decorator(shape)
	{
		m_size = shape.getSize();
	}
	double GetPerimeter() const override;
	double GetArea() const override;
	void Draw(sf::RenderWindow& window) const override;
	void Accept(ShapeVisitor& visitor) const override;
private:
	sf::Vector2f m_size;
};*/