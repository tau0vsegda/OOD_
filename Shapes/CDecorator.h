#pragma once
#include "IShape.h"
class CDecorator : public IShape
{
public:
	CDecorator(IShape shape);
	~CDecorator();
	void Draw(sf::RenderWindow& window) const override;
	IShape m_sh;
};

