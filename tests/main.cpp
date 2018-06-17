#include <Domain/Polygon.hpp>
#include <assert.h>
#include <iostream>

/*
 * Trabalho Pratico 2 - Computacao Grafica
 * Joao Paulo Reis Alvarenga
 * Manoel Stilpen
*/

using namespace commons;

int main(int argc, char** argv) {
    Polygon * polygon = new Polygon();
//    polygon->addVertex(0, 0);
//    polygon->addVertex(0, 10);
//    polygon->addVertex(10, 10);
//    polygon->addVertex(10, 0);
//    std::cout << "Area: " << polygon->getArea() << std::endl;
//    std::cout << "Orientation: ";
//    std::cout << polygon->getOrientation();
//    std::cout << std::endl;
//    assert(polygon->getOrientation() == COUNTERCLOCKWISE);
//    assert(polygon->getArea() == 100.0);
    delete polygon;

    polygon = new Polygon();
    polygon->addVertex(0, 0);
    polygon->addVertex(10, 0);
    polygon->addVertex(10, 10);
    polygon->addVertex(0, 10);
    std::cout << "Area: " << polygon->getArea() << std::endl;
    std::cout << "Orientation: ";
    std::cout << polygon->getOrientation();
    std::cout << std::endl;
    assert(polygon->getOrientation() == CLOCKWISE);
    assert(polygon->getArea() == 100.0);
    delete polygon;

    return 0;
}