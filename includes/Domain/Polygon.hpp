/*
 * Trabalho Pratico 2 - Computacao Grafica
 * Joao Paulo Reis Alvarenga
 * Manoel Stilpen
*/

#ifndef TP2_CG_POLYGON_HPP
#define TP2_CG_POLYGON_HPP

#include <vector>
#include <tuple>
#include "Color.hpp"


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
    bool isOutlimits(int xmin, int ymin, int xmax, int ymax);
    void translateTo(int x, int y, std::pair<int, int> limitX, std::pair<int, int> limitY);

private:
    std::vector<std::pair<int, int>*> vertices;
    Color fillColor;

    std::pair<int, int> min;
    std::pair<int, int> max;

};

#endif //TP2_CG_POLYGON_HPP
