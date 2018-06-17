/*
 * Trabalho Pratico 2 - Computacao Grafica
 * Joao Paulo Reis Alvarenga
 * Manoel Stilpen
*/

#ifndef TP2_CG_POLYGON_HPP
#define TP2_CG_POLYGON_HPP

#include <vector>
#include <tuple>
#include <Utils/Commons.hpp>
#include "Color.hpp"

using namespace commons;

class Polygon {
public:
    Polygon();
    Polygon(int r, int g, int b);
    bool addVertex(int x, int y);
    std::vector<std::pair<int, int>*> getVertices();
    std::pair<int, int> getCenter();

    Color getFillColor();
    void setFillColor(Color color);
    bool isIntersecting(std::pair<int, int>);
    void translateTo(int x, int y, std::pair<int, int> limitX, std::pair<int, int> limitY);
    void rotateTo(int angle, int x, int y);
    ORIENTATION getOrientation();
    double getArea();

private:
    std::vector<std::pair<int, int>*> vertices;
    Color fillColor;

    std::pair<int, int> min;
    std::pair<int, int> max;

    ORIENTATION orientation;

};

#endif //TP2_CG_POLYGON_HPP
