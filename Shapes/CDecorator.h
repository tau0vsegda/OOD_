#pragma once
#include "IShape.h"
class CDecorator : public IShape
{
public:
	CDecorator(std::shared_ptr<IShape>& shape);
	~CDecorator();
	void Draw(sf::RenderWindow& window) const override;
	std::shared_ptr<IShape> m_sh;
};

