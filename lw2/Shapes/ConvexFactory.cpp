#include "ConvexFactory.h"
ConvexFactory::ConvexFactory()
{
}
ConvexFactory* ConvexFactory::m_instance = 0;
ConvexFactory* ConvexFactory::Instance() {
    if (m_instance == 0) {
        m_instance = new ConvexFactory;
    }
    return m_instance;
}
sf::ConvexShape& ConvexFactory::createShape(std::vector<std::string>& args) const
{
    sf::Vector2f p1 = { (float)atof(args[0].c_str()), (float)atof(args[1].c_str()) };
    sf::Vector2f p2 = { (float)atof(args[2].c_str()), (float)atof(args[3].c_str()) };
    sf::Vector2f p3 = { (float)atof(args[4].c_str()), (float)atof(args[5].c_str()) };
    sf::Vector2f position = { 0, 0 };
    auto sh = new sf::ConvexShape();
    sh->setPosition(position);
    sh->setPointCount(3);
    sh->setPoint(0, p1);
    sh->setPoint(1, p2);
    sh->setPoint(2, p3);
    sh->setFillColor(sf::Color(0xc263baff));
    sh->setOutlineColor(sf::Color(0x1d011aff));
    sh->setOutlineThickness(-2);
    return *sh;
}