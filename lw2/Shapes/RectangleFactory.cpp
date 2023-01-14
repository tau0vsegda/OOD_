#pragma once
#include "RectangleFactory.h"
RectangleFactory::RectangleFactory()
{
}
RectangleFactory* RectangleFactory::m_instance = 0;
RectangleFactory* RectangleFactory::Instance() {
    if (m_instance == 0) {
        m_instance = new RectangleFactory();
    }
    return m_instance;
}
sf::RectangleShape& RectangleFactory::createShape(std::vector<std::string>& args) const
{
    sf::Vector2f pLeftTop = { (float)atof(args[0].c_str()), (float)atof(args[1].c_str()) };
    sf::Vector2f pSize = { (float)atof(args[2].c_str()) - pLeftTop.x, (float)atof(args[3].c_str()) - pLeftTop.y };
    auto sh = new sf::RectangleShape();
    sh->setPosition(pLeftTop);
    sh->setSize(pSize);
    sh->setFillColor(sf::Color(0xc4ab16ff));
    sh->setOutlineColor(sf::Color(0x2a1601ff));
    sh->setOutlineThickness(-2);
    return *sh;
}