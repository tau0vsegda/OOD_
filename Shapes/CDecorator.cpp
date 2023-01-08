#include "CDecorator.h"
CDecorator::CDecorator(std::shared_ptr<IShape>& shape)
	:m_sh(shape)
{
}
void CDecorator::Draw(sf::RenderWindow& window) const
{
	m_sh->Draw(window);
}
