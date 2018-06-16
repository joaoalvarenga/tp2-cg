/*
 * Trabalho Pratico 2 - Computacao Grafica
 * Joao Paulo Reis Alvarenga
 * Manoel Stilpen
*/
#ifndef TP2_CG_MAINAPPLICATION_HPP
#define TP2_CG_MAINAPPLICATION_HPP

#include <Interfaces/Application.hpp>
#include <Utils/Commons.hpp>
#include <Domain/Polygon.hpp>
#include <Domain/ColorPicker.hpp>

using namespace commons;

class MainApplication : public Application {
public:
    MainApplication();

    void run();
    void draw() override;
    void mouseCallback(int button, int state, int x, int y) override ;
    void menuCallback(int option) override ;
    void mouseMoveCallback(int x, int y);

    void createNewPolygon();
    void addVertexToNewPolygon(int x, int y);

private:
    APPLICATION_STATUS status;
    std::vector<Polygon> polygons;

    Polygon * formingPolygon;
    Polygon * selectedPolygon;
    ColorPicker* colorPicker;

    std::pair<int, int> startPosition;
};

#endif //TP2_CG_MAINAPPLICATION_HPP
