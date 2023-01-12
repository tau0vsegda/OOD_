#include "CCircleDecorator.h"
#include "CConvexDecorator.h"
#include "CRectangleDecorator.h"
#include "ShapeFactory.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>

std::vector<std::string> GetArgs(std::istream& param)
{
    std::string inputData;
    std::vector<std::string> args;
    while (!param.eof())
    {
        getline(param, inputData, ' ');
        args.push_back(inputData);
    }
    return args;
}

sf::CircleShape MakeCircle(std::istream& param)
{
    std::vector<std::string> args = GetArgs(param);
    sf::Vector2f pCenter = { (float)atof(args[0].c_str()), (float)atof(args[1].c_str()) };
    sf::CircleShape sh;
    sh.setPosition(pCenter);
    sh.setRadius((float)atof(args[2].c_str()));
    sh.setFillColor(sf::Color(0x00b060ff));
    sh.setOutlineColor(sf::Color(0x001b10ff));
    sh.setOutlineThickness(-2);
    return sh;
}
sf::ConvexShape MakeTriangle(std::istream& param)
{
    std::vector<std::string> args = GetArgs(param);
    sf::Vector2f p1 = { (float)atof(args[0].c_str()), (float)atof(args[1].c_str()) };
    sf::Vector2f p2 = { (float)atof(args[2].c_str()), (float)atof(args[3].c_str()) };
    sf::Vector2f p3 = { (float)atof(args[4].c_str()), (float)atof(args[5].c_str()) };
    sf::Vector2f position = { 0, 0 };
    sf::ConvexShape sh;
    sh.setPosition(position);
    sh.setPointCount(3);
    sh.setPoint(0, p1);
    sh.setPoint(1, p2);
    sh.setPoint(2, p3);
    sh.setFillColor(sf::Color(0xc263baff));
    sh.setOutlineColor(sf::Color(0x1d011aff));
    sh.setOutlineThickness(-2);
    return sh;
}

sf::RectangleShape MakeRectangle(std::istream& param)
{
    std::vector<std::string> args = GetArgs(param);
    sf::Vector2f pLeftTop = { (float)atof(args[0].c_str()), (float)atof(args[1].c_str()) };
    sf::Vector2f pSize = { (float)atof(args[2].c_str()) - pLeftTop.x, (float)atof(args[3].c_str()) - pLeftTop.y };
    sf::RectangleShape sh;
    sh.setPosition(pLeftTop);
    sh.setSize(pSize);
    sh.setFillColor(sf::Color(0xc4ab16ff));
    sh.setOutlineColor(sf::Color(0x2a1601ff));
    sh.setOutlineThickness(-2);
    return sh;
}

std::map <std::string, int> shapeType = {
    {"CIRCLE", 0},
    {"TRIANGLE", 1},
    {"RECTANGLE", 2},
};

int main(int argc, char* argv[])
{
    std::ifstream input;
    input.open(argv[1]);
    std::ofstream output;
    output.open(argv[2]);
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Figures", sf::Style::Close);
    window.clear(sf::Color(0xffffffff));
    std::string inputCommand;
    
    while (!input.eof() && !input.fail())
    {
        getline(input, inputCommand);
        std::istringstream command(inputCommand);
        getline(command, inputCommand, ' ');

        switch (shapeType[inputCommand]) {
        case 0:
            {
                sf::CircleShape sh = MakeCircle(command);
                window.draw(sh);
                CCircleDecorator CircleD(sh);
                output << "CIRCLE P=" << CircleD.GetPerimeter() << " S=" << CircleD.GetArea() << std::endl;
            }
            break; 
        case 1:
            {
                sf::ConvexShape sh = MakeTriangle(command);
                window.draw(sh);
                CConvexDecorator ConvexD(sh);
                output << "TRIANGLE P=" << ConvexD.GetPerimeter() << " S=" << ConvexD.GetArea() << std::endl;
            }
            break;
        case 2:
            {
                sf::RectangleShape sh = MakeRectangle(command);
                window.draw(sh);
                CRectangleDecorator RectangleD(sh);
                output << "RECTANGLE P=" << RectangleD.GetPerimeter() << " S=" << RectangleD.GetArea() << std::endl;
            }
            break;
        default:
            break;
        }
    }
    window.display();
    sf::sleep(sf::seconds(5));
}