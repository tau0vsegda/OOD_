#include "CCircleDecorator.h"
#include "CConvexDecorator.h"
#include "CRectangleDecorator.h"
#include "CircleFactory.h"
#include "ConvexFactory.h"
#include "RectangleFactory.h"
#include "ShapeInfoVisitor.h"
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
                CCircleDecorator CircleD(circleF->createShape(args));
                window.draw(CircleD.sh);
                shInfo.Visit(CircleD);
            }
            break; 
        case 1:
            {
                CConvexDecorator ConvexD(convexF->createShape(args));
                window.draw(ConvexD.sh);

                shInfo.Visit(ConvexD);
            }
            break;
        case 2:
            {
                CRectangleDecorator RectangleD(rectangleF->createShape(args));
                window.draw(RectangleD.sh);
                shInfo.Visit(RectangleD);
            }
            break;
        default:
            break;
        }
    }
    window.display();
    sf::sleep(sf::seconds(5));
}