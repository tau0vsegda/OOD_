#pragma once
#include "CCircleDecorator.h"
#include "CConvexDecorator.h"
#include "CRectangleDecorator.h"
#include "ShapeInfoVisitor.h"
#include "CircleFactory.h"
#include "ConvexFactory.h"
#include "RectangleFactory.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
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
    CircleFactory* circleF = CircleFactory::Instance();
    ConvexFactory* convexF = ConvexFactory::Instance();
    RectangleFactory* rectangleF = RectangleFactory::Instance();
    ShapeInfoVisitor shInfo(output);
    while (!input.eof() && !input.fail())
    {
        getline(input, inputCommand);
        std::istringstream command(inputCommand);
        getline(command, inputCommand, ' ');
        std::vector<std::string> args = GetArgs(command);
        switch (shapeType[inputCommand]) {
        case 0:
            {
                CCircleDecorator circleD(circleF->createShape(args));
                circleD.Draw(window);
                circleD.Accept(shInfo);
            }
            break; 
        case 1:
            {
                CConvexDecorator convexD(convexF->createShape(args));
                convexD.Draw(window);
                convexD.Accept(shInfo);
            }
            break;
        case 2:
            {
                CRectangleDecorator rectangleD(rectangleF->createShape(args));
                rectangleD.Draw(window);
                rectangleD.Accept(shInfo);
            }
            break;
        default:
            break;
        }
    }
    window.display();
    sf::sleep(sf::seconds(5));
}