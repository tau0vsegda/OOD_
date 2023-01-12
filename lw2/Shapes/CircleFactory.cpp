#include "CircleFactory.h"
CircleFactory::CircleFactory()
{
}
CircleFactory* CircleFactory::m_instance = 0;
CircleFactory* CircleFactory::Instance() {
        if (m_instance == 0) {
            m_instance = new CircleFactory;
        }
        return m_instance;
}
sf::CircleShape& CircleFactory::createShape(std::vector<std::string>& args) const
{
    sf::Vector2f pCenter = { (float)atof(args[0].c_str()), (float)atof(args[1].c_str()) };
    auto sh = new sf::CircleShape();
    sh->setPosition(pCenter);
    sh->setRadius((float)atof(args[2].c_str()));
    sh->setFillColor(sf::Color(0x00b060ff));
    sh->setOutlineColor(sf::Color(0x001b10ff));
    sh->setOutlineThickness(-2);
    return *sh;
    
}
